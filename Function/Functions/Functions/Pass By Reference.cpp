#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value1(int& par1);
void pass_by_value2(string& my_name);
void swap_value(int& par1, int& par2);

int main() {

	int act1 = 5000;
	int act2 = 1000;
	cout << "Before pass by value " << act1 << endl;
	pass_by_value1(act1);
	cout << "After pass by value " << act1 << endl; // TAKES THE VALUE IN FUNCTION AS A & HAS BEEN USED.

	string friend_name{ "Calvin" };

	cout << "Before pass by value " << friend_name << endl;
	pass_by_value2(friend_name);
	cout << "After pass by value " << friend_name << endl; // TAKES THE VALUE IN FUNCTION AS A & HAS BEEN USED.

	cout << "The numbers before swap are " << act1 << " and " << act2 << endl;
	swap_value(act1, act2);
	cout << "The numbers after swap are " << act1 << " and " << act2;

}

void pass_by_value1(int& par1)
{
	par1 = 2000;
}

void pass_by_value2(string& my_name)
{
	my_name = "Conor";
}

void swap_value(int& par1, int& par2)
{
	int temp = 0;
	temp = par1;
	par1 = par2;
	par2 = temp;

}
