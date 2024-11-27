#include "Point.h"

namespace Geometry {
    // member initialize list:
    Point::Point(void) : x(0), y(0)
    {
    }

    // member initialize list, delegeren constructor (of constructor initializer list):
    /*Point::Point() : Point(0, 0)
    {
    }
    */

    // member initialize list:
    //Point::Point(int x, int y) : x(x), y(y)
    //{
    //}
    // voordeel: kort + variabelen eerst zetten vooraleer je erft van een klasse
    // nadeel: buiten een constructor, gewone methode-aanroep niet mogelijk

    // of: constructor body:
    Point::Point(int x, int y)
    {
        /*
        if(x < 0)
        {
            this->x = 0;  
        }
        else
        {
            this->x = x;
        }

        if(y < 0)
        {
            this->y = 0;  
        }
        else
        {
            this->y = y;
        }
        */

        // voorbeeld van DRY-code:
        setX(x); // aanroepen van gewone methodes zijn hier ook mogelijk
        setY(y);
    }

    /*
    Point::Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point::Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    */

    int Point::getX() const
    {
        //this->x = 4; // is niet mogelijk door const!
        return this->x;
    }

    int Point::getY() const
    {
        return this->y;
    }

    void Point::setX(int x)
    {
        if(x < 0)
        {
            this->x = 0;  
        }
        else
        {
            this->x = x;
        }
    }

    void Point::setY(int y)
    {
        if(y < 0)
        {
            this->y = 0;  
        }
        else
        {
            this->y = y;
        }
    }

    string Point::getString() const
    {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
}