#include "Goal.h"
#include <iostream>

Goal::Goal(int x, int y)
	: PlaceableActor(x, y)
{};

void Goal::draw()
{
	cout << "X";
}

ActorType Goal::getType()
{
	return ActorType::Goal;
}