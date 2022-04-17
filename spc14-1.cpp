// Chapter 14, Programming Challenge 1: Numbers Class
#include <iostream>
#include <string>
using namespace std;

// Declaration of Numbers class
class Numbers
{
private:
    int number;    // To hold a number

public:
    // Static arrays to hold words
    static string lessThan20[20];
    static string tens[9];
    static string hundred;
    static string thousand;
    
    // Constructor
    Numbers(int x){ number = x;}
   
    // Function to print the words for the number
    void print();
};

// Static member variables must be defined
// outside of the class 
string Numbers::lessThan20[20] = 
			 { "zero", "one", "two", "three", "four", "five",
			   "six", "seven ", "eight", "nine", "ten", 
			   "eleven", "twelve", "thirteen", "fourteen", 
			   "fifteen", "sixteen", "seventeen", "eighteen",
			   "nineteen", 
			 };

string Numbers::tens[9] = 
			{ "ten ", "twenty ", "thirty", "forty",
			  "fifty", "sixty", "seventy", "eighty", "ninety",
			};


string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

// *********************************************
// The print fucntion prints the English words *
// for the number                              *
// *********************************************

void Numbers::print()
{
    // Remainder holds what remains to be printed.
    int remainder = number;
	
    // Make sure the number is within range.
	if (remainder < 0 || remainder > 9999)
	{
		cout << "invalid input.";
	}
	else
	{
		cout << "The English description is:";

		if (number == 0)
		{
			cout << " zero";
		}

		// Take care of thousands, if any.
		int n_thousands = remainder / 1000;
		remainder %= 1000;

		if (n_thousands > 0)
		{
			cout << " " << lessThan20[n_thousands];
			cout << " " << thousand;
		}

		// Take care of hundreds, if any.
		int n_hundreds = remainder / 100;
		remainder %= 100;

		if (n_hundreds > 0)
		{
			cout << " " << lessThan20[n_hundreds];
			cout << " " << hundred;
		}

		// Take care numbers less than a 100.
		if (remainder >= 20)
		{
			int n_tens = remainder / 10;
			remainder %= 10;

			if (n_tens > 0)
				cout << " " << tens[n_tens];
		}

		if (remainder > 0)
		{
			// Take care of anything less than 20
			cout << " " << lessThan20[remainder];
		}
	}

	// Skips a few lines.
	cout << endl << endl;
}

// Demo program
int main()
{
   int number;
   
    // Display the program description.
   cout << "This program translates whole dollar amounts\n"
	    << "in the range 0 through 9999 into an English\n"
	    << "description of the number.\n\n";

	// Get input from the user.
	cout << "Enter a whole dollar amount: ";
	cin >> number;
    
	// Create a Numbers object.
	Numbers n(number);
        
	// Print the English description.
	n.print();

    return 0;
}