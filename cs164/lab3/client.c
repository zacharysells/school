#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
 
int main(void)
{
  int sockfd = 0,n = 0;
  char recvBuff[1024];
  char sendBuff[1024];
  struct sockaddr_in serv_addr;
 
  while(1)
  {
  memset(recvBuff, '0' ,sizeof(recvBuff));
  memset(sendBuff, '0', sizeof(sendBuff));
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }
  struct hostent *hen;
  hen = gethostbyname("server.zachary.cs164");
  if(hen==NULL)
  {
	printf("Host not found\n");
	exit(1);
  } 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);
  bcopy((char *)hen->h_addr,(char*)&serv_addr.sin_addr.s_addr, hen->h_length);
  //serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
  	fgets(sendBuff, 1024, stdin);  
 	write(sockfd, sendBuff, strlen(sendBuff));	
  	while((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
        {	
      		recvBuff[n] = 0;
      		if(fputs(recvBuff, stdout) == EOF)
    		{
      			printf("\n Error : Fputs error");
    		}
		memset(recvBuff, '0', sizeof(recvBuff));
      		printf("\n");
    	}
	
  	if( n < 0)
    	{
      		printf("\n Read Error \n");
    	}
	}
	close(sockfd);
	sleep(1); 

  return 0;
}
