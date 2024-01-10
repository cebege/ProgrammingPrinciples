#include <iostream>

using namespace std;

void print_array(int arr[], size_t size); // Possible to assign a const to the array so it cannot be changed.
void set_array(int arr[], size_t size, int value); // value we are setting the array to.

void print_array(int arr[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
	// arr[0] = 1000; // USING CONST TO THE FUNCTION HEADER YOU CAN AVOID THIS.
}

void set_array(int arr[], size_t size, int value)
{
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = value; // prints every number in the array to 100;
	}
}

int main() {

	int my_scores[]{ 100,98,90,86,84 };

	print_array(my_scores, 5);
	set_array(my_scores, 5, 100);
	print_array(my_scores, 5);

}