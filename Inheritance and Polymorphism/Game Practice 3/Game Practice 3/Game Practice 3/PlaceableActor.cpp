#include "PlaceableActor.h"

PlaceableActor::PlaceableActor(int x, int y, int colour = kRegularColour)
	: mIsActive(true)
	, mColour(colour)
	, mCurrentPosition(new Point(x, y))
{

};

PlaceableActor::~PlaceableActor()
{
	if (mCurrentPosition != nullptr)
	{
		delete mCurrentPosition;
		mCurrentPosition = nullptr;
	}
}

void PlaceableActor::setXYposition(int x, int y)
{
	mCurrentPosition->x = x;
	mCurrentPosition->y = y;
}

void PlaceableActor::place(int x, int y)
{
	mCurrentPosition->x = x;
	mCurrentPosition->y = y;
	mIsActive = true;
}

void PlaceableActor::remove()
{
	mIsActive = false;
}