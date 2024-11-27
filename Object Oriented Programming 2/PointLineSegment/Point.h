#pragma once // is niet gestandaardiseerd, maar geaccepteerd in veel compilers
//is gestandaardiseerd, nadeel: unieke naam kiezen over heel je project
//#ifndef POINT_H
//#define POINT_H

#include <string>
using namespace std;

namespace Geometry {
    class Point
    {
        // attributen: instantievariabelen
        private: // access modifier
            // let op: in C++ niet standaard 0, best initialiseren
            // ofwel in parameterloze constructor
            int x = 0;
            int y = 0;

        // attributen: constructoren en methodes
        public: // access modifier
            // constructor: zelfde naam als klasse, geen return type!
            // wordt als eerste aangeroepen!

            // parameterloze constructor 
            //(hoef je zelf niet te schrijven indien je geen enkel andere constructor hebt)
            //(en je tevreden bent met de default waardes van de attributen)
            Point(void);
            Point(int x, int y); // overload constructor
            Point(int x)
            {
                this->x = x; // inline constructor/methode
            }

            // getters (heeft geen argumenten, maar return type):
            // good practice: functie const maken (moet ook gebeuren in cpp)!
            int getX() const;
            int getY() const;

            // setters (heeft argumenten, maar geen return type):
            void setX(int x);
            void setY(int y);

            // andere methodes:
            // good practice: methodes die niets van attributen mogen zetten in klasse, 
            // best ook const zetten
            string getString() const;
    };
}

//#endif