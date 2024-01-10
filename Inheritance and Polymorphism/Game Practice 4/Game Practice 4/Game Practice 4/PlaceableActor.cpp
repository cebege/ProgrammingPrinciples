#include "PlaceableActor.h"

PlaceableActor::PlaceableActor(int x, int y, int colour)
	: mPosition(new Point(x, y))
	, mColour(colour)
	, mIsActive(false)
{};

PlaceableActor::~PlaceableActor()
{
	if (mPosition != nullptr)
	{
		mPosition = nullptr;
	}
}

void PlaceableActor::setPositionXY(int x, int y)
{
	mPosition->x = x;
	mPosition->y = y;
}

void PlaceableActor::place(int x, int y)
{
	mPosition->x = x;
	mPosition->y = y;
	mIsActive = true;
}

