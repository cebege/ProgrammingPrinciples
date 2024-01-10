// Write a program that asks the user to asks the user to enter a positive number.
// If the number was positive, ask the user to enter another number that is not zero.
// If entered correctly, the program should display one number divided by the other and the result.

#include <iostream>

using namespace std;

int main() {
	float first_number;
	cout << "Enter a positive number: " << endl;
	cin >> first_number;

	if (first_number > 0)
	{
		cout << "Enter a second number: " << endl;
		float second_number;
		cin >> second_number;

		if (second_number != 0)
		{
			cout << first_number << "/" << second_number << " = " << (first_number / second_number) << endl;
		}
		else
		{
			cout << "The number you entered is zero, goodbye!" << endl;
		}
	}
	else
	{
		cout << "The number you entered is negative, goodbye!" << endl;
	}
}