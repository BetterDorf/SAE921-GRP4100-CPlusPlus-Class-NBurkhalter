#pragma once
#include  <vector>
#include <iostream>

class Guns
{
	int currentChamber = 0;
	std::vector<bool> chambers = std::vector<bool>(10);

public:
	Guns(int);
	bool shoot();
	void spinBarrel();
};