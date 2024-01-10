#pragma once
#include "PlaceableActor.h"
class Enemy :
    public PlaceableActor
{
public:
    Enemy(int x, int y, int deltaX, int deltaY);

    virtual ActorType getType() override;
    virtual void draw() override;
    virtual void update() override;

private:
    int _currentMovementX;
    int _currentMovementY;

    int _movementX;
    int _movementY;

    int _directionX;
    int _directionY;

    void updateDirection(int current, int movement, int direction);
};

