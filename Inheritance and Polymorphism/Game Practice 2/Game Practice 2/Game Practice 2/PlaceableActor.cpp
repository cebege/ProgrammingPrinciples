#include "PlaceableActor.h"

PlaceableActor::PlaceableActor(int x, int y, int colour)
	: mIsActive(true)
	, mColour(colour)
	, mPosition(new Point (x, y))
{}

PlaceableActor::~PlaceableActor()
{
	if (mPosition != nullptr)
	{
		mPosition = nullptr;
		delete mPosition;
	}
}

void PlaceableActor::setPosition(int x, int y)
{
	mPosition->x = x;
	mPosition->y = y;
}

int PlaceableActor::getPositionX()
{
	return mPosition->x;
}

int PlaceableActor::getPositionY()
{
	return mPosition->y;
}

int PlaceableActor::getColour()
{
	return mColour;
}

bool PlaceableActor::isActive()
{
	return mIsActive;
}

void PlaceableActor::remove()
{
	mIsActive = false;
}

void PlaceableActor::place(int x, int y)
{
	mPosition->x = x;
	mPosition->y = y;
	mIsActive = true;
}