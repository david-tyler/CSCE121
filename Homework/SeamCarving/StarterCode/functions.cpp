#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;
  
  // Create a one dimensional array on the heap of pointers to Pixels 
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];
  
  bool fail = false;
  
  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];
    
    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }
  
  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // delete array of pointers
    return nullptr;
  }
  
  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

// implement for part 1

int* createSeam(int length) {
  int *ary = new int[length];
  for(int i = 0; i < length; i++)
  {
    ary[i] = 0;
  }
  return ary;
}

void deleteSeam(int* seam) {
  delete[] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
  ifstream inFS;
  string P3;
  int file_width;
  int file_height;
  int r;
  int g;
  int b;
  int max;
  int extra_values;

  inFS.open(filename);
  if(!inFS.is_open())
  {
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }

  inFS >> P3;
  inFS >> file_width;
  if(inFS.fail())
  {
    cout << "Error: read non-integer value" << endl;
    return false;
  }
  inFS >> file_height;
  if(inFS.fail())
  {
    cout << "Error: read non-integer value" << endl;
    return false;
  }
  inFS >> max;
  
  if(toupper(P3.at(0)) != 'P' || P3.at(1) != '3')
  {
    cout << "Error: type is " << P3 << " instead of P3" << endl;
    return false;
  }

  if(height != file_height)
  {
    cout << "Error: input height (" << height << ") does not match value in file (" << file_height << ")" << endl;
    return false;
  }
  if(width != file_width)
  {
    cout << "Error: input width (" << width << ") does not match value in file (" << file_width << ")" << endl;
    return false;
  }
  

  for(int row = 0; row < height; row++)
  {
    for(int col = 0; col < width; col++)
    {
      
      inFS >> r;
      if(inFS.fail() && !inFS.eof())
      {
        cout << "Error: read non-integer value" << endl;
        return false;
      }
      if(inFS.fail() && inFS.eof())
      {
        cout << "Error: not enough color values" << endl;
        return false;
      }
      inFS >> g;
      if(inFS.fail() && !inFS.eof())
      {
        cout << "Error: read non-integer value";
        return false;
      }
      if(inFS.fail() && inFS.eof())
      {
        
        cout << "Error: not enough color values" << endl;
        return false;
      }
      inFS >> b;
      if(inFS.fail() && !inFS.eof())
      {
        cout << "Error: read non-integer value";
        return false;
      }
      if(inFS.fail() && inFS.eof())
      {
        
        cout << "Error: not enough color values" << endl;
        return false;
      }

      if(r < 0 || r > 255)
      {
        cout << "Error: invalid color value " << r << endl;
        return false;
      }
      if(g < 0 || g > 255)
      {
        cout << "Error: invalid color value " << g << endl;
        return false;
      }
      if(b < 0 || b > 255)
      {
        cout << "Error: invalid color value " << b << endl;
        return false;
      }
      image[col][row] = {r, g, b};

    }
  }

  while(!inFS.eof() && inFS.good())
  {
    inFS>>extra_values;
    /*if(inFS.fail())
    {
      cout << "Error: read non-integer value" << endl;
      return false;
    }*/
    if(!inFS.fail())
    {
      cout << "Error: too many color values" << endl;
      return false;
    }
  }
  
  inFS.close();

  return true;
}

bool outputImage(string filename, const Pixel*const* image, int width, int height) {
  ofstream outFS;
  outFS.open(filename);

  if(!outFS.is_open())
  {
    cout << "Error: failed to open output file - " << filename << endl;
    return false;
  }

  outFS << "P3" << endl;
  outFS << width << " " << height << endl;
  outFS << 255 << endl;

  for(int row = 0; row < height; row++)
  {
    for(int col = 0; col < width; col++)
    {
      outFS << (image[col][row]).r << " " << (image[col][row]).g << " "  << (image[col][row]).g << " ";
    }
    outFS << endl;
  }


  outFS.close();
  return true;
}

