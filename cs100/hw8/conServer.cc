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
#include <pthread.h>
#include <sys/sendfile.h>

using namespace std;

#define SERVER_PORT htons(13217)

void throw_error(const string &str)
{
	cerr << str << endl;
	exit(0);
}

void recursive_file_copy(int new_socket_fd, const char * dir)
{
	struct stat stat_buf;
	off_t offset = 0;
	int ofile, rc, bytes_read;
	string full_dir_path = dir;
	char server_reply[1000];
	
	//Directory information
	DIR* directory;
	directory = opendir(dir);
	dirent * inner_dir;
	
	directory = opendir(dir);
	//Go through directory structure and create files
	while(inner_dir = readdir(directory))//<-- file inside 'directory'
	{
		if(inner_dir->d_name[0] == '.' && opendir(inner_dir->d_name) != NULL) continue;
		
		if(opendir((full_dir_path + "/" + inner_dir->d_name).c_str()) != NULL)
		{
			continue;
		}
		else
		{
			//Get file information. Store in stat struct
			ofile = open((full_dir_path + "/" + inner_dir->d_name).c_str(), O_RDONLY);
			if(ofile < 0) throw_error("Failed to open file");
			
			rc = fstat(ofile, &stat_buf);
			if(rc < 0) throw_error("Failed to call fstat()");
			
			rc = write(new_socket_fd, &stat_buf.st_size, sizeof(stat_buf.st_size));
			if(rc < 0) throw_error("Failed to call write");
			
			rc = write(new_socket_fd, &inner_dir->d_name, 1000);
			if(rc < 0) throw_error("Failed to call write");
			
			while (1) 
			{
				// Read data into buffer.  We may not have enough to fill up buffer, so we
				// store how many bytes were actually read in bytes_read.
				bytes_read = read(ofile, server_reply , 1000);
				if (bytes_read == 0) // We're done reading from the file
					break;

				if (bytes_read < 0)
					throw_error("Failed to read from file");

				char *p = server_reply;
				while (bytes_read > 0) 
				{
					int bytes_written = write(new_socket_fd, p, bytes_read);
					if (bytes_written <= 0) {
						// handle errors
					}
					bytes_read -= bytes_written;
					p += bytes_written;
				}
			}
			memset(server_reply, 0, 1000);
			close(ofile);
			//sleep(1);
		}
	}
}

void fork_process(int new_socket_fd, char * dir)
{
	int fork_pid = fork();
	
	switch(fork_pid)
	{
	
		case -1: cerr << "Error forking process" << endl; exit(0);
		
		case 0:
		{
			recursive_file_copy(new_socket_fd, dir);
			shutdown(new_socket_fd, SHUT_RDWR);
			exit(0);
		}
		
		default: return;

	}
}


void await_connection(int socket_fd, struct sockaddr_in sock_addr)
{

	char client_message[1000];
	int addr_len, read_ret, new_socket_fd;
	
	while(true)
	{
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
		
		memset(client_message, 0, sizeof(client_message));
		if(read_ret = read(new_socket_fd, client_message, 1000) < 0)
		{			
			cerr << "Error reading from socket" << endl;
			exit(0);
		}
		fork_process(new_socket_fd, client_message);
	}
		
	shutdown(new_socket_fd, SHUT_RDWR);
}


int main()
{
	int true_var = 1;
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&true_var,sizeof(int));
	
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

