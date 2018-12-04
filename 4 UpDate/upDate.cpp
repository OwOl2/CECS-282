//Matias Dotta <matias.dotta@student.csulb.edu>
//CECS 282-05
//Prog 4 upDate
//Due Nov/01/2018

#include "upDate.h"
#include "myDate.h"

int upDate::count = 0;

upDate::upDate()
{
	dptr = new int[3];
	setDate(5, 11, 1959);
	count++;
}

upDate::upDate(int month, int day, int year)
{
	dptr = new int[3];
	myDate d(month, day, year);
	setDate(d.getmonth(), d.getday(), d.getyear());
	count++;
}

upDate::upDate(int J)
{
	dptr = new int[3];
	J2G(J, dptr[0], dptr[1], dptr[2]);
	count++;
}

upDate::upDate(const upDate &D)
{
	dptr = new int[3];
	dptr[0] = D.dptr[0];
	dptr[1] = D.dptr[1];
	dptr[2] = D.dptr[2];
	count++;
}

upDate::~upDate()
{
	count--;
	delete[]dptr;
}

void upDate::setDate(int month, int day, int year) 
{
	dptr[0] = month;
	dptr[1] = day;
	dptr[2] = year;
}

int upDate::getMonth()
{
    return dptr[0];
}

int upDate::getDay() 
{
    return dptr[1];
}

int upDate::getYear()
{
    return dptr[2];
}

string upDate::getMonthName()
{
	string m;
	switch (dptr[0])
	{
	case 1:
		m = "January";
		break;
	case 2:
		m = "February";
		break;
	case 3:
		m = "March";
		break;
	case 4:
		m = "April";
		break;
	case 5:
		m = "May";
		break;
	case 6:
		m = "June";
		break;
	case 7:
		m = "July";
		break;
	case 8:
		m = "August";
		break;
	case 9:
		m = "September";
		break;
	case 10:
		m = "October";
		break;
	case 11:
		m = "November";
		break;
	case 12:
		m = "December";
		break;
	}
	return m;
}

upDate upDate::operator=(upDate const &D)
{
	if (&D != this) 
	{
		dptr[0] = D.dptr[0];
		dptr[1] = D.dptr[1];
		dptr[2] = D.dptr[2];
	}
	return *this;
}
upDate upDate::operator+(int i)
{
	upDate temp(*this);
	int j = G2J(temp.dptr[0], temp.dptr[1], temp.dptr[2]) + i;
	J2G(j, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

upDate operator+(int n, upDate D)
{
	return D + n;
}


upDate upDate::operator-(int i)
{
	upDate temp(*this);
	int j = G2J(temp.dptr[0], temp.dptr[1], temp.dptr[2]) - i;
	J2G(j, temp.dptr[0], temp.dptr[1], temp.dptr[2]);
	return temp;
}

int upDate::operator-(const upDate& D)
{
	return  G2J(dptr[0], dptr[1], dptr[2]) - G2J(D.dptr[0], D.dptr[1], D.dptr[2]);
}

upDate upDate::operator+= (int i)
{
	int j = G2J(dptr[0], dptr[1], dptr[2]) + i;
	J2G(j, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator+= (const upDate& D)
{
	int j = G2J(dptr[0], dptr[1], dptr[2]) + G2J(D.dptr[0], D.dptr[1], D.dptr[2]);
	J2G(j, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator-= (int i)
{
	int j = G2J(dptr[0], dptr[1], dptr[2]) - i;
	J2G(j, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator-= (const upDate& D)
{
	int j = G2J(dptr[0], dptr[1], dptr[2]) - G2J(D.dptr[0], D.dptr[1], D.dptr[2]);
	J2G(j, dptr[0], dptr[1], dptr[2]);
	return *this;
}

upDate upDate::operator++ ()
{
	*this += 1;
	return *this;
}

upDate upDate::operator++ (int)
{
	upDate temp(*this);
	*this += 1;
	return temp;
}

upDate upDate::operator-- ()
{
	*this -= 1;
	return *this;
}

upDate upDate::operator-- (int)
{
	upDate temp(*this);
	*this -= 1;
	return temp;
}

bool upDate::operator==(const upDate &D)
{
	return (G2J(dptr[0], dptr[1], dptr[2]) == G2J(D.dptr[0], D.dptr[1], D.dptr[2]));
}

bool upDate::operator>(const upDate &D)
{
	return (G2J(dptr[0], dptr[1], dptr[2]) > G2J(D.dptr[0], D.dptr[1], D.dptr[2]));
}

bool upDate::operator<(const upDate &D)
{
	return (G2J(dptr[0], dptr[1], dptr[2]) < G2J(D.dptr[0], D.dptr[1], D.dptr[2]));
}

ostream & operator<<(ostream &a, upDate D) 
{
	a << D.dptr[0] << '/' << D.dptr[1] << '/' << D.dptr[2];
	return a; 
}

int upDate::GetDateCount()
{
	return count;
}

int upDate::julian()
{
	return G2J(dptr[0], dptr[1], dptr[2]);
}