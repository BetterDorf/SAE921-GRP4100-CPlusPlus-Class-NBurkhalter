#include <iostream>
#include "Car.h"

int main()
{
    Car car1("Fiat", "Panda", "1982");
    Car car2("Ford", "Mustang", "1966");

    std::cout << "Car 1 : ";
    car1.PrintValues();

    std::cout << "Car 2 : ";
    car2.PrintValues();
}