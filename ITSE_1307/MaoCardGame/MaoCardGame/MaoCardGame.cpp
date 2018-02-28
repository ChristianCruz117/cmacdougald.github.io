// MaoCardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int intCard = 46;
	int intFace = -1;
	int intSuite = -1;
	string strFace = "";
	string strSuite = "";

	cout << "Please enter a card number between 1 and 52: ";
	cin >> intCard;

	intFace = 1 + ((intCard - 1) % 13);
	intSuite = (intCard - 1) / 13;

	// cerr << intFace << endl;

	if (intFace == 1) {
		strFace = "Ace";
	}
	else if (intFace == 11) {
		strFace = "Jack";
	}
	else if (intFace == 12) {
		strFace = "Queen";
	}
	else if (intFace == 13) {
		strFace = "King";
	}
	else {
		//cerr << strFace << intFace << endl;
		strFace += std::to_string(intFace);
		//cerr << strFace << intFace << endl;
	}

	if (intSuite == 0) {
		strSuite = "Clubs";
	} else if (intSuite == 1) {
		strSuite = "Diamonds";
	} else if (intSuite == 2) {
		strSuite = "Hearts";
	} else {
		strSuite = "Spades";
	}

	cout << strFace << " of " << strSuite << endl;

    return 0;
}

