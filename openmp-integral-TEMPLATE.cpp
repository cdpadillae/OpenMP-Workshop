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
  const int N = 100000000;

  // print result
  //std::cout << "Serial integral: " << integral_serial(XA, XB, N, f) << "\n";
  //std::cout << "Serial openmp  : " << integral_openmp(XA, XB, N, f) << "\n";
  double t1 = omp_get_wtime();
  integral_openmp(XA, XB, N, f);
  double t2 = omp_get_wtime();

#pragma omp parallel
  {
    if(0 == omp_get_thread_num()) {
      std::cout << omp_get_num_threads() << "\t" << t2 - t1 << std::endl;
    }
  }
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
  TODO
}
