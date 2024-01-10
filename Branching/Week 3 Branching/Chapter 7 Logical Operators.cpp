// Write a program that asks the user to enter a number 
// The program should tell the user if the number is postive, negative, odd, even or a combination.

#include <iostream>

using namespace std;

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	bool is_even = number % 2 == 0;
	bool is_odd = !is_even;
	bool is_positive = number > 0;
	bool is_negative = number < 0;
	bool is_zero = !is_positive && !is_negative;
	bool is_non_zero = !is_zero;

	if (is_even && is_positive && is_non_zero)
	{
		cout << "The number you have entered is an even, positive, non zero number." << endl;
	}
	if (is_odd && is_negative && is_non_zero)
	{
		cout << "The number you have entered is an odd, negative, non zero number." << endl;
	}
	if (is_even && is_negative && is_non_zero)
	{
		cout << "The number you have entered is an even, negative, non zero number." << endl;
	}
	if (is_odd && is_positive && is_non_zero)
	{
		cout << "The number you have entered is an odd, positive, non zero number." << endl;
	}
	if (is_zero)
	{
		cout << "The number you have entered is zero" << endl;
	}
}