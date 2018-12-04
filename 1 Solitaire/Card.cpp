#include "Card.h"
#include <iostream>
using namespace std;


Card::Card() {
	rank = 0;
	suit = '0';
}
Card::Card(int r, char s) {
	rank = r;
	suit = s;
}

void Card::setCard(int r, char s) {
	rank = r;
	suit = s;
}
int Card::getValue() {
	if (rank < 11)
		return rank;
	if (rank > 10)
		return 10;
	}

void Card::showCard() {
	if (rank == 1)
		cout << 'A' << suit << ",  ";
	if (rank == 11)
		cout << 'J' << suit << ",  ";
	if (rank == 12)
		cout << 'Q' << suit << ",  ";
	if (rank == 13)
		cout << 'K' << suit << ",  ";
	if (rank > 1 && rank < 11)
		cout << rank << suit << ",  ";
}