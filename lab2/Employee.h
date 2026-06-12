#pragma once

class Employee
{
public:
	virtual void calculateSalary() = 0;
};

class FullTimeEmployee : public Employee
{
private:
	int fixSalary;
public:
	FullTimeEmployee(int sal);

	void calculateSalary();
};

class PartTimeEmployee : public Employee
{
private:
	float hours;
public:
	PartTimeEmployee(float hour);

	void calculateSalary();
};