#include <iostream>
#include <string>
#include "./string_calculator.h"


using std::cout, std::endl;
using std::string;

int ASCII[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    bool found = false;
    for(int i = 0; i < 10; i++)
    {
        if(digit == ASCII[i])
        {
            found = true;
            unsigned int index = static_cast<unsigned int>(i);
            return index;
        }  
    }
    if(found == false)
    {
        cout << "digit_to_decimal THROW: " << digit << endl;
        throw std::invalid_argument("Invalid Argument");
    }
        
    return 0;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    bool found = false;
    for(unsigned int i = 0; i < 10; i++)
    {
        if(decimal == i)
        {
            found = true;
            return char(ASCII[i]);
        }
            
    }
    if(found == false)
    {
        cout << "decimal_to_digit THROW: " << decimal << endl;
        throw std::invalid_argument("Invalid Argument");
    }
        
    return '\0';
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    //cout << "String: " << num << endl;
    int count = 0;
    int i = 0;
    if(num.at(i) == '-')
        i = 1;
    for(int x = i; x < static_cast<int>(num.length()); x++)
    {
        if(num.at(x) != '0')
            count++;
    }
    if(count == 0)
        return "0";
    if(num == "")
    {
        return "0";
    }
    while(num.at(i) == '0')
    {
        num.erase(i, 1);
    }
   
    return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
     lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    int left_length = lhs.length();
    int right_length = rhs.length();


    int left_digit;
    int right_digit;
    int sum;
    int carry = 0;


    string result;


    if(rhs.at(0) == '-' || lhs.at(0) == '-')
    {
        rhs.erase(0,1);
        lhs.erase(0,1);
        if(right_length > left_length)
        {
            int temp_length = right_length;
            right_length = left_length;
            left_length = temp_length;

            string hold_string = rhs;
            rhs = lhs;
            lhs = hold_string;
            int j = lhs.length()-1;
            result = lhs.substr(0,left_length-right_length);
            int result_length = result.length();
            for(int i = rhs.length()-1; i >= 0; i--)
            {
                left_digit = digit_to_decimal(lhs.at(j));
                right_digit = digit_to_decimal(rhs.at(i));
                sum = left_digit + right_digit + carry;
                if(sum >= 10)
                {
                    carry = sum/10;
                    sum = sum % 10;
                }
                else if(sum < 10)
                    carry = 0;
                if(i == 0)
                {
                    if(carry > 0)
                    {
                        int temp;
                        temp = digit_to_decimal(result.at(result_length-1)) + carry;
                        if(temp >= 10)
                        {
                        
                            string string_sum(1, decimal_to_digit(sum));
                            result.insert(result_length, string_sum);

    
                            for(int i = result_length-1; i >= 0; i--)
                            {
                                temp = digit_to_decimal(result.at(i)) + carry;
                                carry = temp/10;
                                temp %= 10;

                                string string_temp(1, decimal_to_digit(temp));
                                result.replace(i, 1, string_temp);

                            
                            }
                            string string_ac(1, decimal_to_digit(carry));
                            result.insert(0, string_ac);
                        }
                        else
                        {
                        
                            string string_temp(1, decimal_to_digit(temp));
                            result.replace(result_length-1, 1, string_temp);
                        
                            string string_sum(1, decimal_to_digit(sum));
                            result.insert(result_length, string_sum);
                        }
                        
                    }
                    else 
                    {
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(result_length, string_sum);
                        
                    }
                }
                else
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(result_length, string_sum);
                    
                }
                j--;
            }
        }
        else if(left_length > right_length)
        {
            int j = lhs.length()-1;
            result = lhs.substr(0,left_length-right_length);
            int result_length = result.length();
            for(int i = rhs.length()-1; i >= 0; i--)
            {
                left_digit = digit_to_decimal(lhs.at(j));
                right_digit = digit_to_decimal(rhs.at(i));
                sum = left_digit + right_digit + carry;
                if(sum >= 10)
                {
                    carry = sum/10;
                    sum = sum % 10;
                }
                else if(sum < 10)
                    carry = 0;
                if(i == 0)
                {
                    if(carry > 0)
                    {
                        int temp;
                        temp = digit_to_decimal(result.at(result_length-1)) + carry;
                        if(temp >= 10)
                        {
                        
                            string string_sum(1, decimal_to_digit(sum));
                            result.insert(result_length, string_sum);


                            for(int i = result_length-1; i >= 0; i--)
                            {
                                temp = digit_to_decimal(result.at(i)) + carry;
                                carry = temp/10;
                                temp %= 10;

                                string string_temp(1, decimal_to_digit(temp));
                                result.replace(i, 1, string_temp);

                            
                            }
                            string string_ac(1, decimal_to_digit(carry));
                            result.insert(0, string_ac);
                        }
                        else
                        {
                        
                            string string_temp(1, decimal_to_digit(temp));
                            result.replace(result_length-1, 1, string_temp);
                        
                            string string_sum(1, decimal_to_digit(sum));
                            result.insert(result_length, string_sum);
                        }
                        
                    }
                    else 
                    {
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(result_length, string_sum);
                        
                    }
                }
                else
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(result_length, string_sum);
                    
                }
                j--;
            }
        }
        else if(left_length == right_length)
        {
            for(int i = rhs.length()-1; i >= 0; i--)
            {
                left_digit = digit_to_decimal(lhs.at(i));
                right_digit = digit_to_decimal(rhs.at(i));
                sum = left_digit + right_digit + carry;
                if(sum >= 10)
                {
                    carry = sum/10;
                    sum = sum % 10;
                }
                else if(sum < 10)
                    carry = 0;
                if(i == 0)
                {
                    if(carry > 0)
                    {
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(0, string_sum);

                        string string_carry(1, decimal_to_digit(carry));
                        result.insert(0, string_carry);
                    }
                    else 
                    {
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(0, string_sum);
                    }
                }
                else
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(0, string_sum);
                
                }
            }
        }
        result.insert(0, "-");
    }
    else if(right_length > left_length)
    {
        int temp_length = right_length;
        right_length = left_length;
        left_length = temp_length;

        string hold_string = rhs;
        rhs = lhs;
        lhs = hold_string;
        int j = lhs.length()-1;
        result = lhs.substr(0,left_length-right_length);
        int result_length = result.length();

        for(int i = rhs.length()-1; i >= 0; i--)
        {
            left_digit = digit_to_decimal(lhs.at(j));
            right_digit = digit_to_decimal(rhs.at(i));
            sum = left_digit + right_digit + carry;
            if(sum >= 10)
            {
                carry = sum/10;
                sum = sum % 10;
            }
            else if(sum < 10)
                carry = 0;
            if(i == 0)
            {
                if(carry > 0)
                {
                    int temp;
                    temp = digit_to_decimal(result.at(result_length-1)) + carry;
                    if(temp >= 10)
                    {
                        
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(result_length, string_sum);


                        for(int i = result_length-1; i >= 0; i--)
                        {
                            temp = digit_to_decimal(result.at(i)) + carry;
                            carry = temp/10;
                            temp %= 10;

                            string string_temp(1, decimal_to_digit(temp));
                            result.replace(i, 1, string_temp);

                            
                        }
                        string string_ac(1, decimal_to_digit(carry));
                        result.insert(0, string_ac);
                    }
                    else
                    {
                        
                        string string_temp(1, decimal_to_digit(temp));
                        result.replace(result_length-1, 1, string_temp);
                        
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(result_length, string_sum);
                    }
                    
                }
                else 
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(result_length, string_sum);
                    
                }
            }
            else
            {
                string string_sum(1, decimal_to_digit(sum));
                result.insert(result_length, string_sum);
                
            }
            j--;
        }
       // cout << "New result: " << result << endl;
    }
    else if(left_length > right_length)
    {
        int j = lhs.length()-1;
        result = lhs.substr(0,left_length-right_length);
        //cout << "Orig result: " << result << endl;
        int result_length = result.length();
        for(int i = rhs.length()-1; i >= 0; i--)
        {
            left_digit = digit_to_decimal(lhs.at(j));
            right_digit = digit_to_decimal(rhs.at(i));
            sum = left_digit + right_digit + carry;
            if(sum >= 10)
            {
                carry = sum/10;
                sum = sum % 10;
            }
            else if(sum < 10)
                carry = 0;
            if(i == 0)
            {
                if(carry > 0)
                {
                    int temp;
                    temp = digit_to_decimal(result.at(result_length-1)) + carry;
                    if(temp >= 10)
                    {
                        
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(result_length, string_sum);


                        for(int i = result_length-1; i >= 0; i--)
                        {
                            temp = digit_to_decimal(result.at(i)) + carry;
                            carry = temp/10;
                            temp %= 10;

                            string string_temp(1, decimal_to_digit(temp));
                            result.replace(i, 1, string_temp);

                            
                        }
                        string string_ac(1, decimal_to_digit(carry));
                        result.insert(0, string_ac);
                    }
                    else
                    {
                        
                        string string_temp(1, decimal_to_digit(temp));
                        result.replace(result_length-1, 1, string_temp);
                        
                        string string_sum(1, decimal_to_digit(sum));
                        result.insert(result_length, string_sum);
                    }
                    
                }
                else 
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(result_length, string_sum);
                    
                }
            }
            else
            {
                string string_sum(1, decimal_to_digit(sum));
                result.insert(result_length, string_sum);
                
            }
            j--;
        }
    }
    else if(left_length == right_length)
    {
        result = "";
        carry = 0;
        for(int i = rhs.length()-1; i >= 0; i--)
        {
            left_digit = digit_to_decimal(lhs.at(i));
            right_digit = digit_to_decimal(rhs.at(i));
            sum = left_digit + right_digit + carry;
            if(sum >= 10)
            {
                carry = sum/10;
                sum = sum % 10;
            }
            else if(sum < 10)
                carry = 0;
            if(i == 0)
            {
                if(carry > 0)
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(0, string_sum);

                    string string_carry(1, decimal_to_digit(carry));
                    result.insert(0, string_carry);
                }
                else 
                {
                    string string_sum(1, decimal_to_digit(sum));
                    result.insert(0, string_sum);
                }
            }
            else
            {
                string string_sum(1, decimal_to_digit(sum));
                result.insert(0, string_sum);
                
            }
        }
    }

   
    return trim_leading_zeros(result);
}

