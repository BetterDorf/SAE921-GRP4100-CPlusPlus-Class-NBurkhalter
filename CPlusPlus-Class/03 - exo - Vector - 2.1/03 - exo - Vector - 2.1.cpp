#include <iostream>
#include <random>
#include <vector>

int const HIGHEST_VALUE = 20;

//Setup the random
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> randNum(1, HIGHEST_VALUE);

int randomNum()
{
    return randNum(gen);
}

void printVector(std::vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
        std::cout << vector[i] << " ";
	}
}

int main()
{
    std::vector<int> vector;

    //populate the vector
    for (int i = 0; i <= 12 ; i++)
    {
        vector.push_back(randomNum());
    }

    //iterate over vector and record the lowest number and its position
    int lowestNumIndex = 0;
    int lowestNum = 21;

    for (int i = 0; i < vector.size(); i++)
    {
        //Check if curNum is lower than lowest
	    if (vector[i] < lowestNum)
	    {
            lowestNum = vector[i];
            lowestNumIndex = i;
	    }
    }

    //Insert 0's a number of time corresponding to the number
	vector.insert(vector.begin() + lowestNumIndex + 1, lowestNum, 0);

    //print it
    printVector(vector);
}