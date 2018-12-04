#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;

void J2G(int, int&, int&, int&);
int G2J(int, int, int);

class myDate
{
private:
	int date;

public:
	myDate();
	myDate(int m, int d, int y);
	void display();
	void increaseDate(int n);
	void decreaseDate(int n);
	int daysBetween(myDate d);
	int getmonth();
	int getday();
	int getyear();
	int getDate();
	int dayOfYear();
	string dayName();
};
#endif