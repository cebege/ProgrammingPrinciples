#include "Door.h"
#include <Windows.h>
using namespace std;

Door::Door(int x, int y, int colour, int closedColour)
	: PlaceableActor(x, y, colour)
	, mIsOpen(false)
	, mClosedColour(closedColour)
{};

void Door::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (mIsOpen = true)
	{
		SetConsoleTextAttribute(console, mColour);
	}
	else
	{
		SetConsoleTextAttribute(console, mClosedColour);
	}
	cout << "|";
	SetConsoleTextAttribute(console, kRegularColour);
}