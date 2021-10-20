#pragma once

#include "Potion.h"

class ForcePotion : public Potion
{
	void drink() override { std::cout << "Force potion drank" << std::endl; }
public:
	ForcePotion() { name_ = "Force Potion"; }
};

