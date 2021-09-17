#include <iostream>
#include <random>

using namespace std;

int const ORC_HEALTH = 20;
int const THEO_HEALTH = 22;

int const MIN_ORC_DAMAGE = 1;
int const MAX_ORC_DAMAGE = 9;
int const WAAGHODDS = 10;

int const THEO_DAMAGE = 5;
float const DEFEND_EFFICIENCY = 0.7f;
int const POTION_HEAL = 3;

//Setup the random
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> attackDamageDist(MIN_ORC_DAMAGE, MAX_ORC_DAMAGE);
std::uniform_int_distribution<> percentDist(1, 100);

//from https://stackoverflow.com/questions/6486289/how-can-i-clear-console
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

bool do_waagh()
{
    return percentDist(gen) <= WAAGHODDS;
}

int theo_decision()
{
    int answer;

    while (true)
    {
        cout << "1: attaquer (1)\n2: se defendre (2)\n3: boire une potion (3)" << endl;
        cin >> answer;

        if (answer == 1 || answer == 2 || answer == 3)
        {
            return answer;
        }
    }
}

void show_status(float theoHealth, float orcHealth)
{
    cout << "-----\n|Theo a " << theoHealth << " points de vie" << endl
        << "et Grimgor en a " << orcHealth << "|\n-----" << endl;
}

int main()
{
    //initialize the healths
    float theoHealth = THEO_HEALTH;
    float orcHealth = ORC_HEALTH;

    bool win = false;
    bool defend = false;

    int damage = 0;
    // loop the turns
    do
    {
	    /// Orc's turn
        cout << "-----\nTour de Grimgor\n---" << endl;
        damage = attackDamageDist(gen);
        if (do_waagh())
        {
            cout << "Grimgor s'enrage !" << endl;
            damage *= 2;
        }

        //deal damage
        cout << "Grimgor attaque et inflige " << damage << " degats!" << endl;
        if (damage > 10)
        {
            cout << "Quelle violence!" << endl;
        }
        //check for defense
        if (defend)
        {
            //reduce damage if defended
            damage *= (1 - DEFEND_EFFICIENCY);
            defend = false;
            cout << "Mais Theobald s'est malheureusement defendu et n'a prit que "
                << damage << " degats" << endl;
        }
    	theoHealth -= damage;

        //check for death
        if (theoHealth <= 0)
        {
            win = false;
            continue;
        }

        /// Theo's turn
        show_status(theoHealth, orcHealth);
        // present option
        cout << "Tour de Theobald le peureux.\n---\nQue va-t-il faire?" << endl;
        int decision = theo_decision();

        //clear screen between turns
        Clear();

        //act
	    switch (decision)
	    {
        case 1 :
            //attack
            damage = THEO_DAMAGE;
            cout << "Theobald attaque et inflige " << damage << " degats!" << endl;
            orcHealth -= damage;

            // check for death
            if (orcHealth <= 0)
            {
                win = true;
                continue;
            }
            break;
        case 2 :
            //defend
            cout << "Fidel a sa reputation, Theobald se defend. Couard." << endl;
            defend = true;
            break;
        case 3:
            //heal
            cout << "Theobald sent qu'il va mourir et s'empresse d'engloutir une potion de soin." << endl;
            theoHealth += POTION_HEAL;
            cout << "Il recupere 3 points de vie" << endl;
            break;
	    }

    } while (theoHealth > 0 && orcHealth > 0);

    //show winner
    if (win)
    {
        cout << "Contre toutes attentes, Theobald l'emporte sur son adversaire pourtant plus meritant" << endl;
    }
    else
    {
        cout << "Ainsi s'acheve l'epopee de Theobald, terasse de la main de Grimgor. Tout le monde s'y attendait." << endl;
    }
}