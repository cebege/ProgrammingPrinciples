#include "GameplayState.h"

#include <conio.h>
#include <iostream>
#include <assert.h>

#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Money.h"
#include "Goal.h"
#include "AudioManager.h"
#include "Game.h"
#include "Utility.h"

#include "StateMachineExampleGame.h"

using namespace std;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;
constexpr int kBackspace = 8;

GameplayState::GameplayState(StateMachineExampleGame* pOwner)
	: m_pOwner(pOwner)
	, m_beatLevel(false)
	, m_skipFrameCount(0)
	, m_currentLevel(0)
	, m_pLevel(nullptr)
{
	m_LevelNames.push_back("Level1.txt");
	m_LevelNames.push_back("Level2.txt");
	m_LevelNames.push_back("Level3.txt");
}

GameplayState::~GameplayState()
{
	m_pLevel = nullptr;
	delete m_pLevel;
}

bool GameplayState::load()
{
	if (m_pLevel)
	{
		delete m_pLevel;
		m_pLevel = nullptr;
	}

	m_pLevel = new Level();

	return m_pLevel->LoadLevel(m_LevelNames.at(m_currentLevel), m_player.GetXPositionPointer(), m_player.GetYPositionPointer());
}

void GameplayState::Enter()
{
	load();
}

bool GameplayState::Update(bool processInput)
{
	if (processInput && !m_beatLevel)
	{
		int input = _getch();
		int arrowInput = 0;
		int newPlayerX = m_player.GetXPosition();
		int newPlayerY = m_player.GetYPosition();

		// One of the Arrow keys were pressed
		if (input == kArrowInput)
		{
			arrowInput = _getch();
		}

		if ((input == kArrowInput && arrowInput == kRightArrow) ||
			((char)input == 'd' || (char)input == 'D'))
		{
			newPlayerX++;
		}

		else if ((input == kArrowInput && arrowInput == kLeftArrow) ||
			((char)input == 'a' || (char)input == 'A'))
		{
			newPlayerX--;
		}

		else if ((input == kArrowInput && arrowInput == kUpArrow) ||
			((char)input == 'w' || (char)input == 'W'))
		{
			newPlayerY--;
		}

		else if ((input == kArrowInput && arrowInput == kDownArrow) ||
			((char)input == 's' || (char)input == 'S'))
		{
			newPlayerY++;
		}

		else if (input == kEscapeKey)
		{
			m_pOwner->LoadScene(StateMachineExampleGame::SceneName::MainMenu);
		}
		else if ((char)input == 'Z' || (char)input == 'z')
		{
			m_player.DropKey();
			AudioManager::GetInstance()->dropKeySound();
		}
		//If position never changed

		if (newPlayerX == m_player.GetXPosition() && newPlayerY == m_player.GetYPosition())
		{
			
		}
		else
		{
			HandleCollision(newPlayerX, newPlayerY);
		}
	}

	if (m_beatLevel)
	{
		++m_skipFrameCount;
		if (m_skipFrameCount > kFramesToSkip) // player transitions over to X spot before sound.
		{
			m_beatLevel = false;
			m_skipFrameCount = 0;

			++m_currentLevel;
			if (m_currentLevel == m_LevelNames.size())
			{
				Utility::WriteHighScore(m_player.GetMoney());
				AudioManager::GetInstance()->win();
				m_pOwner->LoadScene(StateMachineExampleGame::SceneName::Win);
			}
			else
			{
				load();
			}
		}
	}
	return false;
}

