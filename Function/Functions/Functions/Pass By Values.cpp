#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value1(int num);
void pass_by_value2(string s);

int main() {

	int num = 5000;
	int another_num = 2000;
	cout << "Before pass by value " << num << endl;
	pass_by_value1(num);
	cout << "After pass by value " << num << endl; // DOES NOT TAKE 1000. A COPY OF NUM IS PRODUCED BY THE FUNCTION.

	string name{ "Calvin" };

	cout << "Before pass by value " << name << endl;
	pass_by_value2(name);
	cout << "After pass by value " << name << endl; // DOES NOT TAKE CONOR. A COPY OF STRING IS PRODUCED BY THE FUNCTION.

}

void pass_by_value1(int num)
{
	num = 1000;
}

void pass_by_value2(string s)
{
	s = "Conor";
}