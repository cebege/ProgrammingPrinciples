#pragma once
#include "PlaceableActor.h"

using namespace std;

class Key : public PlaceableActor
{
public:
	Key(int x, int y, int colour);

	virtual void draw() override;

private:
	bool mCurrentKey;


};