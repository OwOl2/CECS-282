#ifndef Card_H
#define Card_H

class Card
{
private:
	int rank;
	char suit;
public:
	Card();
	Card(int r, char s);
	void setCard(int r, char s);
	int getValue();
	void showCard();
};

#endif

