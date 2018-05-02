// MaoCardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"
using namespace std;


void testCard() {
	Card objCard(1);
	cout << "Card Testing" << endl;
	cout << objCard.getValue() << endl
		<< objCard.getFaceValue() << endl
		<< objCard.getFaceString() << endl
		<< objCard.getSuiteValue() << endl
		<< objCard.getSuiteString() << endl
		<< objCard.toString() << endl;
	objCard.setValue(45);
}

void testDeck() {
	Deck objDeck = Deck();
	cout << "Deck Testing" << endl;
	objDeck.printDeck();
	//Get cards until we reach the shuffle point you can also get cards until you reach NULL
	do {
		objDeck.getCard();
		cout << "Percentage: " << objDeck.getPercentOfDeckDealt() << endl;
	}
	while(!objDeck.shouldShuffle());
	if (objDeck.shouldShuffle()) {
		objDeck.shuffle();
	}
	objDeck.printDeck();
}

void testDiscardPile() {
	Deck objDeck = Deck(4);
	objDeck.shuffle();
	DiscardPile objDiscard = DiscardPile();
	objDiscard.addCard(objDeck.getCard());
	cout << objDiscard.getTopCard().toString() << endl;
}

int main()
{
	srand(time(0)); //Setup the randomness at the beginning of the program
	const int INTNUMBEROFDECKS = 3;
	const int INTPLAYERHANDSIZE = 7;
	const int INTMAXPLAYERS = 6;
	int intNumberOfPlayers = 2;

	//testCard();
	//testDeck();
	testDiscardPile();

    return 0;
}

