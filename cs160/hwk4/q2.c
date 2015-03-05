#include <omp.h>#include <stdio.h>static long num_steps = 100000;double step;void main (){  int i; double x, pi, sum = 0.0;  double start_time = omp_get_wtime();  step = 1.0/(double) num_steps;  #pragma omp parallel num_threads(4) private(i,x)  {    #pragma omp for reduction(+:sum) schedule(static)    for (i=0; i< num_steps; i++)    {      x = (i+0.5)*step;      sum = sum + 4.0/(1.0+x*x);    }  }  pi = step * sum;  printf("pi: %f\n", pi);  printf("elapsed time: %f\n", omp_get_wtime() - start_time);}