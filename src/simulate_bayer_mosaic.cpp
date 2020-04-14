#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // In this assignment, we'll assume the top left pixel is blue, its right neighbor is green and neighbor below is also green, and its kitty-corner neighbor is red.
  for(int row = 0; row < height; row++){
    for(int col = 0; col < width; col++){
      int offset;
      // take blue when even row and even col since the index starting with 0 (should be odd row and col if starting 1)
      if (row % 2 == 0 && col % 2 == 0){
        offset = 2;
      }else if(row % 2 == 1 && col % 2 == 1){ // take red when odd row and odd col since the index starting with 0 (should be even row and col if starting 1)
        offset = 0;
      }else{ //otherwise take green
        offset = 1;
      }
      bayer[row*width+col] = rgb[row*width*3+col*3+offset];
    }
  }  
  ////////////////////////////////////////////////////////////////////////////
}
