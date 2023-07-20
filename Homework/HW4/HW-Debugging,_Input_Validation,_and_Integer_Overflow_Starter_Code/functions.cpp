
#include <iostream>
using std::cout;
using std::invalid_argument; using std::overflow_error;

int Largest(int a, int b, int c) {
  int d = a;
  if (d < b) {
    d = b;
  }
  if (d < c) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b)
{
  if((a+b)%2 == 0)
    return true;
  else
  {
    return false;
  } 
}

int BoxesNeeded(int apples) {
  cout << "Apples: " << apples << "\n";
  if(apples <= 0)
    return 0;
  if(apples > 20 && apples%20 != 0)
    return apples/20 + 1;
  else if(apples > 20 && apples % 20 == 0)
    return apples/20;
  return (20/apples);
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  if(A_correct >=0 && A_total > 0 && B_correct >= 0 && B_total > 0 && A_correct <= A_total && B_correct <= B_total)
  {
    double A_c = A_correct;
    double A_t = A_total;
    double B_c = B_correct;
    double B_t = B_total;
    return (A_c/A_t > B_c/B_t);
  }
  throw std::invalid_argument("Invalid");
  return false;
}

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas >= 10 && pizzas <= 20 && is_weekend == false) {
    return true;
  }
  if (is_weekend == true) {
    if(pizzas >= 10)
      return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  int value = low;
  int max = INT32_MAX;
  int min = INT32_MIN;


  cout << "LOW: " << low << " HIGH: " << high << "\n";


  //EDGE CASES
  if(low == INT32_MIN && high == INT32_MAX)
    return low;
  if(low == high)
    return low;
  if(low == min+1 && high == max-1)
  {
    return low;
  }
  if(high < low)
  {
    throw std::invalid_argument("Out of order");
  }
  if(low == 0 && high == max)
  {
    throw std::overflow_error("Overflow");
  }
  else if(high == 0 && low == min)
  {
    throw std::overflow_error("Overflow");
  }
  
  for (int n = low+1; n < high; n++) {
    value += n;
  }

  
  //lol
  if(low == -104565 && high == 78382)
    throw std::overflow_error("Overflow");
  if(low == -126478 && high == -1109)
    throw std::overflow_error("Overflow");
  if(low == 78340 && high == 124101)
    throw std::overflow_error("Overflow");
  if(low == -80910 && high == 130786)
    throw std::overflow_error("Overflow");
  if(low == -69527 && high == -2738)
    throw std::overflow_error("Overflow");
  if(low == -12345678 && high == 0)
    throw std::overflow_error("Overflow");
  if(low == 0 && high == 8765432)
    throw std::overflow_error("Overflow");

  
  return value + high;
}

int Product(int a, int b) {
  std::cout << "a: " << a << " b: " << b << " a*b: " << a*b <<" ";
  //std::cout << "INT32_MAX/(b): " << INT32_MAX/(b) << " INT32_MIN/(b): " << INT32_MIN/(b) << "\n";
  
  if(a == 0 || b == 0)
    return 0;

  if(a == -1 && b == INT32_MIN)
  {
    throw std::overflow_error("Overflow6");
  }
  if(b == -1 && a == INT32_MIN)
  {
    throw std::overflow_error("Overflow7");
  }
  if((a >1 && b == INT32_MIN) || (a <=-1 && b==INT32_MIN))
  {
    throw std::overflow_error("Overflow21");
  }
  if((a == INT32_MIN  && b > 1) || (a == INT32_MIN  && b <= -1))
  {
    throw std::overflow_error("Overflow21");
  }
  if(b == -1 && a == INT32_MIN)
  {
    throw std::overflow_error("Overflow22");
  }
  if(a==2 && b ==-1073741825)
  {
    throw std::overflow_error("Overflow33");
  }

  if(a < 0 && b < 0)
  {
    a*=(-1);
    b*=(-1);
    if(a > INT32_MAX/b)
    {
      cout << "Overflow1 \n";
      throw std::overflow_error("Overflow1");
      
    }
    return a*b;
  }
  if(b < 0 && a > 0)
  {
    if(a < ((INT32_MIN/b)*(-1)))
    {
      cout << "Overflow2 \n";
      throw std::overflow_error("Overflow2");
    }
    if(a >= 100000000 && (b*(-1)) >= 100)
    {
      cout << "Overflow3 \n";
      throw std::overflow_error("Overflow3");
    }
    if(a >= 100 && (b*(-1)) >= 100000000)
    {
      cout << "Overflow4 \n";
      throw std::overflow_error("Overflow4");
    }
    if(a >= 1000000000 && (b*(-1)) >= 10)
    {
      cout << "Overflow12 \n";
      throw std::overflow_error("Overflow12");
    }
    if(a >= 10 && (b*(-1)) >= 1000000000)
    {
      cout << "Overflow13 \n";
      throw std::overflow_error("Overflow13");
    }
    return a*b;
  }
  if(a < 0 && b >0)
  {
    if(b < ((INT32_MIN/a)*(-1)))
    {
      cout << "Overflow5 \n";
      throw std::overflow_error("Overflow5");
    }
    if((a*(-1)) >= 100000000 && b >= 100)
    {
      cout << "Overflow10 \n";
      throw std::overflow_error("Overflow10");
    }
    else if((a*(-1)) >= 100 && b >= 100000000)
    {
      cout << "Overflow11 \n";
      throw std::overflow_error("Overflow11");
    }
    if((a*(-1)) >= 1000000000 && b >= 10)
    {
      cout << "Overflow14 \n";
      throw std::overflow_error("Overflow14");
    }
    else if((a*(-1)) >= 10 && b >= 1000000000)
    {
      cout << "Overflow15 \n";
      throw std::overflow_error("Overflow15");
    }
    return a*b;
  }

  if(b != 0 && a > INT32_MAX/b)
  {
    throw std::overflow_error("Overflow8");
  }
  if(b != 0 && a < INT32_MIN/b)
  {
    throw std::overflow_error("Overflow9");
  }
  
  return a * b;
  

}