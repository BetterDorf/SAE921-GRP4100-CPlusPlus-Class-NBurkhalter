#include <iostream>
#include "Sweet.h"

using namespace std;

int main()
{
    //set the sweets
    Sweet licorice("licorice", 100);
    Sweet gum("bubbleGum", 50);

    //Test the class
    gum.Buy(20);
    gum.Buy(40);
    gum.Restock(30);
    gum.Buy(60);
}