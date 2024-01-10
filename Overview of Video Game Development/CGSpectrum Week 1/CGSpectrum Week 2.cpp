#include <iostream>
#include <string>

using namespace std;

int main() {
	int age;
	float weight;
	double distance;
	bool is_alive;
	char initial; 
	string name;

	unsigned short int better_age;
	long double huge_distance;

	age = 30;
	weight = 190.5f;
	distance = 1212.987;
	is_alive = true;
	initial = 'C';
	name = "Conor";

	cout << boolalpha;

	cout << "My name is " << name << " and I am " << age << " years old" << endl;
	cout << "I am " << is_alive << endl;

	int new_age;
	new_age = age;

	int newest_age = 25;


	return 0;
}