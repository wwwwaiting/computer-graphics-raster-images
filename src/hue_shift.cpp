#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <cmath>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < width*height; i++){
    // convert to [0, 1]
    double r = rgb[3*i + 0]/255.0;
    double g = rgb[3*i + 1]/255.0;
    double b = rgb[3*i + 2]/255.0;

    double h,s,v;
    rgb_to_hsv(r,g,b,h,s,v);

    h+= shift;
 		// restrict the range to [0, 360]
    while (h < 0){
      h += 360;
    }
  	// in case that h > 360
 		h = fmod(h, 360);

    hsv_to_rgb(h,s,v,r,g,b);

    shifted[3*i + 0] = r * 255.0;
    shifted[3*i + 1] = g * 255.0;
    shifted[3*i + 2] = b * 255.0;
  }
  ////////////////////////////////////////////////////////////////////////////
}
