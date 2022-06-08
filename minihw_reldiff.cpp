// AUTHORS: CINDY PADILLA, DANIELA DAZA
#include <iostream>
#include <omp.h>

using fptr = double(double);

double f(double x);
double integral_serial(double a, double b, int N, fptr f);
double integral_openmp(double a, double b, int N, fptr f);

int main(void)
{
  // declare vars
  const double XA = 0.0; 
  const double XB = 10.0; 
  const int w_per_thread = 12000;
  int nth = 0;
  int N = w_per_thread;
  const double exact = 1000.0/3.0;
  
  #pragma omp parallel
  {
    if(0 == omp_get_thread_num()) {
      nth = omp_get_num_threads();
      //std::cout << nth << "\t" << t2 - t1 << std::endl;
    }
  }
  N = nth*w_per_thread;
  
  // print result
  double s_int = integral_serial(XA, XB, w_per_thread, f);
  double p_int = integral_openmp(XA, XB, N, f);
  double t1 = omp_get_wtime();
  integral_openmp(XA, XB, N, f);
  double t2 = omp_get_wtime();
  std::cout << nth << '\t' << N << '\t' << t2-t1 << '\t' << s_int << '\t' << p_int << '\t' << exact << '\t' << 1 - p_int/exact << std::endl;
}

double f(double x)
{
  return x*x;
}

double integral_serial(double a, double b, int N, fptr f)
{
  const double dx = (b-a)/N; 
  // compute integral
  double sum = 0, x;
  for(int ii = 0; ii < N; ++ii) {
    x = a + ii*dx;
    sum += dx*f(x);

    
  }

  return sum;
}

double integral_openmp(double a, double b, int N, fptr f)
{
  const double dx = (b-a)/N; 
  // compute integral
  double sum = 0, x;
#pragma omp parallel for private(x) reduction(+:sum)
  for(int ii = 0; ii < N; ++ii) {
    x = a + ii*dx;
    sum += dx*f(x);
  }
  return sum;
  
}
