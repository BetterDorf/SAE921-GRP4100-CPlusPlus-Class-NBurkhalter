#pragma once
#include <vector>
#include <memory>

#include "Item.h"

class Inventory
{
	std::vector<std::unique_ptr<Item>> items {};
public:
	void print();
	void use(int index);
	void add(std::unique_ptr<Item> ptr);
};