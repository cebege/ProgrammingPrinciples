#include "WinState.h"

#include <iostream>
#include <conio.h>

#include "StateMachineExampleGame.h"

using namespace std;

WinState::WinState(StateMachineExampleGame* pOwner)
	: m_pOwner(pOwner)
{}

bool WinState::Update(bool processInput)
{
	if (processInput)
	{
		int input = _getch();
		m_pOwner->LoadScene(StateMachineExampleGame::SceneName::MainMenu);
	}
	return false;
}

void WinState::Draw()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "             - - - - WELL DONE - - - -            " << endl << endl;
	cout << "             YOU BEAT THE GAME.       " << endl << endl;
	cout << "                                          " << endl << endl;

}
