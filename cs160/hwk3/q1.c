#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printHello(void * x)
{
    printf("Hello World!\n");
    return NULL;
}

int main(int argc, char * argv[])
{
  int nthreads = atoi(argv[1]);
  pthread_t tid[nthreads];
  for(int i = 0; i < nthreads; ++i)
  {
    if(pthread_create(&tid[i], NULL, printHello, NULL) < 0)
    {
      printf("Error creating thread\n");
      exit(1);
    }
  }

  for(int i = 0; i < nthreads; ++i)
  {
    pthread_join(tid[i], NULL);
  }

}
