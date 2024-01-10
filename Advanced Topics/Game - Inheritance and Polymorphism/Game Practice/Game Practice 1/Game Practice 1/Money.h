#pragma once
#include "PlaceableActor.h"
class Money :
    public PlaceableActor
{
private:
    int _worth;

public:
    Money(int x, int y);

    int getWorth() { return _worth; }

    virtual void draw() override;
    virtual ActorType getType() override;

};

