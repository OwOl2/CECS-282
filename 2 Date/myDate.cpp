//Matias Dotta <matias.dotta@student.csulb.edu>
//CECS 282-05
//Prog 1 solitaire
//Due Oct/04/2018

#include "myDate.h"
#include <iostream>

void J2G(int, int &, int &, int &);
int G2J(int, int, int);

myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;
}

myDate::myDate(int m, int d, int y)
{
	int JD = G2J(m, d, y);
	int m1, d1, y1;
	J2G(JD, m1, d1, y1);
	if (m1 == m, d1 == d, y1 == y)
	{
		month = m;
		day = d;
		year = y;
	}
	else
	{
		month = 5;
		day = 11;
		year = 1959;
	}
}

void myDate::display()
{
	string m;
	switch (month)
	{
	case 1:
		m = "Jan";
		break;
	case 2:
		m = "Feb";
		break;
	case 3:
		m = "Mar";
		break;
	case 4:
		m = "Apr";
		break;
	case 5:
		m = "May";
		break;
	case 6:
		m = "Jun";
		break;
	case 7:
		m = "Jul";
		break;
	case 8:
		m = "Aug";
		break;
	case 9:
		m = "Sep";
		break;
	case 10:
		m = "Oct";
		break;
	case 11:
		m = "Nov";
		break;
	case 12:
		m = "Dec";
		break;
	}
	cout << m << " " << day << ", " << year;
}
void myDate::increaseDate(int n)
{
	int JD = G2J(month, day, year);
	JD += n;
	J2G(JD, month, day, year);
}
void myDate::decreaseDate(int n)
{
	int JD = G2J(month, day, year);
	JD -= n;
	J2G(JD, month, day, year);
}
int myDate::daysBetween(myDate d)
{
	int JD = G2J(month, day, year);
	JD = abs(JD - G2J(d.getMonth(), d.getDay(), d.getYear()));
	return JD;
}
int myDate::getMonth()
{
	return month;
}
int myDate::getDay()
{
	return day;
}
int myDate::getYear()
{
	return year;
}
int myDate::dayOfYear()
{
	myDate d(1, 1, year);
	int JD = abs(daysBetween(d)) + 1;
	return JD;
}
string myDate::dayName()
{
	string day1;
	int mod = (abs(G2J(month, day, year))%7);
	switch (mod)
	{
	case 0:
		day1 = "Monday";
		break;
	case 1:
		day1 = "Tuesday";
		break;
	case 2:
		day1 = "Wednesday";
		break;
	case 3:
		day1 = "Thursday";
		break;
	case 4:
		day1 = "Friday";
		break;
	case 5:
		day1 = "Saturday";
		break;
	case 6:
		day1 = "Sunday";
		break;
	}
	return day1;
}


int G2J(int j, int k, int i)
{
	int JD;
	JD = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return JD;
}

void J2G(int JD, int &month, int &day, int &year)
{
	int i, j, k, L, N;
	L = JD + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	i = 4000 * (L + 1) / 1461001;
	L = L - 1461 * i / 4 + 31;
	j = 80 * L / 2447;
	k = L - 2447 * j / 80;
	L = j / 11;
	j = j + 2 - 12 * L;
	i = 100 * (N - 49) + i + L;

	month = j;
	year = i;
	day = k;

}