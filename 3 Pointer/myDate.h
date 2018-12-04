#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;

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
	void J2G(int JD, int&a, int&b, int&c);
	int G2J(int j, int k, int i);
	int daysBetween(myDate d);
	int getMonth();
	int getDay();
	int getYear();
	int getDate();
	int dayOfYear();
	string dayName();
	string printDate();
};

#endif