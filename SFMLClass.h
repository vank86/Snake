
#ifndef SNAKE_SFMLCLASS_H
#define SNAKE_SFMLCLASS_H
#include "SnakeArea.h"
#include "SnakeBody.h"
#include "Apple.h"
#include "Menu.h"
#include "SFML/Window.hpp"


class SFMLClass {
    int cellSize;
    int ResolX;
    int ResolY;
    float timer;
    float delay;
    sf::Clock clock;
    sf::Texture snakeTexture;
    sf::Texture appleTexture;


public:
    SFMLClass(int Rx, int Ry, float delay);
    void menuWndow();
    void initGame();
    int getSizeOfCell() const;
    int getResolX();
    int getResolY();
};



#endif //SNAKE_SFMLCLASS_H
