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
#define N_THREADS 400

struct Thread_data
{
	int id;
	pthread_t thread_id;
	int new_socket_fd;
	sockaddr_in sock_addr;
	char path[255];
};

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
	
	cerr << data.path << endl;
	
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
	pthread_exit(0);
}


void accept_requests(int socket_fd, const sockaddr_in &sock_addr)
{
	int i = 0;
	int addr_len = sizeof(struct sockaddr_in);
	Thread_data thread_args[N_THREADS];
	char server_reply[1000];

	while(true)
	{	
		Thread_data & data = thread_args[i];
		
		cerr << "Waiting for new connection..." << endl;
		int new_socket_fd = accept(socket_fd,
						(struct sockaddr *)&sock_addr,
						(socklen_t*)&addr_len);
	
		if(new_socket_fd < 0)
			throw_error("Failed to accept connection");
	
		
		getFileToCopy(new_socket_fd, data.path);
		data.new_socket_fd = new_socket_fd;
		
		pthread_create(&data.thread_id, NULL, thread_work, &data);
		
		++i;
	}
}

int main()
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0) throw_error("Socket failed");
	
	int true_var = 1;
	setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&true_var,sizeof(int));
	
	accept_requests(socket_fd, build_socket_addr(socket_fd));
	
	close(socket_fd);
}
	
