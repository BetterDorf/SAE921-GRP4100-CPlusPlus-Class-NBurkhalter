#include <iostream>
#include <string>

std::string replace(std::string original, std::string thingToReplace, std::string newPart)
{
    int pos = original.find(thingToReplace);

    return  original.replace(pos, thingToReplace.length(), newPart);
}

int main()
{
    //Get name and amount of ennemies
    std::cout << "What is your name?" << std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Correct!" << std::endl;

    std::cout << "And how many enemies do you think you could take on?" << std::endl;
    int enemies = 0;
    std::cin >> enemies;

    std::string death_message = "[Name] died fighting [Enemies] dragons. How sad!";
    death_message = replace(death_message, "[Name]", name);
    death_message = replace(death_message, "[Enemies]", std::to_string(enemies));

    std::cout << death_message;
}