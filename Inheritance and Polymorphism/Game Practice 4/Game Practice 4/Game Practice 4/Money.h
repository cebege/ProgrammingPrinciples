#pragma once
#include "PlaceableActor.h"

class Money : public PlaceableActor
{
	Money(int x, int y);

	int getWorth() { return mMoney; }

	virtual void draw() override;

private:
	int mMoney;
};