#include <iostream>
#include "guns.h"

int main()
{
	Guns gun = Guns(2);

	std::cout << "Gun loaded" << std::endl;

	gun.spinBarrel();

	std::cout << "Gun spinned" << std::endl;

	std::string buffer;

	while(true)
	{
		std::cout << "Type anthything to shoot" << std::endl;

		std::cin >> buffer;

		if (gun.shoot())
		{
			std::cout << "BANG";
			break;
		}

		std::cout << "click" << std::endl;
	}
}