#include "Card.h"

#include <iostream>

Card::Card(int value_, int suit_)
{
    //convert the ints into values and suits
	value = static_cast<Value>(value_);
	suit = static_cast<Suit>(suit_);
}


void Card::print()
{
    // set text to value
    std::string cardText;
    switch (value)
    {
    case Value::Ace: cardText = "Ace"; break;
    case Value::Two: cardText = "Two"; break;
    case Value::Three: cardText = "Three"; break;
    case Value::Four: cardText = "Four"; break;
    case Value::Five: cardText = "Five"; break;
    case Value::Six:cardText = "Six"; break;
    case Value::Seven:cardText = "Seven"; break;
    case Value::Eight:cardText = "Eight"; break;
    case Value::Nine:cardText = "Nine"; break;
    case Value::Ten:cardText = "Ten"; break;
    case Value::Jack:cardText = "Jack"; break;
    case Value::Queen:cardText = "Queen"; break;
    case Value::King:cardText = "King"; break;
    case Value::nbValues: break;
    default:;
    }

    cardText.append(" of ");

    //Add the suit
    std::string suitText;
    switch (suit)
    {
    case Suit::Hearts:
        suitText = "Hearts";
        break;
    case Suit::Clubs:
        suitText = "Clubs";
        break;
    case Suit::Spades:
        suitText = "Spades";
        break;
    case Suit::Diamonds:
        suitText = "Diamonds";
        break;
    default:;
    }
    cardText.append(suitText);

    std::cout << cardText << std::endl;
}
