#pragma once
#include "PlaceableActor.h"

using namespace std;

class Door : public PlaceableActor
{
public:
	Door(int x, int y, int colour, int closedColour);

	bool isOpen() { return mIsOpen; }
	void OpenDoor() { mIsOpen = true; }

	virtual void draw() override;

private:
	bool mIsOpen;
	int mClosedColour;

};