string multiply(string lhs, string rhs) {
    //TODO(student): implement
    int product = 0;
	int carry = 0;
    int top = 0;
	int bottom = 0;
	string result = "";
	bool isNeg = false;
	if (rhs.length() < lhs.length())  //make the bigger numebr on top
	{
		swap(lhs,rhs);
	}
	if (lhs.find('-') != string::npos && rhs.find('-') != string::npos) //if both are neg the result is positive
	{
		rhs.erase(0,1);
		lhs.erase(0,1);
	}
	else if (rhs.find('-') != string::npos && lhs.find('-') == string::npos) //right is negative
	{
		rhs.erase(0,1);
		isNeg = true; 
	}
	else if (lhs.find('-') != string::npos && rhs.find('-') == string::npos) // left is negative
	{
		lhs.erase(0,1);
		isNeg = true;
	}
    string sum = "0";
	int counter = 1;
	for (int i = lhs.length() - 1; i >= 0; i--)
	{
		for (int j = rhs.length() - 1; j >= 0; j--)
		{
			top = digit_to_decimal(rhs.at(j));
			bottom = digit_to_decimal(lhs.at(i));
			
			product = top * bottom + carry;
			carry = 0;
			
			if (product >= 10)
			{
				if (j == 0) 
				{  
					int inner_product = product;
					while (inner_product != 0) 
					{
						result += decimal_to_digit(inner_product % 10);
						inner_product /= 10;
					}
				}
				else 
				{
					carry = product / 10;
					result += decimal_to_digit(product % 10);
				}
			}
			else 
			{
				result += decimal_to_digit(product); 
			}
		}
		int j = result.length()-1;
		string reversed_result = "";
		while (j >= 0)
		{
			reversed_result += result.at(j);
			j--;
		}
		sum = add(sum,reversed_result);
		result = "";
		for (int k = 0; k < counter; k++) 
			result += "0";
		counter++;
	}
	if (isNeg) 
	{
		sum.insert(0,"-");
	}
	return sum;
    

    return "";
}

std::string subtract(std::string lhs, std::string rhs)
{
    string negative = "-";
    if(lhs.find('-') == string::npos && rhs.find('-') == string::npos)
    {
        negative += rhs;
        return add(lhs, negative);
    }
    return add(lhs, rhs);
}