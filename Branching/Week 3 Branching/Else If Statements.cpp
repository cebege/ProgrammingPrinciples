#include <iostream>

using namespace std;

int main() {

	int number;
	cout << "Enter your exam score: ";
	cin >> number;

	if (number >= 80)
	{
		cout << "You recieved an A*" << endl;
	}
	else if (number >= 70)
	{
		cout << "You recieved an A" << endl;
	}
	else if (number >= 60)
	{
		cout << "You recieved a B" << endl;
	}
	else if (number < 60)
	{
		cout << "You recieved a C" << endl;
	}
}