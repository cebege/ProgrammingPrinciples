#include "Key.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Key::Key(int x, int y, int colour)
	: PlaceableActor(x, y, colour)
{};

void Key::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, mColour);
	cout << "+";
	SetConsoleTextAttribute(console, kRegularColour);
}