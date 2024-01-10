#include "PlaceableActor.h"
using namespace std;

PlaceableActor::PlaceableActor(int x, int y, int colour)
	: mPosition(new Point(x, y)),
	mActive(true),
	mColour(colour)
{};

PlaceableActor::~PlaceableActor()
{
	if (mPosition != nullptr)
	{
		mPosition = nullptr;
		delete mPosition;
	}
}

void PlaceableActor::setXYPosition(int x, int y)
{
	mPosition->x = x;
	mPosition->y = y;
}

void PlaceableActor::placeKey(int x, int y)
{
	mPosition->x = x;
	mPosition->y = y;
	mActive = true;
}
