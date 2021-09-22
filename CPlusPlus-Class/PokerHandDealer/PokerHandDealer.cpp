#include <algorithm>
#include <iostream>
#include <string>
#include <array>
#include <ctime>

const int CARDS_TO_DRAW = 5;
int const CARDS = 52;

//Enum of values a card can have
enum class Value
{
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
    Ace,

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

//Show card method
void printCard(Value value, Suit suit)
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
	    default: ;
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
	    default: ;
    }
    cardText.append(suitText);

    std::cout << cardText << std::endl;
}

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

void printHandValue(std::array<Value, CARDS_TO_DRAW> valuesDrawn, std::array<Suit, CARDS_TO_DRAW> suitsDrawn)
{
    //some reusable variables
    int curCard = 0;

	//register both straight and flushes
    bool flush = true;
    Suit suitOfHand = suitsDrawn.at(0);
    for (auto suit : suitsDrawn)
    {
	    if (suit != suitOfHand)
	    {
            flush = false;
		    break;
	    }
    }

    //check for straight
    bool straight = true;

    //Check for straight flush

    //register the highest number of identical values
    //Check if there is a four of a kind

    //check if there is a three-of-a-kind and register the bool second pair (full house)

    //check if a normal flush was achieved

    //check for straight

    //three of a kind

    //a pair and another pair

    //a pair

    //if none of those, print the highest value
}

int main()
{
    srand(time(NULL));

    //Say hi to the player
    std::cout << "Hello, your hand is:" << std::endl;

    //Make the deck
    //Declaration of variables relating to the deck
    int nbValue = 13;
    int nbSuit = 4;

    std::array<Value, CARDS> values; 
    std::array<Suit, CARDS> suits;

    //for each value make a card of each suit
    int pos = 0;
    for (int value = 0 ; value < nbValue; value++)
    {
        for (int suit = 0 ; suit < nbSuit ; suit++)
        {
	        //Create the card
            values.at(pos) = static_cast<Value>(value);
            suits.at(pos++) = static_cast<Suit>(suit);
        }
    }

    //Repeat as long as player cares to
    do
    {
        //Draw cards
        std::array<Value, CARDS_TO_DRAW> valuesDrawn;
        std::array<Suit, CARDS_TO_DRAW> suitsDrawn;

        //To avoid repeats we'll keep track of drawn cards
        std::array<int, CARDS_TO_DRAW> cardsDrawn
        { 0 * CARDS_TO_DRAW };

        for (int card = 0; card < CARDS_TO_DRAW; card++)
        {
            //grab a random valid number
            int cardToDraw;
            do
            {
                cardToDraw = rand() % CARDS;
            } while (inArray(cardToDraw, cardsDrawn));

            //Add the number to the drawn cards
            cardsDrawn.at(card) = cardToDraw;

            //Add the corresponding values and suit
            valuesDrawn.at(card) = values.at(cardToDraw);
            suitsDrawn.at(card) = suits.at(cardToDraw);
        }

        //Show the cards
        for (int card = 0; card < CARDS_TO_DRAW; card++)
        {
            printCard(valuesDrawn.at(card), suitsDrawn.at(card));
        }

        //print the hand's value
        printHandValue(valuesDrawn, suitsDrawn);

        // Ask to play again
	    std::cout << "Do you want to \"reshuffle\" and draw another hand?(y/n)" << std::endl;
        char answer;
        std::cin >> answer;
        if (answer != 'y')
        {
            break;
        }
    } while (true);

    std::cout << "That's not a \"y\" so no hand for you";
}