#include <iostream>
#include <string>

using namespace std;

int main() {
	string user_name;
	string last_name;
	unsigned short year_of_birth;
	unsigned short current_year;

	cout << "Enter your name: ";
	cin >> user_name;
	cin >> last_name;
	cout << "Enter year of birth: ";
	cin >> year_of_birth;
	cout << "Enter current year: ";
	cin >> current_year;
	cout << "Name: " << user_name << " " << last_name << endl;
	cout << "Year of birth: " << year_of_birth << endl;
	cout << "Current year: " << current_year << endl;

	unsigned short age = current_year - year_of_birth;
	cout << "Age: " << age << endl;
}