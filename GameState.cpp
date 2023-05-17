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

void GameState::increaseScore()
{
    score++;
}

int GameState::getScore()
{
    return score;
}

void GameState::resetScore() {
    score = 0;
}
