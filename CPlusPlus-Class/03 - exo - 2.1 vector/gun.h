#pragma once
#include  <vector>
#include <iostream>

class Gun
{
	int currentChamber = 0;
	std::vector<bool> chambers = std::vector<bool>(10);

public:
	Gun(int);
	bool shoot();
	void spinBarrel();
};