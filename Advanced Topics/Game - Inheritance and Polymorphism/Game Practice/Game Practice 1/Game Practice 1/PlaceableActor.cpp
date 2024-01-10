#include "PlaceableActor.h"

PlaceableActor::PlaceableActor(int x, int y, ActorColour colour)
	: _pPosition(new Point(x, y))
	, _ActorColour(colour)
	, _isActive(true)
{};

PlaceableActor::~PlaceableActor()
{
	if (_pPosition != nullptr)
	{
		delete _pPosition;
		_pPosition = nullptr;
	}
}

void PlaceableActor::setPositionXY(int x, int y)
{
	_pPosition->x = x;
	_pPosition->y = y;
}

void PlaceableActor::place(int x, int y)
{
	_pPosition->x = x;
	_pPosition->y = y;
	_isActive = true;
}
