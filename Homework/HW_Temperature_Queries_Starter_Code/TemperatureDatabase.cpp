#include "TemperatureDatabase.h"

#include <fstream>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream inFS;
	double temperature;
	string id;
	int year;
	int month;
	istringstream ISS;
	string line;

	inFS.open(filename);
	if(!inFS.is_open())
    {
        cout << "Error: Unable to open " << filename << endl;
    }
	while(!inFS.eof())
	{
		double d_month;
		getline(inFS, line);
		
		ISS.clear();
		ISS.str(line);
		ISS >> id;
		ISS >> year;
		ISS >> d_month;
		ISS >> temperature;
		double diff_month = d_month - static_cast<int>(d_month);
		
		if(ISS.fail())
		{
			cout << "Error: Other invalid input" << endl;
		}
		else if(year < 1800 || year > 2022)
		{
			cout << "Error: Invalid year " << year << endl;
		}
		else if(temperature < -50.0 || temperature > 50.0)
		{
			if(temperature == -99.99)
			{
				//missing information
			}
			else
			{
				cout << "Error: Invalid temperature " << temperature << endl;
			}
		}
		else if(diff_month != 0.0)
		{
			//do nothing
		}
		else if(diff_month == 0.0)
		{
			month = static_cast<int>(d_month);
			if(month < 1 || month > 12)
			{
				cout << "Error: Invalid month " << month << endl;
			}
		}
		else if(inFS.good())
		{
			records.insert(id, year, month, temperature);
		}
		
	}

	inFS.close();


}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	
	//  Leave it blank for part 1
	ofstream dataout("sorted." + filename);
}
