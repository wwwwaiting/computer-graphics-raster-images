#include "rgb_to_hsv.h"
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  // formula rederence see: https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
  double max = std::max(std::max(r,g), b);
  double min = std::min(std::min(r,g), b);
  double diff = max-min;

  if (max == min){
    h = 0.0;
  }else if (max == r){
    h = 60.0*(g-b)/diff;
  }else if (max == g){
    h = 60.0*(2.0+(b-r)/diff);
  }else if(max == b){
    h = 60.0*(4.0+(r-g)/diff);
  }
  while (h < 0.0){
    h += 360.0;
  }
  
  if (max == 0.0){
    s = 0.0;
  } else{
    s = diff/max;
  }

  v = max;
  ////////////////////////////////////////////////////////////////////////////
}
