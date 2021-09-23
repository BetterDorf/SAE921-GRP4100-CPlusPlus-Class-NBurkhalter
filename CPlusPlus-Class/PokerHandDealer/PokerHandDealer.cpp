#include <iostream>
#include <string>
#include <array>
#include <ctime>

const int CARDS_TO_DRAW = 5;
int const CARDS = 52;

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

//return 0 for no straight 1 for straight and 2 for royal
int checkConsecutive(std::array<Value, CARDS_TO_DRAW> values)
{
    bool straight = true;
    int biggestNum = 0;
    //find biggest number once considering ace as the smallest
	for (int i = 0 ; i < CARDS_TO_DRAW ; i++)
	{
        if (static_cast<int>(values.at(i)) > biggestNum)
        {
            biggestNum = static_cast<int>(values.at(i));
        }
	}

    int loops = 0;
    do
    {
        straight = true;
        //search the number directly below it and repeat cards - 1 times
        for (int consecutiveNums = 1; consecutiveNums < CARDS_TO_DRAW; consecutiveNums++)
        {
            bool found = false;
            for (int i = 0; i < CARDS_TO_DRAW; i++)
            {
                if (biggestNum - static_cast<int>(values.at(i)) == 1)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                straight = false;
                break;
            }
            biggestNum -= 1;
        }
        if (straight)
        {
            //if we are on our second loop then ace is the biggest and this has potential for a royal flush
            if (loops == 1)
                return 2;
            return 1;
        }

        //if there's an ace in the loop, try again with 13 as biggest
        if (loops == 0)
        {
            bool found = false;
            for (int i = 0 ; i < CARDS_TO_DRAW ; i++ )
            {
	            if (values.at(i) == Value::Ace)
	            {
                    found = true;
		            break;
	            }
            }
            if (!found)
                return 0;
            biggestNum = static_cast<int>(Value::nbValues);
        }
    } while (loops++ < 1);

    //by default we consider nothing was found
    return 0;
}

void printHandValue(std::array<Value, CARDS_TO_DRAW> valuesDrawn, std::array<Suit, CARDS_TO_DRAW> suitsDrawn)
{
    std::cout << "----" << std::endl;
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
    int straight = checkConsecutive(valuesDrawn);

    //Check for straight flush and Royal 
    if (straight > 0 && flush)
    {
	    //Check for royal
        if (straight == 2)
        {
	        //ROYAL
            std::cout << "ROYAL FLUSH !!!!!!!" << std::endl;
        }
        else
        {
	        //Straight flush
            std::cout << "Straight Flush !!!!!!" << std::endl;
        }
        return;
    }

    //register the highest number of identical values
    int mostRepeats = 0;
    Value mostRepeatedValue;
    //loop over each card
    for (int i = 0 ; i < CARDS_TO_DRAW ; i++)
    {
        Value card = valuesDrawn.at(i);
        int repeats = 0;

        //check how many times that card occurs in the hand
	    for (int j = 0 ; j < CARDS_TO_DRAW ; j++)
	    {
		    if (card == valuesDrawn.at(j))
		    {
                repeats++;
		    }
	    }
        if (repeats > mostRepeats)
        {
            mostRepeats = repeats;
            mostRepeatedValue = card;
        }
    }

    if (mostRepeats == 5)
    {
		std::cout << "Technically the program didn't work but you cheated so that's only fair" << std::endl;
    }

    //Check if there is a four of a kind
    if (mostRepeats == 4)
    {
        //Straight flush
        std::cout << "Four of a kind !!!!!" << std::endl;
    }

    //check if there is a three-of-a-kind and register the bool second pair (full house)
    //register the second pair
    bool secondPair = false;
    for (int i = 0; i < CARDS_TO_DRAW; i++)
    {
        Value card = valuesDrawn.at(i);
        int repeats = 0;

        //make sure the card isn't the first pair/three/four of a kind
        if (card == mostRepeatedValue)
        {
	        continue;
        }

        //check how many times that card occurs in the hand
        for (int j = 0; j < CARDS_TO_DRAW; j++)
        {
            if (card == valuesDrawn.at(j))
            {
                repeats++;
            }
        }
        if (repeats == 2)
        {
            secondPair = true;
            break;
        }
    }

    //full house
    if (mostRepeats == 3 && secondPair)
    {
        std::cout << "Full House !!!!" << std::endl;
        return;
    }

    //check if a normal flush was achieved
    if (flush)
    {
        std::cout << "Flush !!!!" << std::endl;
        return;
    }

    //check for straight
    if (straight > 0)
    {
        std::cout << "Straight !!!" << std::endl;
        return;
    }

    //three of a kind
    if (mostRepeats == 3)
    {
        std::cout << "Three of a kind !!!" << std::endl;
        return;
    }

    //a pair and another pair
    if (mostRepeats == 2 && secondPair)
    {
        std::cout << "Two pairs !!" << std::endl;
        return;
    }

    //a pair
    if (mostRepeats == 2)
    {
        std::cout << "Pair !" << std::endl;
        return;
    }

    //if none of those, print the highest value
    int biggestNum = 0;
    for (int i = 0; i < CARDS_TO_DRAW; i++)
    {
        if (valuesDrawn.at(i) == Value::Ace)
        {
            biggestNum = static_cast<int>(Value::nbValues);
        }
        if (static_cast<int>(valuesDrawn.at(i)) > biggestNum)
        {
            biggestNum = static_cast<int>(valuesDrawn.at(i));
        }
    }
    std::cout << "Highest number : " << biggestNum + 1<< std::endl;
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