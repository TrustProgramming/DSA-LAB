#pragma once

class Shape
{
public:
	virtual void area() = 0;
};

class Circle : public Shape
{
private:
	float radius;
public:
	Circle(float rad);

	void area();
};

class Rectangle : public Shape
{
private :
	int length;
	int width;
public:
	Rectangle(int len, int wid);

	void area();
};