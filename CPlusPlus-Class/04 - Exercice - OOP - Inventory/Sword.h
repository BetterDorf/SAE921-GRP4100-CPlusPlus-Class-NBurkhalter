#pragma once

#include "Weapon.h"

class Sword : public Weapon
{
	void equip() override { std::cout << "Equipped sword" << std::endl; }
	void attack() override { std::cout << "Attacked with sword" << std::endl; }

public:
	Sword() { name_ = "Sword"; }
};