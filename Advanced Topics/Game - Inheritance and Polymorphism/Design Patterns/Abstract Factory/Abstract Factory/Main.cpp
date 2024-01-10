#include <string>
#include <iostream>

using namespace std;

class Button
{
protected:
	string mLabel;

public:
	Button(string label)
		: mLabel(label)
	{
	}
	virtual void draw() = 0;
};

class CheckBox
{
public:
	virtual void draw() = 0;
};

class GUIFactory
{
public:
	virtual Button* CreateButton(string label) = 0;
	virtual CheckBox* CreateCheckBox() = 0;
};

#ifdef XBOX

class XboxButton : public Button
{
public:
	XboxButton(string label)
		: Button(label)
	{};

	virtual void draw() override
	{
		cout << "A: " << mLabel << endl;
	}
};

class XboxCheckBox : public CheckBox
{
	virtual void draw() override
	{
		cout << "Xbox Checkbox" << endl;
	}
};

class XboxFactory : public GUIFactory
{
	virtual Button* CreateButton(string label) override
	{
		return new XboxButton(label);
	}
	virtual CheckBox* CreateCheckBox() override
	{
		return new XboxCheckBox();
	}
};

#else

class PlaystationButton : public Button
{
public:
	PlaystationButton(string label)
		: Button(label)
	{};

	virtual void draw() override
	{
		cout << "X: " << mLabel << endl;
	}
};

class PlaystationCheckBox : public CheckBox
{
	virtual void draw() override
	{
		cout << "Playstation Checkbox" << endl;
	}
};

class PlaystationFactory : public GUIFactory
{
	virtual Button* CreateButton(string label) override
	{
		return new PlaystationButton(label);
	}
	virtual CheckBox* CreateCheckBox() override
	{
		return new PlaystationCheckBox();
	}
};

#endif // XBOX

//use preprocessor directives.

GUIFactory* GetGUIFactory() // Graphical User Interface.
{
#ifdef XBOX

	return new XboxFactory();

#else

	return new PlaystationFactory();

#endif // XBOX
}

int main()
{
	GUIFactory* pFactory = GetGUIFactory();
	Button* pButton = pFactory->CreateButton("Main Menu");
	CheckBox* pCheckBox = pFactory->CreateCheckBox();

	pButton->draw();
	pCheckBox->draw();

	delete pButton;
	pButton = nullptr;

	delete pFactory;
	pFactory = nullptr;
}

