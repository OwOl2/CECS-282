#ifndef UPDATE_H
#define UPDATE_H
#include <string>
#include <iostream>
using namespace std;


class upDate
{
private:
	int *dptr;
	static int count; 
public:
	upDate();
	upDate(int, int, int );
	upDate(int);
	upDate(const upDate &);
	~upDate();
	void setDate(int, int, int);
	int getMonth();
	int getDay();
	int getYear();
	string getMonthName();
	
	upDate operator=(const upDate&);
	upDate operator+(int);
	friend upDate operator+(int, upDate);
	upDate operator-(int);
	int operator-(const upDate&);
	upDate operator+=(int);
	upDate operator+=(const upDate&);
	upDate operator-=(int);
	upDate operator-=(const upDate&);
	upDate operator++();
	upDate operator++(int);
	upDate operator--();
	upDate operator--(int);

	bool operator==(const upDate&);
	bool operator>(const upDate&);
	bool operator<(const upDate&);

	friend ostream & operator<<(ostream&, upDate);
	static int GetDateCount();
	int julian();
};

#endif