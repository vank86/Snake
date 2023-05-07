//
// Created by Ivan on 06/05/2023.
//

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

#include "SFML/Graphics.hpp"
#include "SnakeArea.h"
#include "GameState.h"
enum Direction {UP, DOWN, LEFT, RIGHT};

//struct Snake{
//    int x;
//    int y;
//} sn[500];


class SnakeBody : public GameState{
    struct Snake{
        int x;
        int y;
    } sn[50];
    SnakeArea &area;
    int bodySize;
    Direction dir;

public:

    SnakeBody(SnakeArea &ar);
    void snakeBody();
    void drawSnake(sf::RenderWindow &window, sf::Sprite &snakeSprite);
//    void snakeMove(sf::Event &ev);
    int getBodySize() const;
    void setDir(Direction direct);

    Snake& operator[](int index);

    Direction getDir() const;
    int snakeHeadX() const;
    int snakeHeadY() const;
    void bodyGrowth();
};


#endif //SNAKE_SNAKEBODY_H
