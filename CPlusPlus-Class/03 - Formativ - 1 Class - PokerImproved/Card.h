#pragma once
#include <string>

//Enum of values a card can have
enum class Value : int
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,

    nbValues
};

//Enum of suit of a card
enum class Suit
{
    Hearts,
    Clubs,
    Spades,
    Diamonds,

    nbSuits
};

class Card
{
	Value value;
	Suit suit;

public:
	Card(int, int);
	void print();
};
