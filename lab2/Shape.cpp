#include <iostream>
#include "Shape.h"
using namespace std;

Circle::Circle(float rad)
{
	radius = rad;
}
void Circle::area()
{
	float result = radius * radius;

	cout << " Area of Circle : " << result << endl;
}
Rectangle::Rectangle(int len, int wid)
{
	length = len;
	width = wid;
}
void Rectangle::area()
{
	int result = length * width;

	cout << " Area of Rectangle : " << result << endl;
}