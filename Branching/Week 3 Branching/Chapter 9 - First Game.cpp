// Create program that asks the player if they would like to play a game.
// If they do, then ask them a few questions before they can play. Ask them to enter their chosen username, ask them how old they are and what gender they are.
// From here, they have two guesses to guess a number between 1 - 10.
// If they are correct they win!

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main() {

	srand((unsigned)time(0));
	constexpr int k_play_choice = 1;
	constexpr int k_dont_play_choice = 2;

	cout << "==== WELCOME TO CONOR'S FIRST GAME ====" << endl;
	cout << "Would you like to play a game?" << endl;
	cout << "You have two choices, please enter 1 or 2: " << endl;
	cout << "1) Yes, I would love to play a game!" << endl;
	cout << "2) Not today, another time!" << endl;

	int input;
	cin >> input;

	switch (input)
	{
	case k_play_choice:
	{
		constexpr int k_male = 1;
		constexpr int k_female = 2;
		constexpr int k_other = 3;

		cout << "Great choice, before we play, please enter your name: ";
		string username;
		cin >> username;

		cout << "Welcome " << username << ", just a few more questions before we begin." << endl;

		cout << "Please confirm your gender by pressing 1, 2 or 3: " << endl;
		cout << "1) Male" << endl;
		cout << "2) Female" << endl;
		cout << "3) Other" << endl;

		int input_gender;
		cin >> input_gender;

		switch (input_gender)
		{
		case k_male:
		{
			cout << "Please enter how old you are: ";
			int age;
			cin >> age;

			if (age > 65)
			{
				cout << "Interesting, " << username << " is an old man!" << endl;
			}
			if (age < 65 && age > 25)
			{
				cout << username << " is a young man and has a few years left in him." << endl;
			}
			if (age < 25)
			{
				cout << username << " is just a baby boy!" << endl;
			}
			break;
		}
		case k_female:
		{
			cout << "Please enter how old you are: ";
			int age;
			cin >> age;

			if (age > 65)
			{
				cout << "Interesting, " << username << " is an old woman!" << endl;
			}
			if (age < 65 && age > 25)
			{
				cout << username << " is a young woman and has a few years left in her." << endl;
			}
			if (age < 25)
			{
				cout << username << " is just a baby girl!" << endl;
			}
			break;
		}
		case k_other:
		{
			cout << "Please enter how old you are: ";
			int age;
			cin >> age;

			if (age > 65)
			{
				cout << "Interesting, " << username << " is old!" << endl;
			}
			if (age < 65 && age > 25)
			{
				cout << username << " is a young and has a few years left in them." << endl;
			}
			if (age < 25)
			{
				cout << username << " is just a baby!" << endl;
			}
			break;
		}
		default:
		{
			cout << "Invalid option, please start again." << endl;
		}
		}

		cout << "Please now guess a number between 1 and 20: ";

		int winning_number = 1 + rand() % 20;
		cout << winning_number << endl;
		int guess;
		cin >> guess;
		if (guess == winning_number)
		{
			cout << "You win!" << endl;
			break;
		}
		if (guess > winning_number)
		{
			cout << "The number you have guessed is too high, try again!" << endl;
		}
		if (guess < winning_number)
		{
			cout << "The number you have guessed is too low, try again!" << endl;
		}
		int guess2;
		cin >> guess2;
		if (guess2 == winning_number)
		{
			cout << "You win!" << endl;
		}
		else
		{
			if (guess2 == winning_number)
			{
				cout << "You win!" << endl;
			}
			if (guess2 > winning_number)
			{
				cout << "The number you have guessed is too high, Game Over!" << endl;
			}
			if (guess2 < winning_number)
			{
				cout << "The number you have guessed is too low, Game Over!" << endl;
			}
		}
		break;
	}
		{
		case k_dont_play_choice:
		{
			cout << "See you next time!" << endl;
			break;
		}
		default:
		{
			cout << "Invalid input, we can try again later!" << endl;
			break;
		}
		}
	}
	system("pause>0");
	}