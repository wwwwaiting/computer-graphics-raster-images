#include "hsv_to_rgb.h"
#include <math.h>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  r = 0;
  g = 0;
  b = 0;

  // formulas see reference here: https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB  
  double c = v * s;
  double h_prime = h / 60.0;
  double x = c * (1.0 - fabs(fmod(h_prime, 2.0) - 1.0));

  if (0 <= h_prime && h_prime <= 1){
    r = c;
    g = x;
    b = 0.0;
  } else if (1 < h_prime && h_prime <= 2){
    r = x;
    g = c;
    b = 0.0;
  } else if (2 < h_prime && h_prime <= 3){
    r = 0.0;
    g = c;
    b = x;
  } else if (3 < h_prime && h_prime <= 4){
    r = 0.0;
    g = x;
    b = c;
  } else if (4 < h_prime && h_prime <= 5){
    r = x;
    g = 0.0;
    b = c;
  } else if (5 < h_prime && h_prime <= 6){
    r = c;
    g = 0.0;
    b = x;
  } else {
    r = 0.0;
    g = 0.0;
    b = 0.0;
  }
  
  double m = v-c; 
  r += m;
  g += m;
  b += m;
  ////////////////////////////////////////////////////////////////////////////
}
