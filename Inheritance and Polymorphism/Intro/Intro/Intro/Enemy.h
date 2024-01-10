#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Character.h"

class Enemy : public Character
{
public:
	void speak() override
	{
		cout << "I am an Enemy." << endl;
	}
};

#endif