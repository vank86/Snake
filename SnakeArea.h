//
// Created by Ivan on 19/04/2023.
//

#ifndef SNAKE_SNAKEAREA_H
#define SNAKE_SNAKEAREA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class SnakeArea {
    int width {};
    int height {};
    int cellSize {10};
    typedef struct playingArea{
        bool isGround;
        bool isWall;
    } AREA;
    sf::Texture boardCell;

public:
    SnakeArea(int, int);
    void drawBoard(sf::RenderWindow &window);
    int getHeight();
    int getWidth;
//    int setHeight();
//    int setWidth;
};


#endif //SNAKE_SNAKEAREA_H
