#include <iostream>

using namespace std;

void swap(int* num, int* num1);

void display_array(int myArray[], size_t size);

int main() {

	int number{ 20 };
	int number1{ 50 };
	int* num{ &number };
	int* num1{ &number1 };

	cout << num << endl;
	cout << num1 << endl;

	swap(*num, *num1);

	cout << *num << endl;
	cout << *num1 << endl;

	size_t size{ 3 };
	int myArray[3]{ 20, 40, 50 };
	int* myArray_ptr{ myArray };
	cout << *myArray_ptr << endl;

	display_array(myArray, size);
	display_array(myArray_ptr, size);

}

void swap(int num, int num1)
{
	int temp{ 0 };
	temp = num;
	num = num1;
	num1 = temp;
}

void display_array(int myArray[], size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << myArray[i] << endl;
	}
}