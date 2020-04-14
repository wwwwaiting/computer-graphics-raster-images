#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < width*height; i++){
    double r_a = A[4*i + 0];
    double g_a = A[4*i + 1];
    double b_a = A[4*i + 2];
    double a_a = A[4*i + 3]/255.0;

    double r_b = B[4*i + 0];
    double g_b = B[4*i + 1];
    double b_b = B[4*i + 2];
    double a_b = B[4*i + 3]/255.0;

    // use https://en.wikipedia.org/wiki/Alpha_compositing as reference for the transformation
    double c_a = a_a + a_b*(1-a_a);
    double c_r = (r_a*a_a + r_b*a_b*(1-a_a)) / c_a;
    double c_g = (g_a*a_a + g_b*a_b*(1-a_a)) / c_a;
    double c_b = (b_a*a_a + b_b*a_b*(1-a_a)) / c_a;

    C[4*i + 0] = c_r;
    C[4*i + 1] = c_g;
    C[4*i + 2] = c_b;
    C[4*i + 3] = c_a * 255.0;
  }
  ////////////////////////////////////////////////////////////////////////////
}
