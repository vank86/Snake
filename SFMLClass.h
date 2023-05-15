
#ifndef SNAKE_SFMLCLASS_H
#define SNAKE_SFMLCLASS_H
#include "SnakeArea.h"
#include "SnakeBody.h"
#include "Apple.h"
#include "Menu.h"
#include "GameState.h"
#include "SFML/Window.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>


struct playerScore
{
    std::string name;
    int score;
};

class SFMLClass{
    int cellSize;
    int ResolX;
    int ResolY;
    float timer;
    float delay;
    sf::Clock clock;
    sf::Texture snakeTexture;
    sf::Texture appleTexture;


public:
    SFMLClass(int Rx, int Ry);
    void menuWindow();
    void initGame();
    void gameOverText(sf::RenderWindow &window);
    int getSizeOfCell() const;
    int getResolX() const;
    int getResolY() const;
    static bool compare_scores(playerScore ps1, playerScore ps2);
    void playerToScoreBoard();
    std::vector<playerScore> getScoreBoard();
    bool is_empty(std::ifstream& pFile);

};



#endif //SNAKE_SFMLCLASS_H
