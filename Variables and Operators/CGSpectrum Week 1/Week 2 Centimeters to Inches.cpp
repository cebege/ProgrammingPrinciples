#include <iostream>

using namespace std;

int main() {
	float centimeters;
	cout << "Enter total centimeters: ";
	cin >> centimeters;

	float inches = centimeters / 2.54f;
	cout << "Total inches: " << inches;
}