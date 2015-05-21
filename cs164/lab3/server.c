#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(void)
{
  int listenfd = 0,connfd = 0;
  
  struct sockaddr_in serv_addr;
 
  char sendBuff[1025];  
  int numrv;  
 
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("socket retrieve success\n");
  
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(sendBuff, '0', sizeof(sendBuff));
      
  serv_addr.sin_family = AF_INET;    
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  serv_addr.sin_port = htons(5000);    
 
  bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
  
  if(listen(listenfd, 10) == -1){
      printf("Failed to listen\n");
      return -1;
  }
     
  int n = 0;
  char recvBuff[1024];
  while(1)
    {
      connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL); // accept awaiting request
      n = read(connfd, recvBuff, sizeof(recvBuff)-1);
	recvBuff[n] = '\0';
	//if(fputs(recvBuff, stdout) == EOF)
	//{
	 // printf("\n Error: Fputs error");
	//}
	//printf("\n");
      printf("recvBuff: %s", recvBuff);      
      if(n < 0)
      {
	printf("\n Read Error \n");
      }
      if(strcmp(recvBuff, "Hi\n") == 0)
      	strcpy(sendBuff, "Hi from server");
      else if(strcmp(recvBuff, "Bye\n") == 0)
	strcpy(sendBuff, "Bye from server"); 
      else
	strcpy(sendBuff, "Unrecognized command");
      write(connfd, sendBuff, strlen(sendBuff));
     
      memset(sendBuff, '0', sizeof(sendBuff));
      memset(recvBuff, '0', sizeof(recvBuff));
      close(connfd);    
      sleep(1);
    }
 
 
  return 0;
}
