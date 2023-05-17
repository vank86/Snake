//
// Created by Ivan on 19/04/2023.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H

#include "SFML/Graphics.hpp"
#include "SnakeArea.h"
#include "SnakeBody.h"

class Apple : public GameState{
    struct AppleObject{
        int x;
        int y;
    } apple;
    SnakeArea &area;
    SnakeBody &snake;

public:
    Apple(SnakeArea &ar, SnakeBody &snake);
    void drawApple(sf::RenderWindow &window, sf::Sprite &appleSprite);
    void appleRandomPosition();
};


#endif //SNAKE_APPLE_H
