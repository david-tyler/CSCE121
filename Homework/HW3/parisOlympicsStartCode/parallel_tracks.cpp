#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"

using std::string;

using std::cin;




//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data( double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
  //TODO
  // Update function to return the correct boolean values based on the parameters
  
  for(int i = 0; i < 9; i++)
  {
	cin >> timeArray[i] >> countryArray[i] >> numberArray[i] >> lastnameArray[i]; 
  }

  string trimmed = " ";
  string trimmed2 = " ";
  string yo = " ";
  unsigned int x = 0;

  for(int i = 0; i < 9; i++)
  {
	trimmed = trim(countryArray[i]);
	trimmed2 = trim(lastnameArray[i]);
	yo = countryArray[i];

	if(timeArray[i] <= 0)
	{
		
		return false;
		
	}
		
	if(numberArray[i] >= 100 || numberArray[i]<x)
	{
		
		return false;
		
	}
	if(trimmed.length() != 3)
	{
		
		return false;
		
	}
	if(trimmed2.length() <= 1)
	{
		
		return false;
		
	}
	for(unsigned long j = 0; j<yo.length(); j++)
	{
		if(!isupper(yo[j]))	
		{
			
			return false;
		
		}
	}
	int t2 = trimmed2.length();
	for(int j = 0; j<t2; j++)
	{
		if(!isalpha(trimmed2[j]))
		{
			
			return false;
		
		}
	}
	
  }


  return true; // set so it will compile
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
  for(int i = 0; i < 9; i++)
		ary[i] = 0.0;
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	//TODO
	for(int i = 0; i < 9; i++)
		ary[i] = 0;
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	//TODO
	std::string one = "N/A";
	for(int i = 0; i < 9; i++)
		ary[i] = one;
	
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO

	int rank_index = 0;
	unsigned int rank = 1;
	double max = timeArray[0];
	int max_index = 0;

	for(int j = 0; j < 9; j++)
	{
		if(timeArray[j] > max)
		{
			max = timeArray[j];
			max_index = j;
		}
	}
	double temp = max;
	
	for(int i = 0; i < 9; i++)
	{ 

		max = temp;
		for(int j = 0; j < 9; j++)
		{
			if(timeArray[j] < max && rankArray[j] == 0)
			{
				max = timeArray[j];
				rank_index = j;
			}
		}
		if(rank == 9)
		{
			max = temp;
			rank_index = max_index;
			rankArray[rank_index] = rank;
			break;
		}
		else
		{
			rankArray[rank_index] = rank;
			rank++;
		}
		
	}
	
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}