#include "Sweet.h"

#include <iostream>

using namespace std;

Sweet::Sweet(string type_, int amount_)
{
	type = type_;
	amount = amount_;
}

void Sweet::Buy(int nb)
{
	if (amount >= nb)
	{
		cout << "You bought " << nb << " pieces of " << type << endl;
		amount -= nb;
	}
	else
	{
		cout << "There is only " << nb << " pieces of " << type << " left" << endl;
	}
}

void Sweet::Restock(int nb)
{
	if (nb > 0)
	{
		amount += nb;
	}
}

