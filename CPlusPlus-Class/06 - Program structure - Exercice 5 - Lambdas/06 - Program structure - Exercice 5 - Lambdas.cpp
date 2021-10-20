 // 06 - Program structure - Exercice - Function pointer.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    // Some numbers
    const std::vector<int> numbers = { 12,54,42,42,56,78 };

    int bigNumber = 1000;
    // Use what you learned from previous exercice
	// Use another lambda to substract and display into a for_each algorithm
    // Fill brackets with some code
    std::for_each(numbers.begin(), numbers.end(),
        [&bigNumber](int num)
        {
	        bigNumber -= num;
        	std::cout << bigNumber << std::endl;
        });

}