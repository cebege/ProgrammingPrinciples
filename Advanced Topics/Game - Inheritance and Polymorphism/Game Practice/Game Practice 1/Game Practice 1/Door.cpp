#include "Door.h"
#include <Windows.h>
#include <iostream>
using namespace std;

Door::Door(int x, int y, ActorColour colour, ActorColour closedColour)
	: PlaceableActor(x, y, colour)
	, _isOpen(false)
	, _closedColour(closedColour)
{}

void Door::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (_isOpen)
	{
		SetConsoleTextAttribute(console, (int)_ActorColour);
	}
	if (!_isOpen)
	{
		SetConsoleTextAttribute(console, (int)_closedColour);
	}
	cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColour::Regular);
}