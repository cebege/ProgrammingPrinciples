#pragma once
#include "Point.h"
using namespace std;

constexpr int kGreenColour = 10;
constexpr int kGreenColourSolid = 34;
constexpr int kRedColour = 12;
constexpr int kRedColourSolid = 14;
constexpr int kBlueColour = 9;
constexpr int kBlueColourSolid = 153;
constexpr int kRegularColour = 153;

class PlaceableActor
{
protected:
	Point* mPosition;
	bool mIsActive;
	int mColour;

public:
	PlaceableActor(int x, int y, int colour = kRegularColour);
	~PlaceableActor();

	bool isActive() { return mIsActive; }
	void remove() { mIsActive = false; }

	void setPositionXY(int x, int y);
	void place(int x, int y);

	int getPositionX() { return mPosition->x; }
	int getPositionY() { return mPosition->y; }
	int* getPositionXP() { return &(mPosition->x); }
	int* getPositionYP() { return &(mPosition->y); }

	int getColour() { return mColour; }

	virtual void draw() = 0;
	virtual void update()
	{

	};
};