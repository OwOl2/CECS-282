//Matias Dotta <matias.dotta@student.csulb.edu>
//CECS 282-05
//Prog 1 solitaire
//Due sep/20/2018

#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std;

bool isPrime(int); //tell if a number is prime
void play(Deck); //play solitaire prime

int main()
{
	bool exit = 1;
	int option;
	Deck d1;
	while (exit)
	{
		cout << "\nWelcome to Solitaire Prime!\n1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitarie Prime\n5) exit\n>> ";
		cin >> option;
		
		switch (option)
		{
		case 1:
			d1.refreshDeck();
			break;
		case 2:
			d1.showDeck();
			break;
		case 3:
			d1.shuffle();
			break;
		case 4:
			play(d1);
			break;
		case 5:
			exit = 0;
			break;
		}			
	}
	return 0;
}

void play(Deck d)
{
	Card c1;
	int sum = 0;
	int piles = 0;
	while (d.cardsLeft() > 0)
	{
		c1 = d.deal();
		c1.showCard();
		sum += c1.getValue();
		if (isPrime(sum))
		{
			cout << "Prime: " << sum << "\n";
			sum = 0;
			piles++;
		}
		if (d.cardsLeft() == 0 && sum == 0)
			cout << "\nWiner in " << piles << " piles!\n";
		if (d.cardsLeft() == 0 && sum != 0)
			cout << " Loser\n";
	}
}

bool isPrime(int num)
{
	if ((num % 2) == 0)
		return false;
	if (num == 1)
		return false;
	for (int i = 3; i < num; i = i + 2)
	{
		if ((num%i) == 0)
			return false;
	}
	return true;
}