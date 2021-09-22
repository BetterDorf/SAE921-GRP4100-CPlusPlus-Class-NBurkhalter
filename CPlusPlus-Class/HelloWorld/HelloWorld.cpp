#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int const STARTINGMONEY = 413;

int roll_dice()
{
	return rand() % 6 + 1;
}

int roll_multiple(int x)
{
	int total = 0;
	for (int dice = 0 ; dice < x ; dice++)
	{
		total += roll_dice();
	}

	return  total;
}

char take_answer()
{
	char answer;

	do
	{
		cout << "Keep Going?(y/n)" << endl;
		cin >> answer;
	} while (answer != 'n' && answer != 'y');

	return answer;
}

int main()
{
	//seed the random
	srand(time(nullptr));

	//initialize the money
	int money = STARTINGMONEY;

	//Welcome the user
	cout << "Welcome to dice betting thingy : THE GAME" << endl
	<< "You have : " << STARTINGMONEY << endl;

	while(true)
	{
		cout << "choose a number to bet: ";

		//take the amount to bet
		int bet = 0;
		cin >> bet;
		money -= bet;

		//rolls
		int scoreToBeat = 7;
		int score = 0;
		char answer;
		do
		{
			// roll the dice
			score = roll_multiple(2);

			//print the results
			cout << "You rolled: " << score
				<< " You needed to beat: " << scoreToBeat << endl;

			//check the score
			if (score > scoreToBeat)
			{
				//win
				bet *= 2;
				scoreToBeat = score;
				cout << "You won!" << endl;

				//ask to play again
				cout << "Your winnings are: " << bet << endl;

				answer = take_answer();

				//check answer
				if (answer == 'y')
				{
					// if yes, keep looping
					continue;
				}
				else
				{
					//else stop playing
					break;
				}
			}
			else
			{
				//lose and stop playing
				cout << "You lost" << endl;
				bet = 0;
				break;
			}
		} while (true);

		// show results
		if (bet != 0)
		{
			cout << "You won: " << bet << "CHF" << endl;
		}

		//calulate and show balance
		money += bet;
		cout << "You now have: " << money << "CHF" << endl;
	}
} 