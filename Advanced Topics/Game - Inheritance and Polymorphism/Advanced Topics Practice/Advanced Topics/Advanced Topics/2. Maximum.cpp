#include "1. Constructor and Operators.h"


int maximum(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int maximumDouble(double a, double b)
{
	if (a > b)
		return a;
	return b;
}

// VS

template <typename Type>
Type maximumTemplate (Type a, Type b)
{
	if (a > b)
		return a;
	return b;
}

int main() {

	Point p1(10, 5);
	Point p2(5, 2);

	int maxInt = maximumTemplate(10, 20);
	float maxFloat = maximumTemplate(10.2f, 20.2f);
	double maxDouble = maximumTemplate(10.552, 20.552);
	Point maxPoint = maximumTemplate(p1, p2);
}