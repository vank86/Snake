#include "SnakeBody.h"

SnakeBody::SnakeBody(SnakeArea &ar) : GameState(), area(ar)
{
    this->bodySize = 3;
    this->dir = RIGHT;

//    start position
    this->sn[0].x = 10;
    this->sn[0].y = 15;

}

void SnakeBody::snakeBody()
{
//  snake body body-head following
    for (int i = bodySize; i > 0; i--)
    {
        sn[i].x = sn[i - 1].x;
        sn[i].y = sn[i - 1].y;
    }

//  snake directions
    if (dir == UP)
        sn[0].y--;
    if (dir == DOWN)
        sn[0].y++;
    if (dir == RIGHT)
        sn[0].x++;
    if (dir == LEFT)
        sn[0].x--;

//    out of window cases
    if (sn[0].x > area.getWidth())
        sn[0].x = 0;
    if (sn[0].x < 0)
        sn[0].x = area.getWidth();
    if (sn[0].y > area.getHeight())
        sn[0].y = 0;
    if (sn[0].y < 0)
        sn[0].y = area.getHeight();

//    collision case
    for (int i = 1; i < bodySize; i++)
    {
        if (sn[0].x == sn[i].x && sn[0].y == sn[i].y) {
            setGameState();
        }
    }

}

void SnakeBody::drawSnake(sf::RenderWindow &window, sf::Sprite &snakeSprite)
{
    for(int i = 0; i < bodySize; i++)
    {
        if (i != 0) {
//          head drawing
            snakeSprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
        }
        else {
//          body drawing
            snakeSprite.setTextureRect(sf::IntRect(25, 0, 25, 25));
        }

        snakeSprite.setPosition(sn[i].x * 25, sn[i].y * 25);
        window.draw(snakeSprite);


    }
}


void SnakeBody::setDir(Direction direct)
{
    this->dir = direct;
}

Direction SnakeBody::getDir() const
{
    return dir;
}

int SnakeBody::snakeHeadX() const
{
    return sn[0].x;
}
int SnakeBody::snakeHeadY() const
{
    return sn[0].y;
}

void SnakeBody::bodyGrowth()
{
    this->bodySize++;
}