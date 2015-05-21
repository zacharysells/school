#include <stdio.h>
#include <omp.h>
static long num_steps = 10000000;
double step;
int main()
{
  double x, pi, sum = 0.0;
  double start_time = omp_get_wtime();
  step = 1.0/(double) num_steps;
  int i;
  double temp_sum = 0.0;
  for(i = 0; i < num_steps; i+=1)
  {
    x = (i+0.5)*step;
    sum = sum + 4.0/(1.0 + x*x);
  }
  pi = step * sum;
  printf("pi: %f\n", pi);
  printf("elapsed time: %f\n", omp_get_wtime() - start_time);
}
