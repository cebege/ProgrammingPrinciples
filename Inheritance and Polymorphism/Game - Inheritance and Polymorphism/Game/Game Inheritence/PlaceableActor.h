#ifndef PLACEABLEACTOR_H
#define PLACEABLEACTOR_H

constexpr int kGreenColour = 10;
constexpr int kGreenColourSolid = 34;
constexpr int kRedColour = 12;
constexpr int kRedColourSolid = 14;
constexpr int kBlueColour = 9;
constexpr int kBlueColourSolid = 153;
constexpr int kRegularColour = 7;
#include "Point.h"

class PlaceableActor
{
public:
	PlaceableActor(int x, int y, int colour = kRegularColour);
	virtual ~PlaceableActor();

	int GetXPosition();
	int GetYPosition();
	int* GetXPositionPointer();
	int* GetYPositionPointer();
	void SetXYPosition(int x, int y);

	int GetColour() { return m_colour; }

	void Remove() { m_IsActive = false; }
	bool IsActive() { return m_IsActive; }
	void Place(int x, int y);

	virtual void Draw() = 0;
	virtual void Update() // some placeable actors will not need to update themselves
	{

	}

protected:
	Point* m_pPosition;
	bool m_IsActive;
	int m_colour;

};

#endif