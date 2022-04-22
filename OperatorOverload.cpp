/*
There are 3 way to display class private memeber data (up to now): 

  + display using get memberfunction: too slow and inefficient, although it can passed to cout function
  
  
  + display using operator << overload (Note that reference sign is extremely important
    + First declare a friend function inside class. Format: friend ostream& operator<<(ostream&, const className&);
    + Seconnd write the defition for over load functin
    + Samle:
    ostream& operator<<(ostream &strm, const Height& obj) {
      strm << obj.feet << " feet, " << obj.inches << " inches\n";
      return strm
    }
    
    
+ Declare a friend function that passed in object. 
  friend void display(const Height&) ; don't forget void
  void display(const Height& obj) {
    cout  << obj.feet << " feet, " << obj.inches << " inches\n";
  }
  
  
  
  OVERLOAD CIN
  Inside class:
  friend istream& opeeator>>(istream&, Height&);
  outside class:
  istream& operator>>(istream& strm, Height& obj) {
    cout << "Feet: ";
    strm >> feet;
    cout << "Inches: ";
    strm >> inches;
    
    return strm;
  }
*/

#include <iostream>
using namespace std;

class Height {
private:
	int feet;
	int inches;
public:

	Height() {
		feet = 5;
		inches = 8;
	}

	// overload constructor
	Height(int f, int i) {
		feet = f;
		inches = i;
	}


	// overload cout
	friend ostream& operator<<(ostream&, const Height&);

	// overload cin
	friend istream& operator>>(istream&, Height&);
};

istream& operator>>(istream& strm, Height& obj) {

	// Prompt the user for input
	cout << "Feet: ";
	strm >> obj.feet;
	cout << "Inches: ";
	strm >> obj.inches;

	return strm;

}

// overload operator
ostream& operator << (ostream& strm, const Height& obj) {

	strm << obj.feet << " feet, " << obj.inches << " inches.\n";
	return strm;
}

int main() {

	Height studentA, studentB(5, 9);

	cout << studentA;
	cout << studentB;

	cout << "studentA: \n";
	cin >> studentA;
	cout << "Student B: \n";
	cin >> studentB;

	cout << studentA;
	cout << studentB;
}

// SAMPLE PROGRAM BELOW



#ifndef FEETINCHES_H 
2#define FEETINCHES_H 
3 
4#include <iostream> 
5using namespace std; 
6 
7class FeetInches; // Forward Declaration 
8 
9// Function Prototypes for Overloaded Stream Operators 
10ostream &operator << (ostream &, const FeetInches &); 
11istream &operator >> (istream &, FeetInches &); 
12 
13// The FeetInches class holds distances or measurements 
14// expressed in feet and inches. 
15 
16class FeetInches 
17{ 
18private: 
19   int feet;         // To hold a number of feet 
20   int inches;       // To hold a number of inches 
21   void simplify();  // Defined in FeetInches.cpp 
22public: 
23   // Constructor 
24   FeetInches(int f = 0, int i = 0) 
25     { feet = f; 
26       inches = i; 
27       simplify(); } 
28 
29   // Mutator functions 
30   void setFeet(int f) 
31    { feet = f; } 
32 
33   void setInches(int i) 
34    { inches = i; 
35     simplify(); } 
36 
37   // Accessor functions 
38 
39   int getFeet() const 
40    { return feet; } 
41 
42   int getInches() const 
43    { return inches; } 
44 
45   // Overloaded operator functions 
46   FeetInches operator + (const FeetInches &);  // Overloaded + 
47   FeetInches operator − (const FeetInches &);  // Overloaded − 
48   FeetInches operator ++ ();                   // Prefix ++ 
49   FeetInches operator ++ (int);                // Postfix ++ 
50   bool operator > (const FeetInches &);        // Overloaded > 
51   bool operator < (const FeetInches &);        // Overloaded < 
52   bool operator == (const FeetInches &);       // Overloaded == 
53 
54   // Friends 
55   friend ostream &operator << (ostream &, const FeetInches &); 
56   friend istream &operator >> (istream &, FeetInches &); 
57}; 
58 
59#endif 
60
