#include <iostream>
#include <cassert>

using std::cout, std::endl;
 
class Repository {
   int* contributors;
 
 public:
   Repository(int num) : contributors{nullptr} {
      contributors = new int[1]{num};
   }
      
   // TODO: add destructor
   ~Repository()
   {
    delete[] contributors; //delete the array the only variable/pointer with a new
    contributors = nullptr; //set it to nullptr
   }
    
   // TODO: add copy constructor  
   Repository(const Repository& src)
   {
    contributors = new int[1];
    contributors[0] = src.contributors[0];
   }

   // TODO: add copy assignment operator  
   Repository& operator=(const Repository& src)
   {
        if(this != &src)//first check if the two objects are the same if they are just return the original
        {
            delete[] contributors;//similar idea as copy constructor, delete the original and assign its variables to the new object.
            contributors = nullptr;
            contributors = new int[1];
            contributors[0] = src.contributors[0]; //set the value in contributors to that of the source to avoid shallow copies
        }
        return *this;
   }
 
   void add() { ++contributors[0]; }
 
   bool operator==(int rhs) { return contributors[0] == rhs; }
   
};
 
int main() {
   Repository v(23);
   Repository v2(v);
   
   assert(v == 23);
   assert(v2 == 23);
 
   v2.add();
 
   assert(v == 23);
   assert(v2 == 24);
   
   v2 = v;
   
   assert(v == 23);
   assert(v2 == 23);
   
   v2.add();
 
   assert(v == 23);
   assert(v2 == 24);
   
   cout << "So long, and thanks!" << endl;
      
   return 0;
}