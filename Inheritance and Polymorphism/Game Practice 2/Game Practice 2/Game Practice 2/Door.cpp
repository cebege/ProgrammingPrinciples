#include "Door.h"
#include <Windows.h>

Door::Door(int x, int y, int colour, int closedColour)
	: PlaceableActor(x, y, colour)
	, mIsOpen(false)
	, mClosedColour(closedColour)
{}

void Door::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (isOpen)
	{
		SetConsoleTextAttribute(console, mColour);
	}
	else
	{
		SetConsoleTextAttribute(console, mClosedColour);
	}
	std::cout << '|';
	SetConsoleTextAttribute(console, kRegularColour);
}