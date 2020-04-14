#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here 
  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      // original: row, col
      int orig = num_channels*(col + width*row);
      // rotated: width-1-col, row
      // Note that the width and height has been switched after rotation, so use height to multiply the new row idx
      int rot = num_channels*(row + height*(width-1-col));

      for(int c = 0; c < num_channels; c++){
        rotated[rot + c] = input[orig + c];     	
      }
    }
  }  
  ////////////////////////////////////////////////////////////////////////////
}
