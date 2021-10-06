#pragma once
class Point
{
public:
	int x;
	int y;

	Point();
	Point(int x_, int y_);

	void Move(int dx, int dy);
	void Print();
	void Set();

	float Distance(Point p2);
};