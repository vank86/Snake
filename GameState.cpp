#include "GameState.h"

GameState::GameState()
{
    gameStatus = true;
    std::cout << "created GameState" << '\n';

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
    score += 1;
}

void GameState::showScore()
{
    std::cout << score << '\n';
}
int GameState::getScore()
{
    return score;
}