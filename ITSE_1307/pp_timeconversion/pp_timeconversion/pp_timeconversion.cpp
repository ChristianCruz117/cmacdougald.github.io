// pp_timeconversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int getTotalMinutes(int intHours, int intMinutes) {
	return (intHours * 60) + intMinutes;
}

int getHours(int intTotalMinutes) {
	return intTotalMinutes / 60;
}

int getMinutes(int intTotalMinutes) {
	return intTotalMinutes % 60;
}

int getIntInput(string strMessage, int intMin, int intMax) {
	int intNumber = 0;
	//TODO: Display message
	//TODO: Logic here to loop until it is within the min and max.
	return intNumber;
}

void printTime(int intTotalMinutes, int intFormat12Or24) {
	if (intFormat12Or24 == 12) {
		int intHours = getHours(intTotalMinutes);
		if (intHours == 0) {
			intHours = 12;
		}
		else if (intHours >= 13) {
			intHours -= 12;
		}

		cout << setw(2) << intHours
			<< ":"
			<< setw(2) << setfill('0') << getMinutes(intTotalMinutes) 
			<< (getHours(intTotalMinutes) >= 12 ? " PM" : " AM")
			<< endl;
	}
	else {
		cout << setw(2) << setfill('0') << getHours(intTotalMinutes) 
			<< ":" 
			<< setw(2) << setfill('0') << getMinutes(intTotalMinutes) << endl;
	}
}

int main()
{
	int intTotalMinutes = 0;
	printTime(3, 24);
	printTime(3, 12);
	printTime(1237, 12);
	printTime(721, 12);
	printTime(535, 12);
	printTime(1397, 12);
    return 0;
}

