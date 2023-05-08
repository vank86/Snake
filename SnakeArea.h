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

    sf::Texture boardCell;

public:
    SnakeArea(int, int);
    void drawBoard(sf::RenderWindow &window);
    int getHeight() const;
    int getWidth() const;
};


#endif //SNAKE_SNAKEAREA_H
