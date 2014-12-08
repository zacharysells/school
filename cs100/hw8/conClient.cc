#include <iostream>
#include <cstring>//For memset()
#include <arpa/inet.h>//For htons()
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <stdlib.h>//For exit()
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

using namespace std;

#define SERVER_PORT htons(13217)

void throw_error(const string &str)
{
	cerr << str << endl;
	exit(0);
}

const char * cmd_args(int argc, char * argv[])
{
	string formatted_args;
	for(int i = 2; i < argc; ++i)
	{
		formatted_args = formatted_args + argv[i];
		formatted_args = formatted_args + " ";
	}
	return formatted_args.c_str();
}


int main(int argc, char * argv[])
{
	if(argc < 3) throw_error("Too few arguments; hostname required and directory name required");
	
	int sock, read_bytes=0, file_size, rc, outfile;
    struct sockaddr_in server;
    char message[1000] , server_reply[50], file_name[1000], directory_name[1000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
		throw_error("Failed to create socket");
	
	//Build sockaddr_in struct
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = SERVER_PORT;
     
     
    //Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
			throw_error("Connect failed");
			
	cout << "Connected" << endl;
     
	memset(message, 0, sizeof(message));
	memset(server_reply, 0, sizeof(server_reply));
    //Send command to server
    if( write(sock , argv[2] , strlen(cmd_args(argc, argv))) < 0)
		throw_error("Write Failed");
	
	//Read files from Server
	while(true)
	{
		memset(file_name, 0, 1000);
		rc = read(sock, &file_size, sizeof(file_size));
		if(rc < 0) throw_error("Failed to read file size");
		if(rc == 0) break;
		
		cout << "File Size: " << file_size << endl;
		
		rc = read(sock, &file_name, 1000);
		if(rc < 0) throw_error("Failed to read file name");
		if(rc == 0) break;
		
		cout << "File Name: " << file_name << endl << endl;
		
		outfile = open(file_name, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
		while(read_bytes < file_size)
		{
			memset(server_reply, 0, 50);
			read_bytes = read_bytes + read(sock , &server_reply , 50);
			
			if(read_bytes < 0)
				throw_error("Read failed");
				
				
			if(read_bytes == 0) 
				break;
			
			cout << server_reply;
			//write(outfile, server_reply, read_bytes);
		}
		close(outfile);
		read_bytes = 0;
		//sleep(1);
	}

    return 0;
}
