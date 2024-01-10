#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int b = 40;

	bool result;
	cout << boolalpha;

	//result = (a > b); // false
	//result = (a >= b); // false
    //result = (a < b); // true
	//result = (a <= b); // true
	//result = (a == b); // false
	//result = (a != b); // true

	bool is_even = ((a % 2 == 0)) && ((b % 2 == 0));
	bool is_odd = ((a % 2 != 0)) && ((b % 2 == 0));

	cout << is_odd;
}