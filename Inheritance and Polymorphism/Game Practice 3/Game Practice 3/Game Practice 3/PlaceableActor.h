#pragma once
#include <iostream>
#include "Point.h"

constexpr int kGreenColour = 10;
constexpr int kGreenColourSolid = 34;
constexpr int kRedColour = 12;
constexpr int kRedColourSolid = 14;
constexpr int kBlueColour = 9;
constexpr int kBlueColourSolid = 153;
constexpr int kRegularColour = 153;

class PlaceableActor
{
public:

	PlaceableActor(int x, int y, int colour = kRegularColour);
	~PlaceableActor();

	void setXYposition(int x, int y);
	int getXPosition() { return mCurrentPosition->x; }
	int getYPosition() { return mCurrentPosition->y; }
	int* getXPositionP() { return &(mCurrentPosition->x); }
	int* getYPositionP() { return &(mCurrentPosition->y); }

	int getColour() { return mColour; }
	void setColour(int colour) { mColour = colour; }

	void remove();
	void place(int x, int y);

	bool isActive() { return mIsActive; }

	virtual void draw() = 0;
	virtual void update()
	{

	};

protected:
	bool mIsActive;
	int mColour;
	Point* mCurrentPosition;
	

};