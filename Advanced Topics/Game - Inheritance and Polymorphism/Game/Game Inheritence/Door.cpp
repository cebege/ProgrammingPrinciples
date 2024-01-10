#include <iostream>
#include <Windows.h>
#include "Door.h"

Door::Door(int x, int y, ActorColour colour, ActorColour closedColour)
	:PlaceableActor(x, y, colour)
	, m_isOpen(false)
	, m_closedColour(closedColour)
{};

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, (int)m_colour); // cast to an int
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_closedColour);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColour::Regular);
}