#pragma once
#include <string>

using namespace std;

class SCar
{
	std::string brand;
	string model;
	string year;
	int id;

public:
	SCar(string, string, string, int);

	void PrintValues();
	void ChangeValues(string, string, string, int);
	int GetId() { return id; };
};

