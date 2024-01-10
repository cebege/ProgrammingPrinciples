#include "PlaceableActor.h"

class Door : public PlaceableActor
{
public:
	Door(int x, int y, ActorColour colour, ActorColour closedColour);
	virtual void Draw() override;

	virtual ActorType GetType() override { return ActorType::Door; }
	bool IsOpen() { return m_isOpen; }
	void Open() { m_isOpen = true; }

private:
	bool m_isOpen;
	ActorColour m_closedColour;

};