int energy(const Pixel*const* image, int x, int y, int width, int height) {
  int x_2 = 0;
  int y_2 = 0;
  int energy = 0;

  int r_x = 0;
  int g_x = 0;
  int b_x = 0;
  

  int r_y = 0;
  int g_y = 0;
  int b_y = 0;

  
  if(x == 0)
  {
    if(width == 1 )
    {
      r_x = 0;
      g_x = 0;
      b_x = 0;
      x_2 = 0;
    }
    else
    {
      r_x = (image[width - 1][y]).r - (image[x+1][y]).r;
      g_x = (image[width - 1][y]).g - (image[x+1][y]).g;
      b_x = (image[width - 1][y]).b - (image[x+1][y]).b;
      x_2 = pow(r_x, 2) +  pow(g_x, 2) + pow(b_x, 2);
    }
  }
  if(y == 0)
  {
    if(height == 1)
    {
      r_y = 0;
      g_y = 0;
      b_y = 0;
      y_2 = 0;
    }
    else
    {
      r_y = (image[x][height-1]).r - (image[x][y+1]).r;
      g_y = (image[x][height-1]).g - (image[x][y+1]).g;
      b_y = (image[x][height-1]).b - (image[x][y+1]).b;
      y_2 = pow(r_y, 2) +  pow(g_y, 2) + pow(b_y, 2);
    }
    
  }
  if(x == width - 1)
  {
    if(width == 1)
    {
      r_x = 0;
      g_x = 0;
      b_x = 0;
      x_2 = 0;
    }
    else
    {
      r_x = (image[x-1][y]).r - (image[0][y]).r;
      g_x = (image[x-1][y]).g - (image[0][y]).g;
      b_x = (image[x-1][y]).b - (image[0][y]).b;
      x_2 = pow(r_x, 2) +  pow(g_x, 2) + pow(b_x, 2);
    }
  }
  if(y == height - 1)
  {
    if(height == 1)
    {
      r_y = 0;
      g_y = 0;
      b_y = 0;
      y_2 = 0;
    }
    else
    {
      r_y = (image[x][y-1]).r - (image[x][0]).r;
      g_y = (image[x][y-1]).g - (image[x][0]).g;
      b_y = (image[x][y-1]).b - (image[x][0]).b;
      y_2 = pow(r_y, 2) +  pow(g_y, 2) + pow(b_y, 2);
    }
  }
  if(x != 0 && x != width - 1)
  {
    if(width == 1 )
    {
      r_x = 0;
      g_x = 0;
      b_x = 0;
      x_2 = 0;
    }
    else
    {
      r_x = (image[x+1][y]).r - (image[x-1][y]).r;
      g_x = (image[x+1][y]).g - (image[x-1][y]).g;
      b_x = (image[x+1][y]).b - (image[x-1][y]).b;
      x_2 = pow(r_x, 2) +  pow(g_x, 2) + pow(b_x, 2);
    }
  }
  if(y != 0 && y!= height - 1)
  {
    if(height == 1)
    {
      r_y = 0;
      g_y = 0;
      b_y = 0;
      y_2 = 0;
    }
    else
    {
      r_y = (image[x][y+1]).r - (image[x][y-1]).r;
      g_y = (image[x][y+1]).g - (image[x][y-1]).g;
      b_y = (image[x][y+1]).b - (image[x][y-1]).b;
      y_2 = pow(r_y, 2) +  pow(g_y, 2) + pow(b_y, 2);
    }
  }
  energy = x_2 + y_2;
  return energy;
}

// implement for part 2

// uncomment for part 2


