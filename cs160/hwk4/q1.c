#include <stdio.h>
#include <omp.h>
static long num_steps = 100000;
static int num_threads = 4;
double step;
int main()
{
  double x, pi, sum = 0.0;
  double sum_array[num_threads];
  double start_time = omp_get_wtime();
  step = 1.0/(double) num_steps;
  int i;
  #pragma omp parallel num_threads(num_threads) private(x,i)
  {
    double temp_sum = 0.0;
    int id = omp_get_thread_num();
    for(i = id; i < num_steps; i+=num_threads)
    {
      x = (i+0.5)*step;
      temp_sum = temp_sum + 4.0/(1.0 + x*x);
    }
    sum += temp_sum;
  }
  pi = step * sum;
  printf("pi: %f\n", pi);
  printf("elapsed time: %f\n", omp_get_wtime() - start_time);
}
