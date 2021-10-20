#pragma once
#include <iostream>

class Item
{
protected:
	std::string name_ = "NA";
public:
	virtual void use() = 0;
	std::string getName() { return name_; }
};