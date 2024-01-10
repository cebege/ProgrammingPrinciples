#include "PlaceableActor.h"

class Door : public PlaceableActor
{
public:
	Door(int x, int y, int colour, int closedColour);
	virtual void Draw() override;

	bool IsOpen() { return m_isOpen; }
	void Open() { m_isOpen = true; }

private:
	bool m_isOpen;
	int m_closedColour;

};