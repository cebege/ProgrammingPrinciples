#include <iostream>

using namespace std;

int main() {
	double celcius;

	cout << "Enter temperature in Celcius: ";
	cin >> celcius;

	double fahrenheit = ((celcius * 9 / 5)) + 32;
	cout << "The temperature is " << fahrenheit << "F";

}