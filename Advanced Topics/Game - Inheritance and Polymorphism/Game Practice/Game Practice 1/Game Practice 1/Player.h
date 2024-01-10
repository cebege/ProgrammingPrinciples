#pragma once
#include "PlaceableActor.h"
#include "Key.h"

class Player :
    public PlaceableActor
{
private:
    Key* _pCurrentKey;
    int _playerLives;
    int _playerMoney;

public:
    Player();

    bool hasKey() { return _pCurrentKey != nullptr; }
    bool hasKey(ActorColour colour) { return hasKey() && _pCurrentKey->getActorColour() == colour; }
    void dropKey();
    void pickUpKey(Key* key) { _pCurrentKey = key; }
    void useKey();

    Key* getKey() { return _pCurrentKey; }
    int getLives() { return _playerLives; }
    int getWorth() { return _playerMoney; }

    void addMoney(int money) { _playerMoney += money; }
    void decrementLives() { _playerLives--; }

    virtual ActorType getType() override;
    virtual void draw() override;

};

