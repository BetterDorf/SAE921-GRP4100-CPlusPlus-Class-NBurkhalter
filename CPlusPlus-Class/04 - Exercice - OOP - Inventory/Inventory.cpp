#include "ItemClasses.h"

void Inventory::print()
{
	for (int i = 0 ; i < items.size() ; i++)
		std::cout << i << ": " << items.at(i)->getName() << std::endl;
}

void Inventory::add(std::unique_ptr<Item> ptr)
{
	items.emplace_back(std::move(ptr));
}

void Inventory::use(int index)
{
	if (items.size() > index && index > 0)
		items.at(index)->use();
}