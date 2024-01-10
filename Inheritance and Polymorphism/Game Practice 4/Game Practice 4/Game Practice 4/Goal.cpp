#include "Goal.h"
#include <iostream>

using namespace std;

Goal::Goal(int x, int y)
	: PlaceableActor(x, y)
{};

void Goal::draw()
{
	cout << "X";
}