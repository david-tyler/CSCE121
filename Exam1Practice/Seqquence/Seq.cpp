#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::string;



int Sequen(int n, int arr[])
{
    int count = 0;
    int index = 0;
    for(int i = index; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(i > 0)
            {
                if(arr[i] == arr[i-1])
                    break;
            }
            if(arr[j] != arr[i])
            {
                count++;
                break;
            }
            
        }
    }
    return count+1;
}


int main()
{
    int n = 11;
    int arr[] = {5, 2, 2, 3, 4, 4, 4, 4, 1, 1, 1};
    cout << Sequen(n, arr) << endl;

    n = 2;
    int arr1[] = {1,2};
    cout << Sequen(n, arr1) << endl;

    n = 4;
    int arr2[] = {1,1,1,1};
    cout << Sequen(n, arr2) << endl;

    n = 7;
    int arr3[] = {1,2,3,4,5,6,7};
    cout << Sequen(n, arr3) << endl;

}