#include "GameState.h"

GameState::GameState()
{
    gameStatus = true;
//    std::cout << "created GameState" << '\n';

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
// test function
void GameState::showScore()
{
//    std::cout << score << std::endl;
}
int GameState::getScore()
{
    return score;
}

void GameState::resetScore() {
    score = 0;
}
