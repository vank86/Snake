//
// Created by Ivan on 19/04/2023.
//

#include "SnakeArea.h"


SnakeArea::SnakeArea(int w, int h) : width(w), height(h)
{
}

void SnakeArea::drawBoard(sf::RenderWindow &window)
{
    if (!boardCell.loadFromFile("../images/tiles.png"))
    {
        abort();
    }
    sf::Sprite sprite(boardCell);
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            sprite.setTextureRect(sf::IntRect(0,0,25,25));
            sprite.setPosition(i*25, j*25);
            window.draw(sprite);
        }
    }
//        sprite.setTextureRect(sf::IntRect(spriteRect * 11, 0, spriteRect, spriteRect));
//    sprite.setPosition(i *board.getSizeOfCell(), j * board.getSizeOfCell());
}

int SnakeArea::getHeight() const
{
    return height;
}
int SnakeArea::getWidth() const
{
    return width;
}
