#pragma once
#include "PlaceableActor.h"

using namespace std;

class Goal : public PlaceableActor
{
public:

	Goal(int x, int y);

	virtual void draw() override;
};