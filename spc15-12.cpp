// Chapter 15, Programming Challenge 12: Ship, CruiseShip, and CargoShip classes
#include <iostream>
#include <string>
using namespace std;

// Ship class
class Ship
{
private:
    string name;         // Ship name
    string yearBuilt;    // Year it was built

public:
    // Constructor
    Ship(string n, string y)
    {
        name = n;
        yearBuilt = y;
    }

    // Accessors
    string getName()
    { return name; }

    string getYearBuilt()
    { return yearBuilt; }

    // print function
    virtual void print()
    {
        cout << "Name: " << name << endl
             << "Year built: " << yearBuilt << endl;
    }
};

// CruiseShip class
class CruiseShip : public Ship
{
private:
    int passengers;		// Number of passengers

public:
    // Constructor.
    // Summary of arguments:
    //	n -- name
    //	y -- year built
    //	p -- number of passengers
    CruiseShip(string n, string y, int p) :
      Ship(n, y)
    {
        passengers = p;
    }

    // print function
    virtual void print()
    {
        cout << "Name: " << getName() << endl
             << "Maximum passengers: " << passengers << endl;
    }
};

// CargoShip class
class CargoShip : public Ship
{
private:
    int tonnage;	// Cargo tonnage

public:
    // Constructor.
    // Summary of arguments:
    //	n -- name
    //	y -- year built
    //	t -- tonnage
    CargoShip(string n, string y, int t) :
      Ship(n, y)
    {
        tonnage = t;
    }

    // print function
    virtual void print()
    {
        cout << "Name: " << getName() << endl
             << "Cargo capacity: " << tonnage << " tons"
             << endl;
    }
};

int main()
{
    // Create an array of Ship pointers, initialized with
    // the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("Lolipop", "1960"),
                       new CruiseShip("Disney Magic", "1998", 2400),
                       new CargoShip("Black Pearl", "1800", 50000)
                     };

    // Call each object's print function.
    for (int index=0; index < 3; index++)
    {
        ships[index]->print();
        cout << "----------------------------\n";
    }

    return 0;
}