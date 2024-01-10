#include "Money.h"
#include <iostream>
using namespace std;

Money::Money(int x, int y)
	: PlaceableActor(x, y)
{};

void Money::draw()
{
	cout << "$";
}