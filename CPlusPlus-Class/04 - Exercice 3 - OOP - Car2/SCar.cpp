#include "SCar.h"

#include <iostream>

using namespace std;

SCar::SCar(string brand_, string model_, string year_, int id_)
{
	brand = brand_;
	model = model_;
	year = year_;
	id = id_;
}

void SCar::PrintValues()
{
	cout << brand << " " << model << " " << year << endl;
}

void SCar::ChangeValues(string brand_, string model_, string year_, int id_)
{
	brand = brand_;
	model = model_;
	year = year_;
	id = id_;
}