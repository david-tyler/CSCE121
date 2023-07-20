#include <iostream>


using std::cout, std::endl, std::cin;







int main()
{
    int n; //integer n to be read from standard input
    cout << "Input an integer: ";
    cin >> n; //reading the integer to n
    

    int temp = n; //temporary variable may be needed when modifying n, used for output
    int digit; // each digit to be compared
    int rating = 0; // final rating to be output
    int location = 1; //position of each number

    if(n > 0) //if n is a positive integer
    {
        while(n>0) //while loop to keep doing comparisons while slicing n until it is 0 due to the rules of integer division
        {
            digit = n%10; //digit is the right most digit of n each time
            n /= 10; //slicing n, getting rid of the rightmost digit as we compare
            if(digit%location == 0) //comparing the rightmost digit if its divisible by its location
            {
                rating++; //if it is divible increment the rating by 1
            }
            location ++; //increment the location of each digit as we loop through the n
        }
    }
    else if(n < 0) // if n is a negative integer
    {
        //following the same method as if n is postive
        while(n<0) //but change to less than 0 since we are dealing with negative integers
        {
            digit = n%10;
            n /= 10;
            if(digit%location != 0)
            {
                rating++;
            }
            location ++;
        }
        rating *= (-1); // make it negative following the problem rules
    }

    cout << "n = "<< temp <<  ", rating is: " << rating << endl; // output


    return 0;
}