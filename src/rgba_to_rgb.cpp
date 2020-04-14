#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int size = height*width*4;
  
  for (int idx = 0; idx < size; idx++){
    if (idx % 4 != 3){
      int rgb_idx = idx - (idx / 4);
      rgb[rgb_idx] = rgba[idx];
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
