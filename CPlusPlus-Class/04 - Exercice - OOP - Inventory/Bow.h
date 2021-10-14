#pragma once

#include "Weapon.h"

class Bow : public Weapon
{
	void equip() override { std::cout << "Equipped bow" << std::endl; }
	void attack() override { std::cout << "Attacked with bow" << std::endl; }
};