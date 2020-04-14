#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int size = height*width;
  for (int idx = 0; idx < size; ++idx){
    int r = idx * 3;
    int g = r + 1;
    int b = g + 1;
    gray[idx] = 0.2126*rgb[r] + 0.7152*rgb[g] + 0.0722*rgb[b]; 
  }
  ////////////////////////////////////////////////////////////////////////////
}


