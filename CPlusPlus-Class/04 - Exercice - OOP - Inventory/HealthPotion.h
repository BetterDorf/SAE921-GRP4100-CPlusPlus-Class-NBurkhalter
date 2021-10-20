#pragma once

#include "Potion.h"

class HealthPotion : public Potion
{
	void drink() override { std::cout << "Health potion drank" << std::endl; }
public:
	HealthPotion() { name_ = "Health Potion"; }
};