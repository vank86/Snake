//
// Created by Ivan on 04/05/2023.
//

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