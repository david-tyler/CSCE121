#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if((a >= 10 && a <= b) && (b >= a && b < 10000))
	{
		return true;
	}
	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

	int countDigits = 0; //check whether there is an even or odd number of digits to correspond with the pattern
	int temp = number; //temp holder so I don't change the original number and to help with calculaions
	int comparisonsM = 0; //number of mountain comparisons
	int comparisonsV = 0; //number of valley comparisons
	int lastdigit; //the last digit of the number before and after each division by 10
	int temp1 = number; //same uses as the other temp holder

	while(temp != 0) //count number of digits for the number
	{
		countDigits +=1;
		temp/=10;
	}

	int origcount = countDigits; //place holder for countDigits since I changed countDigits below when I needed the original value later

	while(temp1!=0 && countDigits > 1)
	{
		lastdigit=temp1%10; //getting the last digit
		temp1/=10; //incrementing number so we get rid of the last digit and can use the updated last digit for comparisons with the previous
		if(lastdigit == temp1%10)
			return 'N';
		else if(countDigits%2 == 0) //following the pattern if there is an even number of digits
		{
			if(lastdigit>temp1%10)
			{
				comparisonsM++;
			}
			else if(lastdigit<temp1%10)
			{
				comparisonsV++;
			}
		}
		else if(countDigits%2 == 1) //following the pattern if there is an odd number of digits
		{
			if(lastdigit<temp1%10)
			{
				comparisonsM++;	
			}
			else if(lastdigit>temp1%10)
			{
				comparisonsV++;	
			}
		}
		countDigits--; //changing countDigits to match with my comparisons 
	}
	if(comparisonsM == origcount-1) //following the pattern the number of comparisons = numberOfDigits - 1 for the patterns. Whichever pattern has the value is the pattern
		return 'M';
	else if(comparisonsV == origcount - 1)
		return 'V';
	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int countV = 0;
	int countM = 0;
	for(int i = a; i<= b; i++)
	{
		if(classify_mv_range_type(i) == 'M')
			countM++;
		else if(classify_mv_range_type(i) == 'V')
			countV++;
	}
	cout << "There are " << countM << " mountain ranges and " << countV << " valley ranges between " << a << " and " << b << "." << endl;
}