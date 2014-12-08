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

using namespace std;

#define SERVER_PORT htons(13217)

void await_connection(int socket_fd, struct sockaddr_in sock_addr)
{
	while(true)
	{
		string cmd = "ls -l ";//<--Edit according to command that you wish to run
	
		string formatted_cmd;
		char client_message[2000];
		int addr_len, read_ret, new_socket_fd;
		
		cerr << "Waiting for new connection..." << endl;
		addr_len = sizeof(struct sockaddr_in);
		new_socket_fd = accept(socket_fd,
						(struct sockaddr *)&sock_addr,
						(socklen_t*)&addr_len);
		
		if(new_socket_fd < 0)
		{
			cerr << "Failed to accept connection" << endl;
			exit(0);
		}
		cout << "Client connected at port: " << SERVER_PORT << endl;

		//Client has connected, run command, output to client_socket
		memset(client_message, 0, sizeof(client_message));
		if(read_ret = read(new_socket_fd, client_message, 2000) < 0)
		{			
			cerr << "Error reading from socket" << endl;
			exit(0);
		}
		
		dup2(new_socket_fd, STDOUT_FILENO);
		
		formatted_cmd = cmd + client_message;
		system(formatted_cmd.c_str());
		
		cerr << "Closing connection" << endl;
		close(new_socket_fd);
	}
}


int main()
{
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	//Build sockaddr struct
	struct sockaddr_in sock_addr;
	memset(&sock_addr, 0, sizeof(sock_addr));
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = SERVER_PORT;
	sock_addr.sin_addr.s_addr = INADDR_ANY;
	
	if(socket_fd < 0)
	{
		cerr << "Socket was not created" << endl;
		exit(0);
	}
	
	if(bind(socket_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
	{
		cerr << "Unable to bind" << endl;
		exit(0);
	}
	
	listen(socket_fd, 5);
	
	await_connection(socket_fd, sock_addr);

	close(socket_fd);
}
