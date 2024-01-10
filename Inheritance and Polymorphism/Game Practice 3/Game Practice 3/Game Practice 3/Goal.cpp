#include "Goal.h"

using namespace std;

Goal::Goal(int x, int y)
	: PlaceableActor(x, y)
{};

void Goal::draw()
{
	cout << "X";
}