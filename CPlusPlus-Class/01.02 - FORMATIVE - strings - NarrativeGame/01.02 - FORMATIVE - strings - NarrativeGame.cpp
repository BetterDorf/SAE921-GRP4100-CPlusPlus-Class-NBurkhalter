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

enum class Friend
{
	Scientist,
    Soldier,
    Rando,
    Lead_Scientist,
    None
};

enum class Plan
{
	guards,
    teleporter,
    rig,
    sneak,
    none
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
    string answer;
    cout << "(type any letter to continue)" << endl;
    cin >> answer;
    cout << endl;
}

void chapter(string chapter_message)
{
    printSpace();
    cout << chapter_message;
    printSpace();
    pause();
    printSpace();
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
#pragma region Data_initialisation
    // re-usable variable to hold the user message
    string answer = "";
    //same for ints to use on switches
    int choice = 0;

    //values to replace
    name.placeholder = "[Name]";
    birth_place.placeholder = "[Place]";
    date.placeholder = "[Date]";
    ship_type.placeholder = "[Ship_type]";
    ship.placeholder = "[Ship]";
    specie.placeholder = "[Specie]";
#pragma endregion

    //Loop as long as player didn't win and wants to keep playing
	while (true)
	{
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
	            "\nAfter this mission, neither will the rest of the universe";
	        cout << replaceValue(message, name) << endl;

	        printSpace();

	        //intro
	        message = "Right now, a blue light is blinking on and off on the console of the [Ship_type].\nYou check the monitor and surely enough,"
	            " lines describing a mission begin to appear on the screen.\n"
	            "They are vague at best, something shady is going to be asked of you from the federation,\nbut your morals were on vacation anyway.\n"
	            "For now, all you have to do is to infiltrate a base orbiting near [Place].\nIt should be easy enough, especially since "
	            "only [Specie]s lives there and you're one of them.\nConsidering the fact that [Specie]s are nearly extinct, "
	            "it is an incredible coincidence.\nConsidering [Place] is where you were born and grew up and that the Federation knows that,\n"
	            "this scenario isn't too exceptional.";

	        cout << overkillReplace(message);
	        printSpace();

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

	#pragma region Chapter1_Voyage
		//title
        chapter("Chapter 1 - Preparations");

        //description
        message = "After willfully accepting the mission, you enter the coordinates.\nBy hand.\nFor some reason, there's no technology that "
            "automatically does that.\nSo you painfully type in all 67 space-characters one-by-one.\n"
            "After a while, you can finally turn the engine on. A nice whirring noise starts to gather in the cockpit.\n"
            "Your ship, [Ship], is old but works exceptionally well for a [Ship_type] his age.\n"
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
            "(1) SPACE-WARP GRENADE\n(2) SHORT-RANGE TELEPORTER (ONE-USE ONLY)\n(3) QUANTUM KNIFE\n(4) PLUSHIE OF A PIG MADE OUT OF SALAD\n"
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
        case 3: cout << "EXTREMELY UNSTABLE KNIFE WITH QUANTUM BLADE ORDERED. DELIVERY WITHIN ONE (1) BUSINESS YEAR" << endl;
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
        printSpace();

        //end the chapter
        cout << "That should be enough.\nYou close your laptop and head to the cryosleep chamber.\nIt's a cold, empty chamber with the exception "
            "of the metal pod sitting at the center of it.\nIt is remarkably colder inside this room but the cryobed itself is far colder.\n"
            "We would elaborate on this description with all the inner workings of this remarkable technology but you've already hopped into the pod,\n"
            "so need to move along quickly.\nA blue gas comes rushing in from tubes all around as you slip out of consciousn...";
	#pragma endregion

		bool gameOver = false;

	#pragma region Chapter2_Infiltration
        //title
        chapter("Chapter 2 - Infiltration");

        //Description of the base
        message = "We can take the opportunity, while [Name] is asleep, to skip ahead quite a bit and take a look at this station.\n"
            "Shifting our focus out of the [Ship_type], we can zoom across a few lightyears worth of mostly empty space to arrive instanteanously.\n"
            "Truly, this is a huge station, it can and does provide for a million [Specie]s as it loosely orbit [Place] from quite a distance.\n"
            "This station is dull metallic white (courtesy of the local asteroids that were used in its construction) and resembles a web of corridors\n"
            "meeting at large spherical rooms.\n"
            "As outside observers, we could reason a guess that this is a very advanced [Specie] research\n"
            "belonging to the most well-known WEAPON SELLER operating outside the federation.\n"
            "What we can't possibly guess is that it is currently working on harnessing the full potential of black hole technology.";
        cout << overkillReplace(message) << endl;

        //Sneak docking
        printSpace();
        message = "With a very loud sound that would be heard from far away if it were not for the vacuity of space, "
            "[Ship] and you emerge from the interstellar travel\nYour sensors spot the station and you deduce from its image much of what we described above\n"
            "\nYou must now decide on a course of action to safely and discretely board the station.";
        cout << replaceValue(message, ship) << endl;

        do
        {
            cout << "(1) : Calculate an optimal docking trajectory and disable all systems afterwards to avoid detection.\n"
                "(2) : Eject yourself with just a suit while your ship stays out of the station's sensors' range.\n"
                "(3) : Hope your ship's scramblers are enough.\n"
                "(4) : Just dock, maybe they are friendly." << endl;
            cin >> choice;
        } while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1:
            cout << overkillReplace("You turn off the power in your ship after sending it on its way to the docking area.\n"
                "It is not exactly clear how you will initiate the docking procedure without any power and at this rate, you'll just crash into the hangar.\n"
                "You decide to just bail out of your [Ship_type] before it collides. You put on your personal suit and with your jetpack,\n"
                "manage to close the distance and land in the hangar. Sadly, [Ship] does the exact same as you but without the landing part.\n"
                "A big explosion takes out everything in the hangar which would amount to exactly 2 mining ships and 7 [Specie]s including you.") << endl;
			gameOver = true;
			break;
		case 2:
			cout << overkillReplace("You decide that for a stealthy approach, it is best to leave [Ship] as it is a bit too big for a stealthy, controlled approach.\n"
				"You put on your suit, which is quite a tight fit, and exit the [Ship_type] to find yourself in Space with a capital S.\n"
				"As an added bonus, you get a pretty nice view of all of [Place] from there. After taking the time necessary to enjoy the scenery,\n"
				"you turn on your thruster on you jetpack and start propelling yourself towards the station.\n"
				"One would think that it is incredibly hard to get a [Specie] unnoticed onto such a station.\n"
				"One would be very wrong since they didn't factor the fact that this particular [Specie] did this a lot in their lifetime.\n"
				"It's as simple as landing smoothly in the hangar and saying hi to the other [Specie]s there.\n"
				"The key here, is to behave as if you were meant to be there and no one will ask any question.\n"
				"They'd be too afraid of looking dumb in front of someone clearly important, which [Name] clearly is.") << endl;
			break;
		case 3: 
			cout << overkillReplace("Technologically speaking, [Ship] is quite advanced. But we have to be honest, some corners were cut.\n"
				"And the scramblers aren't really state of the art. So, when a few missiles appear on your radar, heading your way, you're really not surprised.")
	        	<< endl;
			gameOver = true;
			break;
		case 4: cout << "They weren't. They shoot at you with all the might of a militarized research station. You die." << endl;
			gameOver = true;
			break;
        }

        if (gameOver)
        {
			continue;
        }

        printSpace();

        //Find suit
        message = "Now that you are on this station, you should try to blend in more,\n"
            "your bright yellow spacesuit isn't going to cut it if anyone compares it to the local dress code.\n"
			"Fortunately, you find yourself wandering, by sheer luck, into a storage where extra suits are kept.\n"
			"The name plate on of them is left empty, how convenient. Now it's just a matter of doing not too crude of a job laser-cutting your own name\n"
			"and you were doing that on your house's wall since you were five, so you're pretty much an expert at it.\n\n"
			"Annnnd... done!\n"
			"Property of [Name]\n"
			"This should help you maintain your cover while you wait for more instructions.";
        cout << replaceValue(message, name) << endl << "The import part is now: You could dye the suit to make it more personal.\n"
			"Which color do you want? (Any 1 word)" << endl;
        cin >> answer;
        cout << "That is...\nNot a great choice.\nBut you won't do it anyway since the only allowed color on this station seems to be the default green\n"
            "Oh well." << endl;

        printSpace();

        //Explore the different spots
        cout << replaceValue("Now that you are correctly suited, you wander around the station, subtly inquiring about its inner workings.\n"
			"You find out where the scientists live, where the more military [Specie]s go to train and more importantly:\n"
			"The cafeteria and its infinite refill policy on tea\n"
			"(which you are very keen of, especially licorice. It's a fantasy, I can tell you what you like and what you don't).\n"
			"You also discover where most of the experiences happen. For now, the access is too restricted for you to get inside\n"
			"but from what you could gather, they are trying to maximize the energy output of a \"Black hole energy generator\".", specie) << endl;
	#pragma endregion

        Friend best_friend;

	#pragma region Chapter3_Sedentarity
        chapter("Chapter 3 - Sedentarity");

	    //Befriend people there
        cout << "You're starting to get your marks around the station. It has been a few day and you've managed to pass yourself off as a janitor.\n"
			"This ingenious move allowed to swiftly recover whatever it was that you ordered from the DARKNET (trademarked), if anything.\n"
			"You learn some more about the people living there and who could be useful in what context:\n"
			"The soldiers are the plain ol' security of the place, and having ties to one would be a great boon to get around said security.\n"
			"The scientists are the people directly involved with the most interesting thing this station has to offer: The black hole project.\n"
			"You heard that the lead scientist was actually very fond of rare collectibles such as posters, plushies and antique books (which all books are)."
			<< endl;

        printSpace();

	    //Few years pass
        cout << "It now has been quite a while, a year or two, you still haven't received that transmission from the Federation.\n"
            "But you didn't sit idle all this time.\n"
			"You took the opportunity to befriend one of the the people you regularly see at the cafeteria:" << endl;

        do
        {
            cout << "(1) Elena Volt : Physicist working on the black hole project\n"
                "(2) Kar Kat : SOLDIER WHO ONLY SPEAKS IN CAPS LOCK\n"
        		"(3) Joe Boso : A janitor like you, except he's actually a janitor.\n"
        		"(4) Niou Ton : A very excentric scientist that leads the research on the black hole project."
        		<< endl;

            cin >> choice;
        } while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1: cout << "You eventually bonded with one the physicist that works on the main attraction: The black hole.\n"
	        	"You bonded with her over stories of the hardships she encountered during the testing and the various data discrepancies\n"
	        	"while you regaled her with epic tales of how a wet puddle simply refused to dry out.\n"
	        	"In a different context, you might have actually ended up being friends with her, but you have to remind yourself that this is a job.\n"
	        	"The fact that you don't have to fake it as much just makes it easier...\n"
	        	"+Friend: Elena" << endl;
            best_friend = Friend::Scientist;
            break;
        case 2: 
            cout << "It was quite easy to get on the good side of Kar as he is quite talkative and tends to appreciate anyone who listens to him\n"
                "until the end of a conversation. You find it a bit sad, but it proves extremely useful in this scenario.\n"
	        	"The other advantage, is that this friend never sneaks up on you since he ALWAYS LOUDLY ANNOUNCES HIS PRESENCE.\n"
	        	"Not the stealthiest ally, but a well-meaning one.\n"
	        	"+FRIEND: Kar Kat" << endl;
            best_friend = Friend::Soldier;
            break;
        case 3:
            cout << "Joe is a cool kind of guy. Sadly for a description-based game, he is also the kind of guy that never talks about himself\n"
	        	"In two years, you didn't learn much more about him than his name, occupation and where he likes cleaning the most.\n"
	        	"+Friend?: Joe" << endl;
            best_friend = Friend::Rando;
            break;
        case 4:
            cout << "It is easy to tell apart the lead scientist from a crowd, he's the only one in a full-purple suit.\n"
	        	"You go over to him and start smooth-talking. It doesn't really work, seems like you can't get to him." << endl;
            if (tool == Tool::UselessPlushie)
            {
                cout << "You decide to change your approach and on the second day you meet him, you drop the bad boy on the table:\n"
                	"A hand-made plushie of a cute salad-pig.\n"
                	"He is taken aback, shocked, incredulous, flabbergasted. He had been looking for it for a while now.\n"
                	"You give it on the condition that he talks to you about the black hole project.\n"
                	"This turns out to be the right move as he is so enthusiastic about it, it even makes you enthusiastic about it.\n"
                	"Even though you understand exactly none of it.\n"
                	"You continue meeting each other at the cafeteria for a while after that. Until you eventually become analogous to\n"
                	"a rubber duck in these conversations, just a way to talk things out. But you appreciate those moments a lot as it allows\n"
                	"to glimpse into the passion of a brilliant mind.\n"
                	"He occasionally even manages to make you assist to some tests, which looks unimpressive.\n"
                	"But according to the readings, this generates several orders of magnitude more energy than any other current technology.\n"
                	"His goals are purely utopist, completing this would allow near-unlimited resources for civilizations to thrive on.\n"
                	"Of course, one doesn't have to be a genius to realize this could also be turned into a bomb really easily.\n"
                	"+Friend: Niou Ton" << endl;
            }
            else
            {
                cout << "After two years, he still doesn't show any sign of sympathy towards you.\n"
                	"Perhaps you didn't pay attention enough during manipulation classes." << endl;
                best_friend = Friend::None;
                break;
            }
        }

        printSpace();

	    //Finally, a transmission
        cout << overkillReplace("Another year pass without too much happening. Day-to-day life isn't too exciting, but you poorly chose your cover job, so that's on you.\n"
			"Then, out of nowhere, your watch start vibrating discretely.\n"
			"You check it and see the verification code for a high-security message from the Federation.\nFinally.\n\n"
			"[Name], you are to blow up the station orbiting [Place],\n"
			"failing to do that, dispose of the lead scientist, Niou Ton,\n"
			"failing to do that, destroy the black hole project,\n"
			"do not fail further.\n"
			"Good luck,\n"
			"The Federation\n"
			"XOXO\n"
			"PS:\n"
			"Disregard the last line, it was suggested automatically and this is just my first day as operator,\n"
            "Also, I forgot to write it in the mission brief but YOU MUST take the schematics for the station BEFORE blowing up everything.\n"
			"thank you!\n") << endl;
        cout << "You aren't known to fail missions, so it's just a matter of how you'll do it." << endl;
	#pragma endregion

        Plan plan = Plan::none;

	#pragma region Chapter4_Plan
        chapter("Chapter 4 - Plan");

        //Decision on course of action
        cout << replaceValue("What course of action will [Name] take?", name) << endl;
        do
        {
            do
            {
                cout << "\n(1) : Inform the guards that something dangerous will happen on a certain date so that they are away from the main research project.\n"
                    "(2) : Teleport yourself in the schematics room, then out and figure something out to sabotage the generator so that it blows up.\n"
                    "(3) : Use your special grenade to blow up the station after having stolen the schematics.\n"
                    "(4) : Just sneak in like you normally do, steal the plan, blow up the place." << endl;
                cin >> choice;
            } while (choice < 1 || choice > 5);

            switch (choice)
            {
            case 1:
                // Check that scenario is possible
                if (best_friend != Friend::Soldier)
                {
                    cout << "The soldiers don't really believe you." << endl;
                    break;
                }

                cout << "You entrust your buddy, who just so happens to work as a guard for the big project, with critical information regarding...\n"
                    "A vague threat?\n"
                    "You really don't know what to tell him, but he sorts of fill-in the blanks and ALERT HIS ENTIRE SQUADRON OF THE DANGER.\n"
                    "This should make it easier." << endl;
                plan = Plan::guards;
                break;
            case 2:
                //check for tool
                if (tool != Tool::Teleporter)
                {
                    cout << "You don't own a teleporter, how are you planning on teleporting around without it?" << endl;
                    break;
                }

                cout << "This short-range teleporter is great and all, but it was poorly coded, it only uses a single reference frame.\n"
                    "And since it hasn't been changed from the day of its conception, you'll have to do it yourself. Can't be too hard.\n"
                    "But what do all of these numbers mean?" << endl;

                //check for friend
                if (best_friend != Friend::Scientist)
                {
                    cout << "Despite your best efforts, you couldn't manage to calibrate the device, it's simply too complex for you.\n"
                        "To add to your disappointment, no one you know has both the time and the knowledge to help you calibrate it.\n"
                        "In its current state, using it for even a short teleportation would land you practically anywhere around the station.\n"
                        "The odds of killing yourself with it are just to great." << endl;
                    break;
                }

                cout << "Luckily, your friend Elena has some spare time. You frame these equations as \"recreational exercises\". She's happy to help\n"
                    "With her at your side, despite her insistence on \"not revealing the solution\", you manage to crack it!\n"
                    "Walls are now a mere suggestion.\n"
                    "A shame she has to blow up too." << endl;
                plan = Plan::teleporter;
                break;
            case 3:
                // check for the item
                if (tool != Tool::Grenade)
                {
                    cout << "Well you don't really have a cool space warping grenade that could do that, now do you?" << endl;
                    break;
                }

                cout << "This will work perfectly. Since the grenade has a bit of an arming time, you set it up underneath the generator.\n"
                    "It beeps slightly and you can feel gravity shifting around it. How cool." << endl;
                plan = Plan::rig;
                break;

            case 4:
                //always works
                cout << "Yes, the usual approach should work, you'll just sneakily advance, probably in the vents, then you'll complete the objective.\n"
                    "Simple." << endl;
                plan = Plan::sneak;
                break;
            }

        } while (plan == Plan::none);

        cout << "Now you're ready." << endl;
	#pragma endregion

	#pragma region Chapter5_Action_TODO
	        chapter("Chapter 5 - Action");
	#pragma endregion

	#pragma region Chapter6_Conclusion_TODO

	#pragma endregion

	#pragma region GameOver
	        //End the game and ask if they want to play again
	        printSpace();
	        cout << "You died.\n(Or had a sort of similar fate, i.e. you lost)\nDo you want to play again?(Y/N)" << endl;
	        cin >> answer;
	        if (answer != "Y")
	        {
	            break;
	        }
	#pragma endregion
	}
}