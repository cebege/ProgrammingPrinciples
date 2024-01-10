#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "PlaceableActor.h"

class Key;

class Player : public PlaceableActor
{

public:
	Player();

	bool HasKey();
	bool HasKey(ActorColour colour);
	void PickUpKey(Key* key);
	void UseKey();
	void DropKey();
	Key* GetKey() { return m_pCurrentKey; }

	void AddMoney(int money) { m_money += money; }
	int GetMoney() { return m_money; }

	int GetLive() { return m_lives; }
	void DecrementLives() { m_lives--; }

	virtual ActorType GetType() override { return ActorType::Player; }
	virtual void Draw() override;

private:
	Key* m_pCurrentKey;
	int m_money;
	int m_lives;

};

#endif // !_PLAYER_H_
