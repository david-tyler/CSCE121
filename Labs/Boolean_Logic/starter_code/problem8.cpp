#include <iostream>

bool f(bool x, bool y, bool z) {
  // write your code to compute f(x,y,z) here
  bool value = false; // TODO: change this line
  int count = 0;
    if(x==1)
        count++;
    if(y==1)
        count++;
    if(z==1)
        count++;
  if(count == 1 || count == 3)
    value = true;
  else if(count == 2  && x!=1)
    value = true;
  else
    value = false;
  return value;
}