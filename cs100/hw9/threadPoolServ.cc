#include <iostream>
#include <cstring>//For memset()
#include <arpa/inet.h>//For htons()
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>//For exit()
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/sendfile.h>
#include <deque>

using namespace std;

#define SERVER_PORT htons(13217)
#define N_THREADS 5



struct Thread_data
{
	int id;
	pthread_t thread_id;
	int socket_fd;
	int new_socket_fd;
	sockaddr_in sock_addr;
	char path[255];
};

Thread_data thread_args[N_THREADS];

pthread_mutex_t queue_mutex;
pthread_mutex_t readfile_mutex;
pthread_mutex_t isEmpty_mutex;
deque<int> thread_queue;


void *thread_wait_line(void *arg);

void throw_error(const string &str)
{
	cerr << str << endl;
	exit(0);
}

sockaddr_in build_socket_addr(int socket_fd)
{
	struct sockaddr_in sock_addr;
	memset(&sock_addr, 0, sizeof(sock_addr));
	
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = SERVER_PORT;
	sock_addr.sin_addr.s_addr = INADDR_ANY;
	
	if(bind(socket_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
		throw_error("Unable to bind");
		
	listen(socket_fd, 20);
	
	return sock_addr;
}

void getFileToCopy(int new_socket_fd, char * path)
{
	read(new_socket_fd, path, 255);
}

void thread_work(Thread_data &data)
{
	char server_reply[1000];
	struct stat stat_buf;
	
	getFileToCopy(data.new_socket_fd, data.path);
	
	int read_ret;
    
    
	int read_file = open(data.path, O_RDONLY);
		if(read_file < 0) throw_error("Error opening file");
	fstat(read_file, &stat_buf);
	
	
	while((read_ret = read(read_file, server_reply, 1000)) > 0)
    {
		pthread_mutex_lock(&readfile_mutex);
		write(data.new_socket_fd, server_reply, read_ret);
		memset(server_reply, 0, 1000);
		pthread_mutex_unlock(&readfile_mutex);
	}
	
	if(read_ret < 0)
		throw_error("sendfile returned error");
	
	close(read_file);
	close(data.new_socket_fd);
    return;
}

void accept_requests(int socket_fd, sockaddr_in sock_addr)
{
	int jobFd;
	int addr_len = sizeof(struct sockaddr_in);
	while(true)
	{	
		cerr << "Waiting for new connection..." << endl;
		int new_socket_fd = accept(socket_fd,
						(struct sockaddr *)&sock_addr,
						(socklen_t*)&addr_len);
	
		if(new_socket_fd < 0)
			throw_error("Failed to accept connection");
		
        
        jobFd = new_socket_fd;
        thread_queue.push_front(jobFd);
        
	}
}

void *thread_wait_line(void *arg)
{
	while(true)
	{
		Thread_data data = *(Thread_data *)arg;
		
		pthread_mutex_lock(&isEmpty_mutex);
		while(thread_queue.empty());
		data.new_socket_fd = thread_queue.back();
		thread_queue.pop_back();
		pthread_mutex_unlock(&isEmpty_mutex);
		
		thread_work(data);
	}
}

int main()
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0) throw_error("Socket failed");
	
	int true_var = 1;
	setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&true_var,sizeof(int));
	
	pthread_mutex_init(&queue_mutex, NULL);
	pthread_mutex_init(&readfile_mutex, NULL);
	pthread_mutex_init(&isEmpty_mutex, NULL);
	
	for(int i = 0; i < N_THREADS; ++i)
	{
		Thread_data & data = thread_args[i];
		pthread_create(&data.thread_id, NULL, thread_wait_line, &data);
	}
	
	accept_requests(socket_fd, build_socket_addr(socket_fd));
	
	for (int i=0; i < N_THREADS; i++)
        pthread_join(thread_args[i].thread_id, NULL);
	
	close(socket_fd);
}
	
