#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;


Deck::Deck()
{
}

void Deck::refreshDeck()
{
	top = 0;
	int n = 0;
	char suit;
	for (int j = 0; j <= 3; j++)
	{
		if (n < 12)
			suit = 'S';
		if (11 < n && n < 25)
			suit = 'H';
		if (24 < n && n < 38)
			suit = 'D';
		if (37 < n && n < 51)
			suit = 'C';
		for (int i = 1; i <= 13; i++)
		{
			Cards[n].setCard(i, suit);
			n++;
		}
	}
}

Card Deck::deal()
{
	Card c = Cards[top];
	top++;
	return c;
}

void Deck::shuffle()
{
	Card c1, c2;
	int r, q;
	srand(time(0));
	for (int i = 0; i < 40; i++)
	{
		r = rand() % 52;
		q = rand() % 52;
		c1 = Cards[r];
		c2 = Cards[q];
		Cards[r] = c2;
		Cards[q] = c1;
	}
}

int Deck::cardsLeft()
{
	int left = 52 - top;
	return left;
}

void Deck::showDeck()
{
	int x = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Cards[j+x].showCard();
		}
		cout << "\n";
		x = 13*i;
	}
}