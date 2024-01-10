#pragma once
#include "PlaceableActor.h"
class Door :
    public PlaceableActor
{
public:
    Door(int x, int y, ActorColour colour, ActorColour closedColour);

    virtual void draw() override;

    virtual ActorType getType() override;

    bool isOpen() { return _isOpen; }
    void Open() { _isOpen = true; }

private:
    bool _isOpen;
    ActorColour _closedColour;
};

