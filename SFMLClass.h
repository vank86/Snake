
#ifndef SNAKE_SFMLCLASS_H
#define SNAKE_SFMLCLASS_H
#include "SnakeArea.h"
#include "SnakeBody.h"
#include "Apple.h"
#include "SFML/Window.hpp"


class SFMLClass {
    int cellSize;
    int ResolX;
    int ResolY;
    float timer;
    float delay;

public:
    SFMLClass(int Rx, int Ry);
    void initGame();
    int getSizeOfCell() const;
};



#endif //SNAKE_SFMLCLASS_H
