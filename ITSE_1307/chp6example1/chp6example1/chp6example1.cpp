// chp6example1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int getNumberinRange(string strMessage, int intMin, int intMax) {
	int intNumberInRange = intMin;
	do {
		cout << strMessage << ": (" << intMin << "-" << intMax << ") ";
		cin >> intNumberInRange;
	} while (intNumberInRange < intMin || intNumberInRange > intMax);
	return intNumberInRange;
}

int getNumberofDice() {
	return getNumberinRange("How many dice would you like to roll", 1, 16);
}

int getNumberofSides() {
	return getNumberinRange("Enter the number of sides", 3, 100);
}

int dieroll(int intSides) {
	return rand() % intSides + 1; //remainder after divide plus 1
}

int dieroll() {
	return dieroll(6);
}

bool runagain() {
	char chrChoice = 'n';
	cout << "Would you like to roll again? (y/n) ";
	cin >> chrChoice;
	if (chrChoice == 'y' || chrChoice == 'Y') {
		return true;
	}
	return false;
}

int main()
{
	srand(time(0));
	//cout << "Calling with parameter 20: " << dieroll(20) << endl;
	//cout << "Calling without parameter: " << dieroll() << endl;
	do {
		int intNumberofSides = getNumberofSides();
		int intNumberofDice = getNumberofDice();
		for (int intDieCounter = 0; intDieCounter < intNumberofDice; intDieCounter++) {
			cout << "Lets roll the die: " << dieroll(intNumberofSides) << endl;
		}
	} while (runagain());

    return 0;
}