int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {

  
  int total_energy = energy(image, start_col, 0, width, height);
  if(width == 1)
  {
    int sp_energy = 0;
    for(int row = 0; row < height; row++)
    {
      for(int col = start_col; col < width; col++)
      {
        sp_energy += energy(image, col, row, width, height);
      }
    }
    for(int i = 0; i < height; i++)
    {
      seam[i] = 0;
    }
    return sp_energy;
  }

  seam[0] = start_col;


  for(int row = 1; row < height; row++)
  {
      if(start_col != 0 && start_col != width-1)
      {
        int left_energy = energy(image, start_col+1, row, width, height);
        int right_energy = energy(image, start_col-1, row, width, height);
        int center_energy = energy(image, start_col, row, width, height);

        if(center_energy <=  left_energy && center_energy <= right_energy)
        {
          total_energy += center_energy;
          seam[row] = start_col;
        }
        else if(left_energy <= right_energy && left_energy < center_energy)
        {
          total_energy += left_energy;
          start_col = start_col + 1;
          seam[row] = start_col;
        }
        else if(right_energy < left_energy && right_energy < center_energy)
        {
          total_energy += right_energy;
          start_col = start_col - 1;
          seam[row] = start_col;
        }
      }
      else if(start_col == 0)
      {
        int left_energy = energy(image, start_col+1, row, width, height);
        int center_energy = energy(image, start_col, row, width, height);

        if(center_energy <=  left_energy)
        {
          total_energy += center_energy;
          seam[row] = start_col;
        }
        if(left_energy < center_energy)
        {
          total_energy += left_energy;
          start_col = start_col + 1;
          seam[row] = start_col;
        }
      }
      else if(start_col == width-1)
      {
        int right_energy = energy(image, start_col-1, row, width, height);
        int center_energy = energy(image, start_col, row, width, height);
      
        if(center_energy <= right_energy)
        {
          total_energy += center_energy;
          seam[row] = start_col;
        }
        else if(right_energy < center_energy)
        {
            total_energy += right_energy;
            start_col = start_col - 1;
            seam[row] = start_col;
        }
      }
      
  }

  return total_energy;
}

/*int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
  return 0;
}*/

int* findMinVerticalSeam(Pixel** image, int width, int height) {

  int* minimal_seam = createSeam(height);
  loadVerticalSeam(image, 0, width, height, minimal_seam);
  int min_energy = loadVerticalSeam(image, 0, width, height, minimal_seam);
  int min_col = 0;
  cout << "WIDTH: " << width << " HEIGHT: " << height << endl;

  for(int col = 1; col < width; col++)
  {
    int* ary = createSeam(height);
    loadVerticalSeam(image, 0, width, height, ary);
    int temp_energy = loadVerticalSeam(image, col, width, height, ary);

    cout << "COL: " << col << " ENERGY: " << temp_energy <<  " MIN_ENERGY: " << min_energy << endl; 

    /*cout << "MIN SEAM" << endl;
    cout << "COLUMN TO REMOVE: ";
    for(int i = 0; i < height; i++)
    {
      cout << minimal_seam[i] << " ";
    }
    cout << endl;*/

    if(temp_energy < min_energy)
    {
      min_energy = temp_energy;
      min_col = col;

      deleteSeam(minimal_seam);
      minimal_seam = createSeam(height);
      loadVerticalSeam(image, min_col, width, height, minimal_seam);
      
    }
    else if(temp_energy == min_energy)
    {
      if(col < min_col)
      {
        min_col = col;
        min_energy = temp_energy;

        deleteSeam(minimal_seam);
        minimal_seam = createSeam(height);
        loadVerticalSeam(image, min_col, width, height, minimal_seam);
      }
    }
    deleteSeam(ary);
  }

  cout << "FINAL MIN SEAM" << endl;
  cout << "COLUMN TO REMOVE: ";
  for(int i = 0 ; i < height; i++)
  {
    cout << minimal_seam[i] << " ";
  }
  cout << endl;


  return minimal_seam;
}

/*int* findMinHorizontalSeam(Pixel** image, int width, int height) {
  return nullptr;
}*/

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {

  int* ary = findMinVerticalSeam(image, width, height);

  for(int row = 0; row < height; row++)
  {
    if(verticalSeam[row] == width - 1 && verticalSeam[row] != 0)
    {
      continue;
    }
    else
    {
      for(int col = verticalSeam[row]; col < width; col++)
      {
        if(col == width -1)
        {
          continue;
        }
        image[col][row] = image[col+1][row];
      }
    }
  }
  deleteSeam(ary);
}


/*void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
}*/

