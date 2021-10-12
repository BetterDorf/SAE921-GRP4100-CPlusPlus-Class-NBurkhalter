#include "Tree.h"

#include <iostream>

void Tree::grow()
{
	//Generate a random amount of fruits in the range
	fruits_ = rand() % (max - min) + min;
}

float Tree::harvest()
{
	//Remove all fruits and return how many was removed
	std::cout << fruits_ << " ";
	auto harvested = static_cast<float>(fruits_);
	fruits_ = 0;

	return harvested * fruit_weight_; //Mutliply by weight
}
