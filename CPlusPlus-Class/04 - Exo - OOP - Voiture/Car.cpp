#include "Car.h"
#include <iostream>

Car::Car()
{
	brand = "brand";
	model = "model";
	year = "year";
}

Car::Car(string brand_, string model_, string year_)
{
	brand = brand_;
	model = model_;
	year = year_;
}

void Car::PrintValues()
{
	cout << brand << " " << model << " " << year << endl;
}

void Car::ChangeValues(string brand_, string model_, string year_)
{
	brand = brand_;
	model = model_;
	year = year_;
}