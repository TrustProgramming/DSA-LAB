#include <iostream>
#include "Employee.h"
using namespace std;

FullTimeEmployee::FullTimeEmployee(int sal)
{
	fixSalary = sal;
}
void FullTimeEmployee::calculateSalary()
{
	cout << " Salary of Full time Employee : " << fixSalary << endl;
}
PartTimeEmployee::PartTimeEmployee(float hour)
{
	hours = hour;
}
void PartTimeEmployee::calculateSalary()
{
	float result = hours * 1000;

	cout << " Salary of Part time Employee : " << result << endl;
}