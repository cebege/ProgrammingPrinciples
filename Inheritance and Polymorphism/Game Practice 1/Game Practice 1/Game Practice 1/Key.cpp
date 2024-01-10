#include "Key.h"
#include <Windows.h>
#include <iostream>


void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, mColour);
	cout << "*";
	SetConsoleTextAttribute(console, kRegularColour);
}