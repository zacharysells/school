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

pthread_mutex_t accept_mutex;

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

void *thread_work(void *arg)
{
	char server_reply[1000];
	Thread_data data = *(Thread_data *)arg;
	struct stat stat_buf;
	int read_ret;
    
	int read_file = open(data.path, O_RDONLY);
		if(read_file < 0) throw_error("Error opening file");
	fstat(read_file, &stat_buf);
	
	
	while((read_ret = read(read_file, server_reply, 1000)) > 0)
    {
		write(data.new_socket_fd, server_reply, read_ret);
		memset(server_reply, 0, 1000);
	}
		
	if(read_ret < 0)
		throw_error("sendfile returned error");
	
	close(read_file);
	close(data.new_socket_fd);
	
    return NULL;
}


void *accept_requests(void *arg)
{
	int addr_len = sizeof(struct sockaddr_in);
    
    Thread_data data = *(Thread_data *)arg;

	while(true)
	{	
        pthread_mutex_lock(&accept_mutex);
		cerr << "Waiting for new connection..." << endl;
		data.new_socket_fd = accept(data.socket_fd,
						(struct sockaddr *)&data.sock_addr,
						(socklen_t*)&addr_len);
	
		if(data.new_socket_fd < 0)
			throw_error("Failed to accept connection");
	
		pthread_mutex_unlock(&accept_mutex);
		
				
		getFileToCopy(data.new_socket_fd, data.path);
		
        
		thread_work(&data);
        
	}
}

int main()
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0) throw_error("Socket failed");
	
	int true_var = 1;
	setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&true_var,sizeof(int));
    
    struct sockaddr_in sock_addr = build_socket_addr(socket_fd); 
    
    Thread_data thread_args[N_THREADS];
    
	pthread_mutex_init(&accept_mutex, NULL);
    for(int i = 0; i < N_THREADS; ++i)
    {
        Thread_data & data = thread_args[i];
        data.socket_fd = socket_fd;
        data.sock_addr = sock_addr;
        pthread_create(&data.thread_id, NULL, accept_requests, &data);
    }
	
    for(int i = 0; i < N_THREADS; ++i)
    {
        pthread_join(thread_args[i].thread_id, NULL);
    }
    
	close(socket_fd);
}
	
