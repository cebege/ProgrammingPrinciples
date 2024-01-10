#pragma once
#include "PlaceableActor.h"
class Goal :
    public PlaceableActor
{
public:
    Goal(int x, int y);

    virtual void draw() override;
    virtual ActorType getType() override;
};

