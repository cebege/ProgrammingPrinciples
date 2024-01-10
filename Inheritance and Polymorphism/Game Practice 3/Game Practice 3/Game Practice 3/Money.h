#pragma once
#include "PlaceableActor.h"

using namespace std;

class Money : public PlaceableActor
{
public:
	Money(int x, int y, int amount);

	int getWorth() { return mMoney; }

	virtual void draw() override;

private:
	int mMoney;
};