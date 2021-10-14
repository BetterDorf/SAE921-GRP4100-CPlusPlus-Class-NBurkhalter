#include "Weapon.h"

using namespace std;

void Weapon::use()
{
	std::cout << "(a)ttack or (e)quip?" << std::endl;
	char ans = ' ';
	std::cin >> ans;

	if (ans == 'a')
		attack();
	else if (ans == 'e')
		equip();
}
