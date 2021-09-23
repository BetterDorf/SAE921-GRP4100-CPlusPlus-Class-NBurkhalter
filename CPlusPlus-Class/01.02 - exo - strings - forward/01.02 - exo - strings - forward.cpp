#include <iostream>
#include <string>

using namespace  std;

int main()
{
    //ask for string
    cout << "string please" << endl;
    string stringToWorkOn;
    cin >> stringToWorkOn;

    //Change it
    string newString = "";

    for (char letter : stringToWorkOn)
    {
        //check if letter is in fact a letter
        if ((letter > 64 && letter < 91) || (letter > 96 && letter < 123))
        {
            //modulo 32 to get rid of maj and +97 to give lowercase letter (+96 would be the same letter)
            newString += letter % 32 + 97;
        }
        //if not, just add it as is
        else
        {
            newString += letter;
        }
    }

    //print it back
    cout << "Here's the new string: "
        << newString << endl;
}