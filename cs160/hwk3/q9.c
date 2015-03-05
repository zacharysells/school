#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0
#define n 100

int mult[n][n];
int a[n][n];
int b[n][n];

struct v {
  int i; /* row */
  int j; /* column */
};

void print()
{
  int i, e;
  for(i = 0; i < n; ++i)
  {
    for(e = 0; e < n; ++e)
    {
      printf("%d ", mult[i][e]);
    }
    printf("\n");
  }
}

void multiply()
{
  int i, j, k, sum = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      sum = 0;
      for (k = 0; k < n; k++)
      {
        sum = sum + a[i][k] * b[k][j];
      }
      mult[i][j] = sum;
    }
  }

  print();
}

void *runner(void *param)
{
  struct v *data = param;
  int e, sum = 0;

  for(e = 0; e < n; e++){
    sum += a[data->i][e] * b[e][data->j];
  }

  mult[data->i][data->j] = sum;

  free(param);
  pthread_exit(0);
}

void pmult()
{
  pthread_t tid[n][n];       //Thread ID
  int i, j, count = 0;
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      struct v *data = (struct v *) malloc(sizeof(struct v));
      data->i = i;
      data->j = j;
      pthread_create(&tid[i][j],NULL,runner,data);

      count++;
    }
  }

  for(i = 0; i < n; ++i)
  {
    for(j = 0; j < n; ++j)
    {
      pthread_join(tid[i][j], NULL);
    }
  }
  print();
}

int main(int argc, char * argv[])
{
  char buffer [2500];
  FILE * file = fopen(argv[1], "r");

  // First line in input is size of matrix
  fgets(buffer, 2500, file);

  int x = 0, y = 0;
  bool fill_a = true;
  while(fgets(buffer, 2500, file) != NULL)
  {
    if(strcmp(buffer, "---\n") == 0)
    {
      fill_a = false;
      y = 0;
      x = 0;
      continue;
    }
    int i = 0;
    for(i = 0; i < strlen(buffer); ++i)
    {
      if(buffer[i] == ' ')
        continue;

      if(buffer[i] == '\n')
      {
        ++y;
        x = 0;
      }

      else
      {
        if(fill_a)
          a[y][x] = atoi(&buffer[i]);
        else
          b[y][x] = atoi(&buffer[i]);

        ++x;
      }
    }
  }
  if(argc <= 2) multiply();

  else
  {
    pmult();
  }

}
