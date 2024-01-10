#include "Key.h"
#include <Windows.h>

Key::Key(int x, int y, int colour)
	: PlaceableActor(x, y, colour)
{};

void PlaceableActor::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, mColour);
	cout << "+";
	SetConsoleTextAttribute(console, kRegularColour);
}