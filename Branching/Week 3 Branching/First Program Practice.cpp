// Create program that asks the player if they would like to play a game.
// If they do, then ask them a few questions before they can play. Ask them to enter their chosen username, ask them how old they are and what gender they are.
// From here, they have two guesses to guess a number between 1 - 10.
// If they are correct they win!

#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main() {

	constexpr int k_play = 1;
	constexpr int k_dont_play = 2;

	cout << "==== Welcome to Conor's Second Game Practica ====" << endl;
	cout << "Would you like to play a game?" << endl;
	cout << "Please select from the following options by pressing 1 or 2 and then enter:" << endl;
	cout << "1) Yes I would like to play" << endl;
	cout << "2) No thank you" << endl;

	int input;
	cin >> input;

	switch (input)
	{
	case k_play:
	{
		srand(unsigned(time(0)));
		constexpr int k_male = 1;
		constexpr int k_female = 2;
		constexpr int k_other = 3;

		cout << "Before we begin, I would like to confirm a few things with you first." << endl;
		cout << "Please enter your username: ";
		string username;
		cin >> username;

		cout << "Nice to meet you " << username << "." << endl;
		cout << "Please confirm your gender by pressing 1, 2 or 3 and then enter: " << endl;
		cout << "1) Male." << endl;
		cout << "2) Female." << endl;
		cout << "3) Other." << endl;

		int input_gender;
		cin >> input_gender;

		switch (input_gender)
		{
		case k_male:
		{
			cout << "Next question, how old are you?";
			int age;
			cin >> age;

			if (age > 60)
			{
				cout << "You are an old boy" << endl;
			}
			if (age <= 60 && age >= 20)
			{
				cout << "Noted." << endl;
			}
			if (age < 20)
			{
				cout << "You are a young boy" << endl;
			}
			break;
		}
		case k_female:
		{
			cout << "Next question, how old are you?";
			int age;
			cin >> age;

			if (age > 60)
			{
				cout << "You are an old girl" << endl;
			}
			if (age <= 60 && age >= 20)
			{
				cout << "Noted." << endl;
			}
			if (age < 20)
			{
				cout << "You are a young girl" << endl;
			}
			break;
		}
		case k_other:
		{
			cout << "Next question, how old are you?";
			int age;
			cin >> age;

			if (age > 60)
			{
				cout << "You are old " << endl;
			}
			if (age <= 60 && age >= 20)
			{
				cout << "Noted." << endl;
			}
			if (age < 20)
			{
				cout << "You are young." << endl;
			}
			break;
		}

		default:
		{
			cout << "Invalid option, please try again.";
		}
		}

		cout << "Please guess a number between 1 and 20, you have two guesses to get it right.";
		int winning_number = 1 + rand() % 20;
		cout << winning_number;
		int guess1;
		cin >> guess1;

		if (winning_number == guess1)
		{
			cout << "Congratulations, you win!" << endl;
			break;
		}
		else
		{
			if (winning_number > guess1)
			{
				cout << "Your number was too low! Try again. " << endl;
			}
			if (winning_number < guess1)
			{
				cout << "Your number was too high! Try again. " << endl;
			}
		}
		cout << "You have one more attempt, please enter another guess: ";
		int guess2;
		cin >> guess2;

		if (winning_number == guess2)
		{
			cout << "Congratulations, you win!" << endl;
			break;
		}
		else
		{
			if (winning_number > guess2)
			{
				cout << "Your number was too low! Game over. " << endl;
				break;
			}
			if (winning_number < guess2)
			{
				cout << "Your number was too high! Game over. " << endl;
				break;
			}
		}
	}
	case k_dont_play:
	{
		cout << "Next time then!";
	}
	default:
	{
		cout << "You have entered an incorrect value, lets try again another time.";
	}
}
}


	