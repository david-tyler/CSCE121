#include <iostream>

using std::cout, std::endl, std::cin;

void decode(char alphabet[], unsigned int nums1[], unsigned int nums2[], unsigned int size)
{
    unsigned int length = 0; // length of the alphabet
    cout << "The decoded message is:" << endl; //Output to make it look better

    if(size == 0)
        throw std::invalid_argument("Invalid argument"); //throwing if there are no values in the nums1 and nums2 arrays
    if(alphabet[0] == '\0')
        throw std::invalid_argument("Invalid argument"); //throwing if there are no letters
    if(size%2 ==0) // if nums1 and nums2 have the same size 
    {
        for(int i = 0; alphabet[i] != '\0'; i++)
        {
            length++; //looping through the alphabet to get its length or size so that we can compare with the nums arrays
        }
        for(unsigned int i = 0; i < size/2; i++)
        {
            if(nums1[i] >= length) //if index in nums1 is bigger than or equal to the length of alphabet wrap around to the front of alphabet
                nums1[i] = nums1[i] - length; //Performs the wrap around by subtracting the length
            cout << alphabet[nums1[i]]; // alternating output 
            if(nums2[i] >= length) // same as described with nums1
                nums2[i] = nums2[i] - length;
            cout << alphabet[nums2[i]]; // alternating output
        }
        cout << endl;//whitespace
    }
    else if(size%2 == 1) // if nums1 is 1 more than the size of nums2 
    {
        for(int i = 0; alphabet[i] != '\0'; i++)
        {
            length++; //looping through the alphabet to get its length or size so that we can compare with the nums arrays
        }
        for(unsigned int i = 0; i < (size/2) + 1; i++)
        {
            if(i < ((size/2) + 1) - 1)// while the index is not at the last index of nums 1 do regular alternating output. 
            //This is because the length of nums1 is bigger than nums2 so the last index of nums1 will cause and index out of range error.
            {
                if(nums1[i] >= length) //if index in nums1 is bigger than the length of alphabet wrap around to the front of alphabet
                    nums1[i] = nums1[i] - length; //Performs the wrap around by subtracting the length
                cout << alphabet[nums1[i]]; // alternating output 
                if(nums2[i] > length) // same as described with nums1
                    nums2[i] = nums2[i] - length;
                cout << alphabet[nums2[i]]; // alternating output
            }
            else //this will be the last index of nums1 and we will output that value
            {
                if(nums1[i] >= length) //if index in nums1 is bigger than the length of alphabet wrap around to the front of alphabet
                    nums1[i] = nums1[i] - length; //Performs the wrap around by subtracting the length
                cout << alphabet[nums1[i]]; // alternating output 
            }
            
        }
        cout << endl;//whitespace
        
    }
}

int main()
{
    char alphabet[] = "i like to be very cautious";
    unsigned int nums1[] = {26, 8, 11, 51};
    unsigned int nums2[] =  {28, 13, 44};
    unsigned int size = 7;
    decode(alphabet, nums1, nums2, size);

    char oalphabet[] = "abcdefghijklmnopqrstuvwxyzabcdefghij";
    unsigned int onums1[] = {43, 11, 56};
    unsigned int onums2[] =  {4, 15, 18};
    unsigned int osize = 6;
    decode(oalphabet, onums1, onums2, osize);

    char ialphabet[] = "abcdefghijklmnopqrstuvwxyz";
    unsigned int inums1[] = {38, 4, 26, 40, 4, 38};
    unsigned int inums2[] =  {4, 19, 19, 13, 41};
    unsigned int isize = 11;
    decode(ialphabet, inums1, inums2, isize);

    char calphabet[] = "i can be very dexterous";
    unsigned int cnums1[] = {37, 9, 4};
    unsigned int cnums2[] =  {15, 20};
    unsigned int csize = 5;
    decode(calphabet, cnums1, cnums2, csize);
    

    return 0;
}