#pragma once
class Point
{
public:
	float x;
	float y;

	Point();
	Point(int x_, int y_);

	void Move(int dx, int dy);
	void Print();
	void Set();

	float Distance(Point p2);

	Point operator+(Point& p2);
	bool operator>(Point& p2);
};