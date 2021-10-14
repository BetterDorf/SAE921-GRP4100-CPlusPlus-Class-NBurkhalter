#pragma once
#include "Item.h"

class Potion : public Item
{
	virtual void drink();
public:
	void use() override { drink(); };
};