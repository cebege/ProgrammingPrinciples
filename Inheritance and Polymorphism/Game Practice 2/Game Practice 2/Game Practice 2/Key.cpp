#include "PlaceableActor.h"
#include "Key.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void Key:: draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, mColour);
	cout << "+";
	SetConsoleTextAttribute(console, kRegularColour);
}