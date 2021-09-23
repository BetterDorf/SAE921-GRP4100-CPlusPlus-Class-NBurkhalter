#include <iostream>
#include <string>

using namespace  std;

string longestWord(string sentence)
{
    string longest = "";
    int longestLength = 0;

    string curWord = "";
    int curLength = 0;

    //contruct words from the string and check them against the current longest word
    for (char letter : sentence)
    {
        //when a space occur, our cur word has ended
	    if (letter == 32)
	    {
            curWord = "";
            curLength = 0;
	    }
        else
        {
	        //add the current letter and increment the length
            curWord += letter;
            curLength++;

            //check current length against the best
            if (curLength > longestLength)
            {
                longest = curWord;
                longestLength = curLength;
            }
        }
    }

    return longest;
}

int main()
{
    //ask for string
    cout << "Give me a string please.\nI need it." << endl;
    string stringToWorkOn;
    getline(cin, stringToWorkOn);

    //find longest word
    string longest = longestWord(stringToWorkOn);
    


    //print it back
    cout << "The longest word in that string is: "
        << longest << endl;
}