#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::string;


bool is_Triproduct(int n)
{
    for(int i = 1; i <n-3; i++)
    {
        if(n%((i+1)*(i+2)*(i)) == 0)
            return true;
    }
    return false;
}

int main()
{
    if(is_Triproduct(120) == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    if(is_Triproduct(119) == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout << is_Triproduct(1);
}