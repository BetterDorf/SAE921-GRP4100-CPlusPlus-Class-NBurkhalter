#pragma once
#include "Item.h"

class Map :
    public Item
{
    void use() override { std::cout << "You looked at your map" << std::endl; }
};

