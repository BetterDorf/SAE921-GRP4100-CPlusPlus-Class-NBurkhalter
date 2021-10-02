#include "gun.h"

#include <random>

std::random_device rd;
std::mt19937 eng(rd());
std::uniform_int_distribution<> randChamber(0, 9);

Gun::Gun(int bullets)
{
	if (bullets > 10)
	{
		std::cout << "Too many bullets!";
		return;
	}

	bool inserted = false;
	while (bullets > 0)
	{
		do
		{
			int chamber = randChamber(eng);
			if (chambers[chamber] == false)
			{
				inserted = true;
				bullets--;
				chambers[chamber] = true;
			}
		} while (!inserted);
	}
}

void Gun::spinBarrel()
{
	currentChamber = randChamber(eng);
}

bool Gun::shoot()
{
	bool shoot = chambers[currentChamber];

	currentChamber = (currentChamber + 1) % 10;

	return shoot;
}