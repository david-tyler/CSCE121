#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  INFO_STRUCT(stack);
  INFO(number);

  if(stack.capacity > stack.count)
  {
    stack.numbers[stack.count] = number;
    stack.count+=1;
  }
  else
  {
    int old_capacity = stack.capacity;
    stack.capacity *= 2;

    int* ary = new int[stack.capacity];
    
    for(int i = 0; i<old_capacity; i++)
    {
      ary[i] = stack.numbers[i];
      
    }
   
    ary[stack.count] = number;

    stack.count+=1;
    delete[] stack.numbers;

    stack.numbers = ary;
  }
  
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);
  if(stack.count <= 0)
  {
    return INT32_MAX;
  }
  else
  {
    int popped = stack.numbers[stack.count-1];

    int* ary = new int[stack.capacity];
    stack.count-=1;
    
    for(int i = 0; i<stack.count; i++)
    {
      ary[i] = stack.numbers[i];
      
    }

    
    delete[] stack.numbers;
    stack.numbers = ary;
    return popped;
  }
  return 0;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO (optional): implement peek function for stack
  INFO_STRUCT(stack);
  return stack.numbers[stack.count-1];
}
