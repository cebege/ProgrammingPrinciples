#include <iostream>

using namespace std;

void func2(int& x, int y, int z)
{
	x += y + z; // x = x + y + z, x = 30 + 20 + 10 = 60. 
}

int func1(int a, int b)
{
	int result{};
	result = a + b; // result = 10 + 20 = 30.
	func2(result, a, b); // result = 30, a = 10, b = 30
	return result; // result = 60 as there is a pass by reference.
}

int main() {
	int x{ 10 };
	int y{ 20 };
	int z{};
	z = func1(x, y); // x = 10, y = 20
	cout << z << endl; // 60
	return 0;
}