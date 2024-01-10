#pragma once

#include "PlaceableActor.h"

class Key : public PlaceableActor
{
public:

	Key(int x, int y, ActorColour colour);

	virtual ActorType getType() override;

	virtual void draw() override;

};


