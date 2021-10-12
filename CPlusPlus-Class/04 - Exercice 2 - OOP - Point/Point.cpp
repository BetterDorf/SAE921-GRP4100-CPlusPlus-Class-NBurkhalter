#include "Point.h"
#include <iostream>

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int x_, int y_)
{
	x = x_;
	y = y_;
}

void Point::Move(int dx, int dy)
{
	x += dx;
	y += dy;
}

void Point::Print()
{
	std::cout << "x: " << x << " y: " << y << std::endl;
}

void Point::Set()
{
	std::cout << "Type a value for x:" << std::endl;
	std::cin >> x;
	std::cout << "Type a value for y:" << std::endl;
	std::cin >> y;
}

float Point::Distance(Point p2)
{
	return  sqrt (pow(p2.x - x, 2) + pow(p2.y - y, 2));
}

Point Point::operator+(Point& p2)
{
	Point middle;
	middle.x = (p2.x + x) / 2.0f;
	middle.y = (p2.y + y) / 2.0f;
	return middle;
}

bool Point::operator>(Point& p2)
{
	Point origin(0.0f, 0.0f);
	float d1 = Distance(origin);
	float d2 = p2.Distance(origin);

	return (d1 > d2);
}

