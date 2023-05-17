#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

#include "SFML/Graphics.hpp"
#include "SnakeArea.h"
#include "GameState.h"

enum Direction {UP, DOWN, LEFT, RIGHT};

class SnakeBody : public GameState{
    struct Snake{
        int x;
        int y;
    } sn[100];
    SnakeArea &area;
    int bodySize;
    Direction dir;

public:

    SnakeBody(SnakeArea &ar);
    void snakeBody();
    void drawSnake(sf::RenderWindow &window, sf::Sprite &snakeSprite);
    void setDir(Direction direct);

    Direction getDir() const;
    int snakeHeadX() const;
    int snakeHeadY() const;

    void bodyGrowth();
};


#endif //SNAKE_SNAKEBODY_H
