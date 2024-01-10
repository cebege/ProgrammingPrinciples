#include <iostream>
#include <Windows.h>
#include "Key.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, m_colour);
	std::cout << "+"; // prints coloured key.
	SetConsoleTextAttribute(console, kRegularColour);
}