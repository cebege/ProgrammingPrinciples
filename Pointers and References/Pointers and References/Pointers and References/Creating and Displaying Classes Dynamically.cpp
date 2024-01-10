#include <iostream>
using namespace std;

//create classes
//display classes

int* create_grades(size_t * size);

void populate_grades(int* p_my_grades, size_t * size);

void display_grades(int * p_my_grades, size_t * size);

int main() {

	size_t * size_p{ nullptr };
	size_t size{ 0 };
	size_p = &size;
	cout << "How many classes do you have? " << endl;
	cin >> size;
	int* p_my_grades = create_grades(size_p);
	populate_grades(p_my_grades, size_p);
	display_grades(p_my_grades, size_p);

	

}

int* create_grades(size_t * size)
{
	int* ptr = new int[*size];
	return ptr;
}

void populate_grades(int* p_my_grades, size_t *size)
{
	for (int i = 0; i < *size; ++i)
	{
		cin >> p_my_grades[i];
	}
}

void display_grades(int* p_my_grades, size_t * size)
{
	for (int i = 0; i < *size; ++i)
	{
		cout << p_my_grades[i] << " ";
	}
}
