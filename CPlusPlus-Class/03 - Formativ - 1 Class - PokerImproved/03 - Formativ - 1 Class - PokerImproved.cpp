#include <iostream>
#include "Card.h"
#include <vector>
#include <array>

using namespace std;

int const CARDS_TO_DRAW = 5;

bool inArray(int value, std::array<int, CARDS_TO_DRAW> cardsDrawn)
{
	for (auto card : cardsDrawn)
	{
		if (value == card)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	//seed the random
	srand(time(NULL));

	//Declare the deck
	vector<Card> deck;
	deck.reserve(52);

	//populate it
	for (int value = 0; value < 13; value++)
	{
		for (int suit = 0; suit < 4; suit++)
		{
			deck.emplace_back(Card(value, suit));
		}
	}

	//make the hand (keeps reference to the positions of the cards in the deck)
	array<int, CARDS_TO_DRAW> hand
	{ 0 * CARDS_TO_DRAW };

	//Fill the hand
	for (int card = 0; card < CARDS_TO_DRAW; card++)
	{
		//grab a random valid number
		int cardToDraw;
		do
		{
			cardToDraw = rand() % 52;
		} while (inArray(cardToDraw, hand));

		deck.at(cardToDraw).print();
	}
}