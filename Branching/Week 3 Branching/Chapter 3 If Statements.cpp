// Create a program that asks the user to enter a number.
// The program should tell the user if the number is positive, negative or equal to zero.
// The program should also tell the user if the number is odd or even.

#include <iostream>

using namespace std;

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << boolalpha;

	if (number > 0)
	{
		cout << "The number is positive." << endl;
	}

	if (number < 0)
	{
		cout << "The number is negative." << endl;
	}

	if (number == 0)
	{
		cout << "The number is zero." << endl;
	}

	bool even = (number % 2 == 0);

	if (even)
	{
		cout << "The number is even" << endl;
	}
	else
	{
		cout << "The number is odd" << endl;
	}

}