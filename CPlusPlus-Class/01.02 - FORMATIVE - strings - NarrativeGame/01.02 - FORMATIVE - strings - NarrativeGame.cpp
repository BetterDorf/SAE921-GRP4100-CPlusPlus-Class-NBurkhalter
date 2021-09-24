#include <iostream>
#include <string>

using namespace std;

struct Data
{
    string placeholder;
    string value;
};

enum class Tool
{
    Grenade,
    Teleporter,
    Knife,
    UselessPlushie,
    None
};
enum class Knowledge
{
    Fighting,
    Physics,
    Politics,
    None
};

string replaceValue(string original, Data replacement)
{
    std::string thingToReplace = replacement.placeholder;
    std::string newPart = replacement.value;

    int pos = 0;
    while (true)
    {
        pos = original.find(thingToReplace);

        if (pos < 0 || pos >= original.length())
            break;

        original = original.replace(pos, thingToReplace.length(), newPart);
    }

    return  original;
}

#pragma region DataDeclaration

Data name;
Data birth_place;
Data date;
Data ship_type;
Data ship;
Data specie;
#pragma endregion

void printSpace()
{
    cout << "\n\n\n\n";
}

void pause()
{
    printSpace();
    string answer;
    cout << "(type any letter to continue)" << endl;
    cin >> answer;
    cout << endl;
}

//call replace value on all types of data
string overkillReplace(string original)
{
    original = replaceValue(original, name);
    original = replaceValue(original, birth_place);
    original = replaceValue(original, date);
    original = replaceValue(original, ship_type);
    original = replaceValue(original, ship);
    original = replaceValue(original, specie);

    return original;
}

