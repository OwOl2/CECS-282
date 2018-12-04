#include "Card.h"
#ifndef Deck_H
#define Deck_H


class Deck
{
private:
	Card Cards [52];
	int top;
public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int cardsLeft();
	void showDeck();

};

#endif