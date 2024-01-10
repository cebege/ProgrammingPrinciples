#pragma once
#include "PlaceableActor.h"

class Door : public PlaceableActor
{
public:

	Door(int x, int y, int colour, int closedColour);

	bool isOpen() { return mIsOpen; }

	virtual void draw() override;

private:

	bool mIsOpen;
	int mClosedColour

};