int main()
{
    // re-usable variable to hold the user message
    string answer = "";
    //same for ints to use on switches
    int choice = 0;
#pragma region Data_initialisation
    //values to replace
    name.placeholder = "[Name]";
    birth_place.placeholder = "[Place]";
    date.placeholder = "[Date]";
    ship_type.placeholder = "[Ship_type]";
    ship.placeholder = "[Ship]";
    specie.placeholder = "[Specie]";
#pragma endregion

#pragma region Char_choice
    //Welcome the user
    std::cout << "As you drift aimlessly through space, a beeping light appears to remove you from your meaningless wanderings." << endl
        << "You have just received a mission from The Federation.\nThe very same one you swore to protect and blindly obey to many years ago." << endl
        << "But before we can get into your elaborate and probably edgy backstory, we first need to clarify one small detail: " << endl
        << "Who are you?" << endl << endl << endl;

    //present the characters and choice
    std::cout << "(1): Sarah Shepard, Born on planet Earth at 24/08/2087. Captain of the crusader ship The Explorer" << endl
        << "(2): Phil Spector, Born on planet Mars at 26/08/2038. Pilot of the H-Hunter n3434-DFG" << endl
        << "(3): Whifghy, the metamorph. Created  in Sector SD/F67. Child of the bioship Sxiot" << endl;

    do
    {
        cin >> choice;
    } while (choice < 1 || choice > 3);

    //Write the datas of the characters
    switch (choice)
    {
    default:
    case 1:
        name.value = "Sarah Shepard";
        birth_place.value = "Earth";
        date.value = "24 of august in 2087";
        ship_type.value = "crusader";
        ship.value = "The Explorer";
        specie.value = "human";
        break;
    case 2:
        name.value = "Phil Spector";
        birth_place.value = "Mars";
        date.value = "26 of august in 2038";
        ship_type.value = "H-Hunter";
        ship.value = "n3434-DFG";
        specie.value = "human";
        break;
    case 3:
        name.value = "Whilfghy";
        birth_place.value = "The Sector SD/F67";
        date.value = "[Redacted]";
        ship_type.value = "bioship";
        ship.value = "Sxiot";
        specie.value = "metamorph";
        break;
    }
#pragma endregion

#pragma region Intro
    //Confirm the chosen character
    string message = "Of course, you are [Name]. This unnamed narrative game would never forget such a name."
        "\nAfter today, neither will the rest of the universe";
    cout << replaceValue(message, name) << endl;

    printSpace();

    //intro
    message = "Right now, a blue light is blinking on and off on the console of the [Ship_type].\nYou check the monitor and surely enough,"
        " lines describing a mission begin to appear on the screen.\n"
        "They are vague at best, something shady is going to be asked of you from the federation,\nbut your morals were on vacation anyway.\n"
        "For now, all you have to do is to infiltrate a base orbiting near [Place].\nIt should be easy enough, especially since "
        "only [Specie]s lives there and you're one of them.\nConsidering the fact that [Species]s are nearly extinct, "
        "it is an incredible coincidence.\nConsidering [Place] is where you were born and grew up and that the Federation knows that,\n"
        "this scenario isn't too exceptional."; 

    //Character can't decline the mission
    cout << "The terminal is waiting for an input, it says:" << endl;
    message = replaceValue("[Name], will you accept the mission? (y)", name);
    do
    {
        cout << message << endl;
        cin >> answer;
    } while (answer != "y");
    cout << "You never really considered saying no to these missions. The fact that there is no \"decline\" button is a big factor.\n"
        "This doesn't really bother you though, since you already swore loyalty until death to the Federation" << endl;
#pragma endregion

    //chapters
    Tool tool;
    Knowledge knowledge;

#pragma region Chapter1_Voyage_TODO
    //title
    printSpace();
    cout << "Chapter 1 - Preparations";
    pause();

    //description
    message = "After willfully accepting the mission, you enter the coordinates.\nBy hand.\nFor some reason, there's no technology that "
        "automatically does that.\nSo you painfully type in all 67 space-characters one-by-one.\n"
        "After a while, you can finally turn the engine on. A nice whirring noise starts to gather in the cockpit.\n"
        "Your ship, [Ship] is old but works exceptionally well for a [Ship_type] his age.\n"
		"The ancient engine starts to vibrate out of existence and with it, the ship.\nAs the hull and everything in it start to fade,"
		" the stars outside become visible through it but appear blurry.\nA great FWOOOOMP sound echoes in the [Ship_type] as you enter"
		" a huge corridor of light.\nThe federation's fastest means of travel.\nIt will still take the better part of this year, so"
		" you better hop into cryosleep as soon as you can.\n\nWell maybe there is a thing or two that you could do before that...";
    cout << overkillReplace(message);

    printSpace();

    //prepare stuff for next chapters
    //Order a tool
    message = "Since it takes so long to travel and that you're currently in a safe \"space\"\n"
		"(you don't actually know if what you are currently in qualifies as space)\n"
		"you should order a special tool that would arrive in the same timeframe as you, if not a bit behind.\n\n"
		"You open your laptop to check on THE DARK NET (trademarked) for what they have in store.\n\n"
		"WELCOME [Name] TO THE DARK NET (trademarked)\nTO REWARD YOUR FIDELITY YOUR NEXT PURCHASE WILL BE ENTIRELY FREE (EXCLUDING DELIVERY)\n\n"
		"Well, that's convenient.\nNow, what do we want to get?\n\n"
		"(1) SPACE-WARP GRENADE\n(2) SHORT-RANGE TELEPORTER (ONE-USE ONLY)\n(3) STRANGE-MATTER KNIFE\n (4) PLUSHIE OF A PIG MADE OUT OF SALAD\n"
		"(5) NOTHING, I AM TOO DUMB TO SHOP HERE";
    cout << replaceValue(message, name) << endl;
    cin >> choice;

    // Record the user's choice
    switch (choice)
    {
	    case 1: cout << "SPACE WARPING GRENADE ORDERED. DELIVERY WITHIN ONE (1) BUSINESS YEAR" << endl;
	        tool = Tool::Grenade;
	        break;
	    case 2: cout << "SHORT-RANGE TELEPORTER ORDERED. DELIVERY WITHIN ONE (1) BUSINESS YEAR" << endl;
	        tool = Tool::Teleporter;
	        break;
	    case 3: cout << "EXTREMELY UNSTABLE KNIFE WITH STRANGE MATTER BLADE ORDERED. DELIVERY WITHIN ONE (1) BUSINESS YEAR" << endl;
	        tool = Tool::Knife;
	        break;
	    case 4: cout << "INCREDIBLY USELESS PLUSHIE ORDERED. DELIVERY WITHIN ONE (1) BUSINESS YEAR" << endl << "WHY DO WE SELL THOSE?" << endl;
	        tool = Tool::UselessPlushie;
	        break;
	    case 5:
	    default:
            cout << "NOTHING WAS ORDERED... YOU MUST BE DAFT" << endl;
	        tool = Tool::None;
	        break;
    }

    //Exit the space shop
    cout << "THANK YOU FOR SHOPPING AT DARKNET (trademarked)." << endl;

    //end the chapter

#pragma endregion

#pragma region Chapter2_Infiltration_TODO
    //title
    printSpace();
    cout << "Chapter 2 - Infiltration";
    printSpace();

    //Description of the base

    //Sneak docking

    //Find suit

    //Explore the different spots
#pragma endregion

#pragma region Chapter3_Sedentarity_TODO
    //title

    //Befriend people there

    //Few years pass

    //Finally, a transmission
#pragma endregion

#pragma region Chapter4_Action_TODO

#pragma endregion

#pragma region Chapter5_Conclusion_TODO

#pragma endregion
}