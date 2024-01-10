#include "Money.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Money::Money(int x, int y)
	: PlaceableActor(x, y)
{};

ActorType Money::getType()
{
	return ActorType::Money;
}

void Money::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)ActorColour::Green);
	cout << "$";
	SetConsoleTextAttribute(console, (int)ActorColour::Regular);
}