#pragma once
#include <random>

class Tree
{
protected:
	int fruits_ = 0; //Amount of fruits currently on this tree
	float fruit_weight_ = 0; //Intrisinc weight of this tree's fruit

	//The range of fruits that can be made
	int min = 0;
	int max = 0;

public:
	void grow(); //Generate a random amount of fruits in range_
	float harvest(); //Remove all fruits and return how many was removed * weight
};

