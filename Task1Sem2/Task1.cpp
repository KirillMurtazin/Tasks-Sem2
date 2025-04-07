#include <iostream>
#include <string>
#include "Task1.h"

using namespace std;

Person::Person()
{
	string LastName = "";
	string FirstName = "";
	string Patronymic = "";
}

Person::Person(const string& LN, const string& FN, const string& PN)
{
	LastName = LN;
	FirstName = FN;
	Patronymic = PN;
}

void Person::Show()
{
	cout << "Name: " << LastName << endl << "Surname: " << FirstName << endl;
}

void Person::ShowFormal()
{
	cout << "Name: " << LastName << endl << "Surname: " << FirstName << endl << "Patronymic: " << Patronymic << endl;
}