#include <iostream>

using namespace std;

int main()
{
    cout << "Hello, what is your first name?" << endl;
    string firstName;
    cin >> firstName;

    cout << "and your last name?" << endl;
    string name;
    cin >> name;

    cout << "Could I have your age please?" << endl;
    string age;
    cin >> age;

    cout << "Welcome to this exercise, "
        << firstName << " " << name << " a human, presumably, born "
        << age << " years ago." << endl;
}