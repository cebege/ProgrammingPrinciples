// Write a program that asks the user to input a number between 1 to 3.
// Once a number has been selected, the program will ask the user to enter another number to be run through a function.
// Each number 1, 2 and 3 will represents the following functions: 
// 1) check if a number is even.
// 2) check if a number is positive.
// 3) check if a number is a multiple of 7.

#include <iostream>

using namespace std;

int main() {
	cout << "Which of the following options do you want to proceed with: " << endl;
	cout << "1) Check if a number is even." << endl;
	cout << "2) Check if a number is positive." << endl;
	cout << "3) Check if a number is a multiple of 7." << endl;

	int input;
	cin >> input;

	switch (input)
	{
	case 1:
	{
		int number;
		cout << "Please enter a number: ";
		cin >> number;

		if (number % 2 == 0)
		{
			cout << "The number is even.";
		}
		else
		{
			cout << "The number is odd.";
		}
		break;
	}
	case 2:
	{
		int number;
		cout << "Please enter a number: ";
		cin >> number;

		if (number > 0)
		{
			cout << "The number is positive.";
		}
		if (number < 0)
		{
			cout << "The number is negative.";
		}
		else if (number == 0)
		{
			cout << "The number is zero.";
		}
		break;
	}
	case 3:
	{
		int number;
		cout << "Please enter a number: ";
		cin >> number;

		if (number % 7 == 0)
		{
			cout << "This number is a multiple of 7";
		}
		else if (number % 7 != 0)
		{
			cout << "This number is not a multiple of 7";
		}
		break;
	}
	default:
	{
		while (input > 3 || input < 1)
		{
			cout << "You have entered an incorrect number, please try again: ";
			cin >> input; // HOW DO I LOOP THIS BACK TO THE START?
		}
	}
	}
}