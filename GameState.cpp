#include "GameState.h"

GameState::GameState()
{
    gameStatus = true;
}

bool GameState::getGameState() const
{
    return gameStatus;
}

void GameState::setGameState()
{
    gameStatus = !gameStatus;
}