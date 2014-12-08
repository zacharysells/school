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
#include <libgen.h>
#include <unistd.h>
#include "timer.h"

using namespace std;

#define SERVER_PORT htons(13217)
#define N_THREADS 10
#define N_FILES 14
char files[N_FILES][255] = 
{
		"/usr/share/dict/words",
		"/etc/wgetrc",
		"/etc/passwd",
		"/etc/wodim.conf",
		"/etc/networks",
		"/etc/nanorc",
		"/etc/mtab",
		"/etc/mtools.conf",
		"/etc/localtime",
		"/etc/magic",
		"/etc/magic.mime",
		"/etc/mailcap",
		"/etc/mailcap.order",
		"/etc/legal"
};

struct Thread_data
{
	int id;
	pthread_t thread_id;
	int sock;
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
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = SERVER_PORT;
	
	return server;
}

void make_dir(Thread_data &data)
{
	char str_id[255];
	sprintf(str_id, "%d", data.id);
	strcat(data.path, str_id);
	mkdir(data.path, 0777);
}

void create_socket(Thread_data &data)
{
	data.sock = socket(AF_INET , SOCK_STREAM , 0);
    if (data.sock < 0)
		throw_error("Failed to create socket");
     
    struct sockaddr_in sock_addr = build_socket_addr(data.sock);
    data.sock_addr = sock_addr;
    
	if (connect(data.sock , (struct sockaddr *)&data.sock_addr, sizeof(data.sock_addr)) < 0)
			throw_error("Connect failed");
			
}

void remoteCopy(Thread_data data, char * path)
{	
	create_socket(data);
	char server_reply[1000];
	int read_ret;
	
	if(write(data.sock, path, 255) < 0)
		throw_error("Writing failed");
	
	strcat(data.path, "/");
    path = strcat(data.path, basename(path));
    
    int outfile = open(path, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    if(outfile < 0) throw_error("Error opening file");
    while((read_ret = read(data.sock, server_reply, 1000)) > 0)
    {
		write(outfile, server_reply, read_ret);
		memset(server_reply, 0, 1000);
	}
	if(read_ret < 0) throw_error("Error writing to file");
	close(outfile);
	close(data.sock);
}

void *thread_work(void *arg)
{
	Thread_data data = *(Thread_data *)arg;
	make_dir(data);
    for(int i = 0; i < N_FILES; ++i)
    {	
		remoteCopy(data, files[i]);
	}
	pthread_exit(0);
}


int main()
{	
	Timer t;
	double eTime;
    Thread_data thread_args[N_THREADS];
    
    t.start();
    for(int i = 0; i < N_THREADS; ++i)
    {
		Thread_data & t = thread_args[i];
		t.id = i;
		strcpy(t.path, "testdir");
		if(pthread_create(&t.thread_id, NULL, thread_work, &t) < 0)
			throw_error("Failed to create thread");
	}
	for (int i=0; i < N_THREADS; i++)
        pthread_join(thread_args[i].thread_id, NULL);
    
    t.elapsedSystemTime(eTime);
    cout << "Time to do " << N_THREADS << " copies: " << eTime << " seconds" << endl << endl;

	pthread_exit(0);

    return 0;
}
