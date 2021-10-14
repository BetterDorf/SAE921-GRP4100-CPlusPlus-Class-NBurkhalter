#pragma once
#include "Item.h"

class Weapon : public Item
{
	virtual void equip() = 0;

	virtual void attack() = 0;
public:
	void use() override;
};

