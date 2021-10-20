// 06 - Program structure - Exercice - Function pointer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

int main()
{

    // Some numbers
    const std::vector<int> numbers = { 12,54,42,42,56,78 };

    // Fill the  gaps in the lambda expression, display the value of an integer
    auto display = [](int num) {std::cout << num << std::endl; };

    // Using the capture by reference :
    int bigNumber = 1000;
    // Write a lambda expression substracting a parameter to a captured element into
    auto substract = [&](int num) {bigNumber -= num; };

    // Use the lambda into the for loop below
    for (auto number : numbers)
    {
        // Make the substract
        substract(number);

        // Display the result
        display(bigNumber);
    }
}
