/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: student
 */

#include "TemperatureData.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;


TemperatureData::TemperatureData() : id(""), year(0), month(0), temperature(0)
{
} //initialize everything

TemperatureData::TemperatureData(std::string id, int year, int month, double temperature)
{
	this->id = id;
	this->year = year;
	this->month = month;
	this->temperature = temperature;
} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) {
	// Implement this
	
	if(id.compare(b.id) < 0)
		return true;
	if(id.compare(b.id) == 0)
	{
		if(year < b.year)
			return true;
		if(year == b.year)
		{
			if(month < b.month)
				return true;
		}
	}
	
	
	
	return false;

}

