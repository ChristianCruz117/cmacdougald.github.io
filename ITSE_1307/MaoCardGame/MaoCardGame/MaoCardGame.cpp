// MaoCardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int getFaceValue(int intCard) {
	//Function to get the face value of the card
	return 1 + ((intCard - 1) % 13);
}

int getSuiteValue(int intCard) {
	//Function to geth the suite value of the card
	return (intCard - 1) / 13;
}

string getFaceString(int intCard) {
	//Function to get the face as a string of a card
	int intFace = getFaceValue(intCard);
	string strFace = "";
	switch (intFace) {
		case 1:
			strFace = "Ace";
			break;
		case 11:
			strFace = "Jack";
			break;
		case 12:
			strFace = "Queen";
			break;
		case 13:
			strFace = "King";
			break;
		default:
			strFace += std::to_string(intFace);
	}
	return strFace;
}

string getSuiteString(int intCard) {
	//Returns the suite of the card as a string
	string strSuite = "";
	switch (getSuiteValue(intCard)) {
		case 0:
			strSuite = "Clubs";
			break;
		case 1:
			strSuite = "Diamonds";
			break;
		case 2:
			strSuite = "Hearts";
			break;
		default:
			strSuite = "Spades";
			break;
	}
	return strSuite;
}

string getCardString(int intCard) {
	//Returns the full card as a string
	return getFaceString(intCard) + " of " + getSuiteString(intCard);
}

int pickACard() {
	//Lets the user pick a random number
	int intCard = 0;
	do {
		cout << "Please enter a card number between 1 and 52: ";
		cin >> intCard;
	} while (intCard < 1 || intCard > 52);
	return intCard;
}

int getRandomCard() {
	//Generates a random card number
	return rand() % 52 + 1;
}

int main()
{
	srand(time(0)); //Setup the randomness at the beginning of the program

	int intCard = getRandomCard(); //Generates a card
	cout << getCardString(intCard) << endl; //Displays a card

    return 0;
}

