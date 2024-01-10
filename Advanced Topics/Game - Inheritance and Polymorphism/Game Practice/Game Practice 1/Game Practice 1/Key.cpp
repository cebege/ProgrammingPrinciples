#include "Key.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Key::Key(int x, int y, ActorColour colour)
	: PlaceableActor(x, y, colour)
{};

ActorType Key::getType()
{
	return ActorType::Key;
}

void Key::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)_ActorColour);
	cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColour::Regular);
}
