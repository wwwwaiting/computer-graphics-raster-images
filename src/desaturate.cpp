#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

#include <iostream>
using namespace std;

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < width * height; i++){
    // convert to [0, 1]
    double r = rgb[3*i + 0]/255.0;
    double g = rgb[3*i + 1]/255.0;
    double b = rgb[3*i + 2]/255.0;

    double h,s,v;
    rgb_to_hsv(r,g,b,h,s,v);

    // transform based on the given factor.
    s *= (1 - factor);

    hsv_to_rgb(h,s,v,r,g,b);

    desaturated[3*i + 0] = r * 255.0;
    desaturated[3*i + 1] = g * 255.0;
    desaturated[3*i + 2] = b * 255.0;
  }
  ////////////////////////////////////////////////////////////////////////////
}
