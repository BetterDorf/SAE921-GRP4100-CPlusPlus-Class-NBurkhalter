#pragma once
#include <string>

using namespace  std;

class Car
{
	string brand;
	string model;
	string year;

public:
	Car();
	Car(string, string, string);

	void PrintValues();
	void ChangeValues(string, string, string);
};