#include "Header.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;

	//Initialize inventory
	Inventory inv;
	char ans = '0';
	while(true)
	{
		//Take input
		do
		{
			cout << "What do you want to do?" << endl
				<< "(u)se ; (a)dd ; (p)rint " << endl;
			cin >> ans;
		} while (ans != 'u' && ans != 'a' && ans != 'p');

		//Effectue action
		if (ans == 'a')
		{
			//Take input
			do
			{
				cout << "What do you want to add?" << endl
					<< "(h)ealth potion ; (f)orce potion ; (b)ow ; (s)word ; (m)ap " << endl;
				cin >> ans;
			} while (ans != 'h' && ans != 'f' && ans != 'b' && ans != 's' && ans != 'm');

			//Add the item
			switch (ans)
			{
			case 'h':
				inv.add(make_unique<HealthPotion>(HealthPotion()));
				break;
			case 'f':
				inv.add(make_unique<ForcePotion>(ForcePotion()));
				break;
			case 'b':
				inv.add(make_unique<Bow>(Bow()));
				break;
			case 's':
				inv.add(make_unique<Sword>(Sword()));
				break;
			case 'm':
				inv.add(make_unique<Map>(Map()));
			default:
				break;
			}
		}
		else if (ans == 'p')
			inv.print();
		else if (ans == 'u')
		{
			int index = 0;
			do
			{
				cout << "What do you want to use? (index)" << endl;
				cin >> index;
			} while (index < 0);
			inv.use(index);
		}
	}
}