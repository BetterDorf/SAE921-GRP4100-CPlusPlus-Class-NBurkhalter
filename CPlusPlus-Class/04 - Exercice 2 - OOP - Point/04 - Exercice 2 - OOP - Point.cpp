#include <iostream>

#include  "Point.h"

using namespace std;

int main()
{
    Point p1;
    Point p2;

    cout << "First point:" << endl;
    p1.Set();
    cout << "Second point" << endl;
    p2.Set();

    cout << "Distance between points:" << endl;
    cout << p1.Distance(p2);

    if (p1 > p2)
    {
        cout << "P1 plus grand que p2" << endl;
    }

    cout << (p1 + p2).x << (p1 + p2).y;
}