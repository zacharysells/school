#include <iostream>
#include <cstring>//For memset()
#include <arpa/inet.h>//For htons()
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>//For exit()
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

using namespace std;

#define SERVER_PORT htons(3490)

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
	cout << SERVER_PORT << endl;
	int sock, rc;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        cerr << "Could not create socket" << endl;
        exit(0);
    }
    cout << "Socket created" << endl;
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = SERVER_PORT;
     
    //Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		cerr << "connect failed. Error";
		exit(0);
	}
		 
	cout << "Connected" << endl;
     
    //keep communicating with server

	memset(message, 0, sizeof(message));
	memset(server_reply, 0, sizeof(server_reply));
    //Send command to server
    if( write(sock , cmd_args(argc, argv) , strlen(cmd_args(argc, argv))) < 0)
    {
	    cout << "write failed" << endl;
	    exit(0);
	}
	 
	//Read reply from server
    while(true)
    {
        rc = read(sock , server_reply , 2000);
        if(rc < 0)
        {
            cout << "read failed" << endl; 
            exit(0) ;
        }
        if(rc == 0) cout << "HIHIHI" << endl;
        cout << server_reply << flush;
    }
    close(sock);

    return 0;
}
