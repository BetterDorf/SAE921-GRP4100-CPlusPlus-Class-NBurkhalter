#include <iostream>
#include <string>

using namespace  std;

int main()
{
    //ask for string
    cout << "string please" << endl;
    string stringToWorkOn;
    cin >> stringToWorkOn;

    //reverse it
    string newString = "";

    for (int inverseIndex = stringToWorkOn.length() - 1; inverseIndex > -1; inverseIndex--)
    {
        newString = newString + stringToWorkOn.at(inverseIndex);
    }

    //print it back
    cout << "Here's the new string: "
        << newString << endl;
}