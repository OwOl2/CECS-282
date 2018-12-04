
#include "myDate.h"
#include <string>
#include <iostream>
#include <time.h> 
#include <iomanip>
using namespace std;

struct Student //56
{
	char name[20];
	int ID;
	char grade;
	myDate birthday;
	string homeTown;
};
void populate(Student *Sa);
void display(Student **s);
void display(Student *s);
void sortByName(Student *s[], Student *Sa);
void sortByID(Student *s[], Student *Sa);
void sortByID(Student *s[], Student *Sa);
void sortByBday(Student *s[], Student *Sa);
void sortByGrade(Student *s[], Student *Sa);
void sortByHomeTown(Student *s[], Student *Sa);
int main()
{
	Student a[10];
	Student *name[10];
	Student *ID[10];
	Student *grade[10];
	Student *birthday[10];
	Student *homeTown[10];
	populate(a);

	while (true)
	{
		int opt;
		cout << "WELCOME \n\n0)Display original list\n1) Display list sorted by Name\n2) Display list sorted by Student ID\n3) Display list sorted by Grade\n4) Display list sorted by Birthday\n5) Display list sorted by Home Town\n6)EXIT\n>>";
		cin >> opt;

		switch (opt)
		{
		case 0:
		{
			display(a);
			break;
		}
		case 1:
		{
			sortByName(name, a);
			display(name);
			break;
		}
		case 2:
		{
			sortByID(ID, a);
			display(ID);
			break;
		}
		case 3:
		{
			sortByGrade(grade, a);
			display(grade);
			break;
		}
		case 4:
		{
			sortByBday(birthday, a);
			display(birthday);
			break;
		}
		case 5:
		{
			sortByHomeTown(homeTown, a);
			display(homeTown);
			break;
		}
		case 6:
			return 0;
		}
	}
}
void populate(Student *Sa) //Sa[0]
{	
	srand(time(NULL));
	int t1, t2, t3;

	strcpy_s(Sa[0].name, "Matthew");
	strcpy_s(Sa[1].name, "Aiden");
	strcpy_s(Sa[2].name, "Joseph");
	strcpy_s(Sa[3].name, "Samuel");
	strcpy_s(Sa[4].name, "Wyatt");
	strcpy_s(Sa[5].name, "Riley");
	strcpy_s(Sa[6].name, "Killian");
	strcpy_s(Sa[7].name, "Case");
	strcpy_s(Sa[8].name, "Lydia");
	strcpy_s(Sa[9].name, "Mery");


	Sa[0].homeTown = "Dallas";
	Sa[1].homeTown = "Austin";
	Sa[2].homeTown = "Indianapolis";
	Sa[3].homeTown = "Fort Worth";
	Sa[4].homeTown = "Detroit";
	Sa[5].homeTown = "Denver";
	Sa[6].homeTown = "Boston";
	Sa[7].homeTown = "Seattle";
	Sa[8].homeTown = "Oklahoma City";
	Sa[9].homeTown = "Portland";

	

	for (int i = 0; i < 10; i++)
	{
		Sa[i].birthday = myDate();

		Sa[i].ID = rand() % 8999 + 1000;
		for (int n = i-(i-1); n < i; n++)
		{
			if (Sa[n].ID == Sa[i].ID)
			{
				Sa[i].ID = rand() % 8999 + 1000;
				n = 0;
			}
				
		}
			
		
		Sa[i].grade = char(rand() % 5 + 65);
		if (Sa[i].grade == 'E')
			Sa[i].grade = 'F';
		Sa[i].birthday.J2G(((rand() % 2191) + 2449719), t1, t2, t3);
		Sa[i].birthday = myDate(t1, t2, t3);
	}
	
	
}

void display(Student **s)
{
	cout << left << setw(10) <<"Name"<<setw(15)<<"Student ID"<<setw(8)<<"Grade"<<setw(15)<<"Birthday"<<setw(20)<<"Home Town"<<"\n\n";
	for (int i = 0; i < 10; i++)
	{
		
		cout << left << setw(10) << s[i]->name << setw(15) << s[i]->ID << setw(8) << s[i]->grade << setw(15) << s[i]->birthday.printDate() << setw(20) << s[i]->homeTown <<"\n";
	}
	
}

void display(Student *s)
{
	cout << left << setw(10) << "Name" << setw(15) << "Student ID" << setw(8) << "Grade" << setw(15) << "Birthday" << setw(20) << "Home Town" << "\n\n";
	for (int i = 0; i < 10; i++)
	{

		cout << left << setw(10) << s[i].name << setw(15) << s[i].ID << setw(8) << s[i].grade << setw(15) << s[i].birthday.printDate() << setw(20) << s[i].homeTown << "\n";
	}


}

void sortByName(Student *s[],Student *Sa)
{
	for (int i = 0; i < 10; i++)
	{
		s[i] = &Sa[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < (9 - i); j++)
		{
			string h = s[j]->name;
			if (h.compare(s[j + 1]->name) > 0)
			{
					Student *temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
			}
		}
	}		
}

void sortByID(Student *s[], Student *Sa)
{

	for (int i = 0; i < 10; i++)
	{
		s[i] = &Sa[i];
	}
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < (9 - i); j++)
		{
			if (s[j]->ID < s[j + 1]->ID)
			{
				Student *temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}			
}

void sortByGrade(Student *s[], Student *Sa)
{

	for (int i = 0; i < 10; i++)
	{
		s[i] = &Sa[i];
	}
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < (9 - i); j++)
		{
			if (s[j]->grade > s[j + 1]->grade)
			{
				Student *temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

void sortByBday(Student *s[], Student *Sa)
{

	for (int i = 0; i < 10; i++)
	{
		s[i] = &Sa[i];
	}
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < (9 - i); j++)
		{
			if (s[j]->birthday.getDate() > s[j + 1]->birthday.getDate())
			{
				Student *temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}

void sortByHomeTown(Student *s[], Student *Sa)
{
	for (int i = 0; i < 10; i++)
	{
		s[i] = &Sa[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < (9 - i); j++)
		{
			string h = s[j]->homeTown;
			if (h.compare(s[j + 1]->homeTown) > 0)
			{
				Student *temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}





