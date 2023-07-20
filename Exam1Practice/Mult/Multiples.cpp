#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::string;




void display_Multiples(int n, int k, int l)
{
    int count = 0;
    int duplicate = 0;
    if(k > l)
    {
        int temp = k;
        k = l;
        l = temp;
    }
    if(n%2 == 0)
    {
        for(int i = 1; i <= n; i ++)
    {
        //cout << "I: " << i << endl;
        if(count >= n)
            break;

        if(i == l)
        {
            cout << k*(i+1) << " ";
            count++;
            cout << l*i << " ";
            count++;
        }
        else
        {
            cout << k * i << " ";
            count++;
            cout << l*i << " ";
            count++;
        }
        
    }
    }
    else if(n%2 == 1)
    {
        for(int i = 1; i <= n; i ++)
    {
        //cout << "I: " << i << endl;
        if(count >= n)
            break;

        if(i == l)
        {
            cout << k*(i+1) << " ";
            count++;
            cout << l*i << " ";
            count++;
            duplicate++;
        }
        else
        {
            if(count == n-1 && duplicate >=1)
            {
                cout << l*i << " ";
                break;
            }
            else if(count == n-1 && duplicate ==0)
            {
                cout << k*i << " ";
                break;
            }
            cout << k * i << " ";
            count++;
            cout << l*i << " ";
            count++;
        }
    }
    }
    cout << endl;
}

int main()
{
    display_Multiples(6, 2, 3);
    display_Multiples(6, 5, 4);
    display_Multiples(6, 3, 2);
    display_Multiples(7, 3, 2);
    display_Multiples(7, 5, 4);
}