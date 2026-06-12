#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
	FullTimeEmployee fullEmployee(25000);
	PartTimeEmployee partEmployee(5.5);

	fullEmployee.calculateSalary();
	partEmployee.calculateSalary();

	return 0;
}