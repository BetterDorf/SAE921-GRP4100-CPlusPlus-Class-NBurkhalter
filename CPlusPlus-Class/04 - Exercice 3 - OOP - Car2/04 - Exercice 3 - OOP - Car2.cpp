#include <iostream>
#include <vector>

#include "SCar.h"

using namespace std;

int main()
{
    srand(time(NULL));
    vector<SCar> cars;

    for (int car = 0; car < 100 ; car++)
    {
        cars.push_back(SCar("vroum", to_string(car), "2021", rand()));
    }

    vector<SCar> newCars;

    for (auto car : cars)
    {
	    if (car.GetId() % 3 != 0)
	    {
            newCars.push_back(car);
            car.PrintValues();
	    }
    }
}