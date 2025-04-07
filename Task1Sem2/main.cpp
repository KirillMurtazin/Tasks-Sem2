#include <iostream>
#include <string>
#include "Task1.h"

using namespace std;

/**
   Точка входа в программу.
*/
int main()
{
	Person person1("Ivanov", "Ivan", "Ivanovich");

	person1.Show();
	person1.ShowFormal();

	return 0;
}