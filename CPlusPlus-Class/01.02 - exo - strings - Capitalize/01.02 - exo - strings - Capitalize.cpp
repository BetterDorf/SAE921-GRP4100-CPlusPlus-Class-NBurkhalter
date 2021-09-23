#include <iostream>
#include <string>

using namespace  std;

bool isLetter(char letter)
{
    //Check if letter is in the correct range in the ASCII table
    if ((letter > 64 && letter < 91) || (letter > 96 && letter < 123))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Return the capitalized string
string capitalize(string toCapitalize)
{
    bool capital = true;
    string stringReturn = "";

    for (auto letter: toCapitalize)
    {
        //check if the letter needs to be capitalized
	    if (capital == true && isLetter(letter))
	    {
            //Add the capitalized letter
            stringReturn += toupper(letter);

            //Set back capital to false
            capital = false;
	    }
        else
        {
			//add the letter as is
            stringReturn += letter;

            //check if next letter will need to be capitalize i.e. after a space ASCII code = 32
            if (letter == 32)
            {
                capital = true;
            }
        }
    }

    return stringReturn;
}

int main()
{
    //ask for string
    cout << "String To Capitalize Please" << endl;
    string stringToWorkOn;
    getline(cin, stringToWorkOn);

    //Change it
    string newString = capitalize(stringToWorkOn);


    //print it back
    cout << "Here's the new Capitalized string: "
        << newString << endl;
}