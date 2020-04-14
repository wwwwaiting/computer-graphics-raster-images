#include "demosaic.h"
#include <cmath>

// helper funtion for getting the color type based on the index
int checkType(
  const int & row,
  const int & col)
{
	// consistent with the one in simulate_bayer_mosaic
  if (row % 2 == 0 && col % 2 == 0){ // type blue
    return 2;
  }else if(row % 2 == 1 && col % 2 == 1){ // type red
    return 0;
  }else{ // otherwise is type green
    return 1;
  }
}
void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < width*height; i++){
    int col = fmod(i, width);
    int row = (i - col) / width;

    double sum_r, sum_g, sum_b, count_r, count_g, count_b;
    sum_r = sum_g = sum_b = count_r = count_g = count_b = 0;

    // loop through all neighbors for 8 directions
    int neighbor_row, neighbor_col;
	  for (int row_offset = -1; row_offset < 2; row_offset++){
	  	neighbor_row = row + row_offset;    
		  for (int col_offset = -1; col_offset < 2; col_offset++){
		    neighbor_col = col + col_offset;
			  
			  // skip the current pixel
			  if (row_offset == 0 && col_offset == 0){
		 		  continue;			  
			  }
			
		    // check if the index of the neighbor is out of boundry
		    if (neighbor_row >= 0 && neighbor_row < height && neighbor_col >= 0 && neighbor_col < width){
					// check if the type should be r, g, b based on the index
				  int type = checkType(neighbor_row, neighbor_col);
				  if (type == 0){   // type r
				     sum_r += bayer[neighbor_col + width*neighbor_row];
				     count_r += 1;
				  } else if (type == 1){  // type g
				     sum_g += bayer[neighbor_col + width*neighbor_row];
				     count_g += 1;
				  } else if (type == 2){  // type b
				     sum_b += bayer[neighbor_col + width*neighbor_row];
				     count_b += 1;
				  }      		     
		    }
		  }	  
	  }

		// check the type of the current pixel 
    int cur_type = checkType(row, col);
	  if (cur_type == 0){   // current is type r
		 rgb[3*i] = bayer[i];
		 rgb[3*i+1] = sum_g / count_g;
		 rgb[3*i+2] = sum_b / count_b;
	  } else if (cur_type == 1){  // current is type g
		 rgb[3*i] = sum_r /count_r;
		 rgb[3*i+1] = bayer[i];
		 rgb[3*i+2] = sum_b / count_b;
	  } else if (cur_type == 2){  // current is type b
		 rgb[3*i] = sum_r /count_r;
		 rgb[3*i+1] = sum_g / count_g;
		 rgb[3*i+2] = bayer[i];
	  }  

  }
}
