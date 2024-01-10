#pragma once
#include "GameState.h"
#include "Player.h"
#include "Level.h"
#include <Windows.h>
#include <vector>
#include <string>

class StateMachineExampleGame;

class GameplayState :
    public GameState
{
    StateMachineExampleGame* m_pOwner;

    Player m_player;
    Level* m_pLevel;

    bool m_beatLevel;
    int m_skipFrameCount;
    static constexpr int kFramesToSkip = 2;

    int m_currentLevel;
    vector<string> m_LevelNames;

public:
    GameplayState(StateMachineExampleGame* pOwner);
    ~GameplayState(); // clean up after levelnames
    virtual void Enter() override;
    virtual bool Update(bool processInput = true) override;
    virtual void Draw() override;

private:
    bool load();
    void HandleCollision(int newPlayerX, int newPlayerY);
    void DrawHUD(const HANDLE& console);

};

