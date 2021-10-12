#include <iostream>

#include "Header.h"

using namespace std;

int main()
{
    //Seed the random
    srand(time(NULL));

    //Greeet the user
    cout << "Welcome to farming simulator 2023 : Abstract trees edition!" << endl << endl;
    cout << "Generating trees..." << endl << "Just kidding, it's practically instantaneous." << endl << endl;


    //Make trees according to the average needed per tree
    //We'll put half of the necessary trees to make it more interesting
    //for apples : 0.15kg * 725 apples = 108.75Kg / tree => 18.3 trees, rounded to 18
    vector<Apple_Tree> apple_trees(9);

    //for pears : 0.09kg * 300 pears = 27Kg / tree => 74 trees
    vector<Pear_Tree> pear_trees(37);

    //For cherries : 0.005Kg * 3000 cherries = 15Kg => 133.33 trees rounded to 133
    vector<Cherry_Tree> cherry_trees(67);

	//Harvest 10 time
    for (int year = 1; year <= 10 ; year++)
    {
        cout << "YEAR : " << year << endl;

	    //Step 1, grow the fruits
        for (auto& apple_tree : apple_trees) //apples
	        apple_tree.grow();
        for (auto& tree : pear_trees) //pears
            tree.grow();
        for (auto& tree : cherry_trees) //cherries
            tree.grow();

	    //Step 2, harvest them until we have enough (User chooses which gets harvested)
        float weight = 0;
        bool harvApple = false, harvPear = false, harvCherry = false;
        do
        {
            //Take input
            cout << "Which tree do you want to harvest?" << endl << "(a)pple ; (p)ear ; (c)herry" << endl;
            char answer;
            cin >> answer;

            //Harvest the chosen trees
            cout << "Here is the result of that harvest :" << endl;
            switch (answer)
            {
            default:break;
            case 'a' :
                //Check if it was already harvested
                if (harvApple)
                {
                    cout << "Already harvested" << endl;
                    break;
                }
                //Harvest every tree and add it to our total
                for (Apple_Tree tree : apple_trees)
                    weight +=  tree.harvest();
                //Set harvested to true
                harvApple = true;
                break;
            case 'p' :
                if (harvPear)
                {
                    cout << "Already harvested" << endl;
                    break;
                }
                for (auto tree : pear_trees)
                    weight += tree.harvest();
                harvPear = true;
                break;
            case 'c' :
                if (harvCherry)
                {
                    cout << "Already harvested" << endl;
                    break;
                }
                for (auto tree : cherry_trees)
                    weight += tree.harvest();
                harvCherry = true;
                break;
            }

            cout << endl << endl << "You currently have " << weight << "Kg of fruits..." << endl;
        } while (weight < 2000.0f && !(harvApple && harvCherry && harvPear));

	    //Step 3, if we don't have enough fruits, breach the contract
        if (weight < 2000.0f)
        {
            cout << "Which isn't enough, you needed 2000" << endl << "You have failed to uphold your contract";
            return 0;
        }

        cout << "You have passed this year with an excess of " << weight - 2000.0f << "Kg." << endl;
    }

    //Congratulate the farmer
    cout << endl << "You have managed to uphold your contract for 10 Years!" << endl
        << "Congratulations!" << endl << "You win at life.";

}