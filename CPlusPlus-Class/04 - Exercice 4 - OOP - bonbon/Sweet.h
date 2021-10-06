#pragma once
#include <string>

using namespace std;

class Sweet
{
	string type = "Licorice";
	int amount = 0;

public:
	Sweet(string type_, int amount_);

	void Buy(int nb);
	void Restock(int nb);
};