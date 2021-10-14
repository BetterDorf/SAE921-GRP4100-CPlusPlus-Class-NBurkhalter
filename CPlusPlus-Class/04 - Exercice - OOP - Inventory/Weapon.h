#pragma once
#include "Item.h"

class Weapon : public Item
{
	virtual void equip(){}

	virtual void attack(){}
public:
	void use() override;
};

