#include <iostream>
using namespace std;

void Counter()
{
	static int counter = 0;
	counter++;
	cout << counter << ", ";
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		Counter();
	}
}