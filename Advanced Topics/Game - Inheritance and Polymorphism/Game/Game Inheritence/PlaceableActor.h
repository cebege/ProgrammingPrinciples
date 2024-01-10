#ifndef PLACEABLEACTOR_H
#define PLACEABLEACTOR_H
#include "Point.h"

enum class ActorColour
{
	Regular = 7,
	Blue = 9,
	Green = 10,
	Red = 12,
	GreenSolid = 34,
	RedSolid = 255,
	BlueSolid = 153
};

enum class ActorType
{
	Door,
	Enemy,
	Goal,
	Key,
	Money,
	Player
};

class PlaceableActor
{
public:
	PlaceableActor(int x, int y, ActorColour colour = ActorColour::Regular);
	virtual ~PlaceableActor();

	int GetXPosition();
	int GetYPosition();
	int* GetXPositionPointer();
	int* GetYPositionPointer();
	void SetXYPosition(int x, int y);

	ActorColour GetColour() { return m_colour; }

	void Remove() { m_IsActive = false; }
	bool IsActive() { return m_IsActive; }
	void Place(int x, int y);

	virtual ActorType GetType() = 0;
	virtual void Draw() = 0;
	virtual void Update() // some placeable actors will not need to update themselves
	{

	}

protected:
	Point* m_pPosition;
	bool m_IsActive;
	ActorColour m_colour;

};

#endif