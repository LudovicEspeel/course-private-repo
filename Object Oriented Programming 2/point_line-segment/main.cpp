#include <iostream>
#include "Point.h"
#include "LineSegment.h"

using namespace std;
using namespace Geometry;

int main()
{
    Geometry::Point point; // geen (), anders denkt compiler dat je functie point() wilt aanroepen
    //Point point;
    cout << "Point:" << point.getString() << endl; // . = member operator

    Point point1(1, 2); // argumenten zijn literals (vaste waardes) <-> variabelen/methode aanroep
    Point point2(5, 2);

    Point point3 = point1; // wat gebeurt er in C++ (<-> andere talen)? Memberwise copy!
    cout << "point 1: " << point1.getString() << endl;
    cout << "point 3: " << point3.getString() << endl;
    point3.setX(4);
    point3.setY(4);
    cout << endl;
    cout << "point 1: " << point1.getString() << endl;
    cout << "point 3: " << point3.getString() << endl;

    LineSegment segment1(1, 2, 2, 3);
    LineSegment segment2(point1, point2);
    cout << "Line segment 1: " << segment1.getString() << endl;
    cout << "Line segment 2: " << segment2.getString() << endl;

    return 0;
}