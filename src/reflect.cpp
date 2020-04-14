#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      int ref = num_channels*(col + width*row);
      int orig = num_channels*((width-col) + width*row);
      	
      for(int c = 0; c < num_channels; c++){
        reflected[ref + c] = input[orig + c];     	
      }

    }
  }  
  ////////////////////////////////////////////////////////////////////////////
}
