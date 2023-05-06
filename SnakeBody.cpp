//
// Created by Ivan on 06/05/2023.
//

#include "SnakeBody.h"

SnakeBody::SnakeBody()
{
    this->bodySize = 5;
    this->dir = RIGHT;
    this->sn[0].x = 10;
    this->sn[0].y = 15;

}

void SnakeBody::snakeBody()
{
    for (int i = bodySize; i > 0; i--)
    {
        sn[i].x = sn[i - 1].x;
        sn[i].y = sn[i - 1].y;
    }

    if (dir == UP)
        sn[0].y -= 1;
    if (dir == DOWN)
        sn[0].y += 1;
    if (dir == RIGHT)
        sn[0].x += 1;
    if (dir == LEFT)
        sn[0].x -= 1;

}

void SnakeBody::drawSnake(sf::RenderWindow &window, sf::Sprite &snakeSprite)
{
    for(int i = 0; i < bodySize; i++)
    {
        if (i != 0) {
            snakeSprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
        }
        else {
            snakeSprite.setTextureRect(sf::IntRect(25, 0, 25, 25));
        }
//        window.draw(snakeSprite);
//        window.draw(snakeBody);
        snakeSprite.setPosition(sn[i].x * 25, sn[i].y * 25);

        window.draw(snakeSprite);
//        window.draw(snakeBody);


    }
}

int SnakeBody::getBodySize() const
{
    return bodySize;
}

//Snake& SnakeBody::operator[](int index)
//{
//    return sn[index];
//}

void SnakeBody::setDir(Direction direct)
{
    this->dir = direct;
}

Direction SnakeBody::getDir() const
{
    return dir;
}