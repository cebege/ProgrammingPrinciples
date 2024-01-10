#include "LoseState.h"

#include <iostream>
#include <conio.h>

#include "StateMachineExampleGame.h"

using namespace std;

LoseState::LoseState(StateMachineExampleGame* pOwner)
	: m_pOwner(pOwner)
{}

bool LoseState::Update(bool processInput)
{
	if (processInput)
	{
		int input = _getch();
		m_pOwner->LoadScene(StateMachineExampleGame::SceneName::MainMenu);
	}
	return false;
}

void LoseState::Draw()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "             - - - - GAME OVER - - - -            " << endl << endl;
	cout << "             BETTER LUCK NEXT TIME        " << endl << endl;
	cout << "             PRESS ANY KEY TO GO BACK TO MAIN MENU        " << endl << endl;

}