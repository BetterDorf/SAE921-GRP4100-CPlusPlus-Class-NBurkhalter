#include <iostream>
#include <map>

int main()
{
    std::string answer;
    std::map<std::string, std::string> annuary;

    do
    {
        //get name
        std::cout << "Hello, please enter the first name\n";
        std::cin >> answer;

        std::string name = answer;
        std::cout << "And the last name" << std::endl;
        std::cin >> answer;
        name += " " + answer;

        //get phone
        std::cout << "What's the phone number?" << std::endl;
        std::cin >> answer;
        std::string phone = answer;

        //add to annuary
        annuary.emplace(name, phone);

        //ask to add again
        std::cout << "Add another person?(y/n)" << std::endl;
        std::cin >> answer;
    } while (answer == "y");

    do
    {
        //get name
        std::cout << "Enter the first name of the person you want to get" << std::endl;
        std::cin >> answer;

        std::string name = answer;
        std::cout << "And the last name" << std::endl;
        std::cin >> answer;
        name += " " + answer;

        //print phone
        std::cout << "Phone : " << annuary.at(name) << std::endl;

        //ask to look again
        std::cout << "Look up another person?(y/n)" << std::endl;
        std::cin >> answer;
    } while (answer == "y");
}