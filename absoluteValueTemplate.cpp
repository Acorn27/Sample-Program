// Chapter 16, Programming Challenge 4: Absolute Value Template
#include<iostream>
using namespace std;

// absoluteValue template
template <class T>
T absoluteValue(T number)
{
	return (number < 0) ? -number : number;
}

int main()
{
	// Two variables to experiment with...
	int num1 = 10;
	double num2 = -10.5;

	// Try the template with an integer.
	cout << "Absolute value of " << num1
	     << " is: " << absoluteValue(num1) 
		 << endl;

	// Try the template with a double.
	cout << "Absolute value of " << num2
	     << " is: " << absoluteValue(num2) 
		 << endl;

	return 0;
}
