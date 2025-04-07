#pragma once
#include <iostream>
#include <string>

using namespace std;

/**
  Класс Персона.
*/

class Person
{
private:
	/**
	* Фамилия.
	*/
	string LastName;
	/**
	* Имя.
	*/
	string FirstName;
	/**
	* Отчество.
	*/
	string Patronymic;
public:
	/**
	* Конструктор по умолчанию.
	*/
	Person();
	/**
	* Конструктор по умолчанию, класса,
	* const string& LN - Фамилия,
	* const string& FN - Имя,
	* const string& PN - Отчество.
	*/
	Person(const string& LN, const string& FN, const string& PN);
	/**
	* Вывод имени и фамилии.
	*/
	void Show();
	/**
	* Вывод имени, фамилии, отчества.
	*/
	void ShowFormal();
};