void GameplayState::HandleCollision(int newPlayerX, int newPlayerY) // more parameters to help with if loop
{
	PlaceableActor* collidedActor = m_pLevel->UpdateActors(newPlayerX, newPlayerY); // creates a placeable actor
	if (collidedActor != nullptr && collidedActor->IsActive())
	{
		switch (collidedActor->GetType())
		{
		case ActorType::Enemy:
		{
			Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor); // specifies the type/ thing we are trying to cast, in this case an enermy
			assert(collidedEnemy);
			AudioManager::GetInstance()->loseLife();
			// if the pointer is valid, if statement works, if it is a key none of the code will work
			collidedEnemy->Remove(); // if a collision with an enemy occurs, the enermy is removed.
			m_player.SetXYPosition(newPlayerX, newPlayerY); // players position is set to new position
			m_player.DecrementLives(); // decrmeent lives
			if (m_player.GetLive() < 0) // if less than zero game is over.
			{
				AudioManager::GetInstance()->PlayLoseSound();
				m_pOwner->LoadScene(StateMachineExampleGame::SceneName::Lose);
			}
			break;
		}
		case ActorType::Money:
		{
			Money* collidedMoney = dynamic_cast<Money*>(collidedActor); // if collided with money
			assert(collidedMoney);
			AudioManager::GetInstance()->moneySound();
			collidedMoney->Remove(); // remove the money
			m_player.AddMoney(collidedMoney->GetWorth()); // add the money and show the worth.
			m_player.SetXYPosition(newPlayerX, newPlayerY);
			break;
		}
		case ActorType::Key:
		{
			Key* collidedKey = dynamic_cast<Key*>(collidedActor); // returning null if fails within dynamic casts.
			assert(collidedKey);
			if (!m_player.HasKey())
			{
				m_player.PickUpKey(collidedKey);
				AudioManager::GetInstance()->pickupkey();
				collidedKey->Remove();
				m_player.SetXYPosition(newPlayerX, newPlayerY);
			}
			break;
		}
		case ActorType::Door:
		{
			Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
			assert(collidedDoor);
			if (!collidedDoor->IsOpen())
			{
				if (m_player.HasKey(collidedDoor->GetColour()))
				{
					collidedDoor->Open();
					collidedDoor->Remove();
					m_player.UseKey();
					m_player.SetXYPosition(newPlayerX, newPlayerY);
					AudioManager::GetInstance()->dropKeySound();
				}
				else
				{

				}
			}
			else
			{
				m_player.SetXYPosition(newPlayerX, newPlayerY); // player goes through the door
			}
			break;
		}
		case ActorType::Goal:
		{
			Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);
			assert(collidedGoal);
			collidedGoal->Remove(); // removes actors
			m_player.SetXYPosition(newPlayerX, newPlayerY);
			m_beatLevel = true;
			break;
		}
		}
	}
	else if (m_pLevel->IsSpace(newPlayerX, newPlayerY)) // no collision
	{
		m_player.SetXYPosition(newPlayerX, newPlayerY);
	}
	else if (m_pLevel->IsWall(newPlayerX, newPlayerY))
	{
		// wall collision
	}
}

void GameplayState::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");

	m_pLevel->Draw();

	//Set cursor position for player
	COORD actorCursorPosition;
	actorCursorPosition.X = m_player.GetXPosition();
	actorCursorPosition.Y = m_player.GetYPosition();
	SetConsoleCursorPosition(console, actorCursorPosition);
	m_player.Draw();


	//Set cursor to end of level.
	COORD currentCursorPosition;
	actorCursorPosition.X = 0;
	actorCursorPosition.Y = m_pLevel->GetHeight();
	SetConsoleCursorPosition(console, actorCursorPosition);

	DrawHUD(console);
}

void GameplayState::DrawHUD(const HANDLE& console)
{
	cout << endl;

	// Top Border
	for (int i = 0; i < m_pLevel->GetWidth(); ++i)
	{
		cout << Level::WAL;
	}
	cout << endl;

	// left border

	cout << Level::WAL;

	cout << "wasd: move  " << "dropkey: z " << Level::WAL <<  endl;
	cout << Level::WAL << "   $: " << m_player.GetMoney() << "  ";
	cout << " Lives: " << m_player.GetLive() << "  ";


	// right border

	cout << " ";
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);

	COORD pos;
	pos.X = m_pLevel->GetWidth() - 1;
	pos.Y = csbi.dwCursorPosition.Y;
	SetConsoleCursorPosition(console, pos);

	cout << Level::WAL;
	cout << endl;

	// Bottom Border
	for (int i = 0; i < m_pLevel->GetWidth(); ++i)
	{
		cout << Level::WAL;
	}
	cout << endl;
}