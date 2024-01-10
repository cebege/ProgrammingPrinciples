#pragma once
#include "Point.h"

enum class ActorColour
{
	Regular = 7,
	Red = 9,
	Blue = 10,
	Green = 12,
	RedSolid = 34,
	BlueSolid = 255,
	GreenSolid = 153
};

enum class ActorType
{
	Door,
	Money,
	Enemy,
	Player,
	Key,
	Goal
};

class PlaceableActor
{
protected:
	Point* _pPosition;
	ActorColour _ActorColour;
	bool _isActive;

public:
	PlaceableActor(int x, int y, ActorColour colour = ActorColour::Regular);
	~PlaceableActor();

	int getPositionX() { return _pPosition->x; }
	int getPositionY() { return _pPosition->y; }
	int* getPositionX_ptr() { return &(_pPosition->x); }
	int* getPositionY_ptr() { return &(_pPosition->y); }
	ActorColour getActorColour() { return _ActorColour; }
	void setPositionXY(int x, int y);

	void remove() { _isActive = false; }
	bool isActive() { return _isActive; }
	void place(int x, int y);

	virtual ActorType getType() = 0;
	virtual void draw() = 0;
	virtual void update()
	{

	}


};