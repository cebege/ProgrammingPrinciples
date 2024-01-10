#pragma once
using namespace std;
#include <iostream>
template <typename Type>
class Point
{
public:
	Type x;
	Type y;

	Point(Type x = 0, Type y = 0)
		: x (x)
		y (y)
		{};

	Type GetLarger()
	{
		if (x > y)
			return x;
		return y;
	}

	Type GetSmaller()
	{
		if (x < y)
			return x;
		return y;
	}
};

int main()
{
	Point<int> p1(10, 20);
	Point<double> p2(20.25, 20.50);

	int p3 = p1.GetLarger();
	cout << "p3: " << p3 << endl;


}