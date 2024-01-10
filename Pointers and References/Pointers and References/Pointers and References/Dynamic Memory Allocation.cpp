#include <iostream>

using namespace std;

int main() {

	int* int_ptr = new int { 20 };
	delete int_ptr;
	int_ptr = nullptr;

	int* ptr = new int{ 0 };
	for (int i = 0; i < 50000; ++i)
	{
		ptr = new int{ rand() }; // printing 5 times 
		cout << *ptr;
		delete ptr;
		ptr = nullptr;
	}


}