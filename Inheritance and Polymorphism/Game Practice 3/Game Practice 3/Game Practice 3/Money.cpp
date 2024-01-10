#include "Money.h"

using namespace std;

Money::Money(int x, int y, int amount)
	: PlaceableActor(x, y)
	, mMoney(amount)
{};

void Money :: draw()
{
	cout << "$";
}
