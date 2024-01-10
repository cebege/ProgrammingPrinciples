#include "HighScoreState.h"

#include <iostream>
#include <conio.h>

#include "StateMachineExampleGame.h"
#include "Utility.h"

HighScoreState::HighScoreState(StateMachineExampleGame* pOwner)
	: m_pOwner(pOwner)
{
	m_highscore = Utility::WriteHighScore(0);
}

bool HighScoreState::Update(bool processInput)
{
	if (processInput)
	{
		int input = _getch();
		m_pOwner->LoadScene(StateMachineExampleGame::SceneName::MainMenu);
	}
	return false;
}

void HighScoreState::Draw()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "             - - - - HIGH SCORES - - - -            " << endl << endl;

	for (auto i = m_highscore.rbegin(); i != m_highscore.rend(); ++i)
	{
		cout << "                        " << *i << endl;
	}

	cout << endl;
	cout << endl;
	cout << "    Press any key to go back to the main menu. " << endl << endl;
}