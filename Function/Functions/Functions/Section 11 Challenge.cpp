#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {

	vector <int> numbers{};
	char selection;

	do
	{
		cout << "P - Print" << endl;
		cout << "A - Add" << endl;
		cout << "M - Mean" << endl;
		cout << "L - Largest" << endl;
		cout << "S - Smallest" << endl;
		cout << "Q - Quit" << endl;
		cin >> selection;

		if (selection == 'P' || selection == 'p')
		{
			if (numbers.size() == 0)
			{
				cout << "There are no numbers in the vector." << endl;
			}
			else
			{
				for (auto num : numbers)
					cout << "The numbers are as follows: " << num;
			}
		}
		if (selection == 'a' || selection == 'A')
		{
			cout << "Enter an integer you would like to add: ";
			int added_number{};
			cin >> added_number;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input " << endl;
				cout << "Try again" << endl;
			}
			else
			{
				numbers.push_back(added_number);
				cout << added_number << " has been included in the vector." << endl;
			}
		}
		if (selection == 'M' || selection == 'm')
		{
			if (numbers.size() == 0)
			{
				cout << "Divide by zero error." << endl;
			}
			else
			{
				int total{};
				for (auto num : numbers)
					total += num;
				cout << "The mean average is " << static_cast <double> (total) / numbers.size() << endl;
			}
		}
		if (selection == 'L' || selection == 'l')
		{
			int largest = numbers.at(0);
			for (auto num : numbers)
				if (num > largest)
			largest = num;
			cout << "The largest number is: " << largest << endl;
		}
		if (selection == 'S' || selection == 's')
		{
			int smallest = numbers.at(0);
			for (auto num : numbers)
				if (num < smallest)
					smallest = num;
			cout << "The smallest number is: " << smallest << endl;
		}
	} while (selection != 'Q' && selection != 'q');

	cout << "Thank you." << endl;

}