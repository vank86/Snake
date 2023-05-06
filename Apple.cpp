//
// Created by Ivan on 19/04/2023.
//

#include "Apple.h"
//
Apple::Apple(SnakeArea &ar, SnakeBody &snake) : area(ar), snake(snake)
{
    apple.x = 15;
    apple.y = 15;
}

void Apple::appleRandomPosition()
{
    if ((snake.snakeHeadX() == apple.x) && (snake.snakeHeadY() == apple.y)) {
        snake.bodyGrowth();
        apple.x = rand() % area.getWidth();
        apple.y = rand() % area.getHeight();

    }

}
//// PROBLEM WITH LINKER
//void drawApple(sf::RenderWindow &window, sf::Sprite &appleSprite)
//{
//    appleSprite.setTextureRect(sf::IntRect(0, 0, 25, 25));
//
//    appleSprite.setPosition(25,25);
//
//    window.draw(appleSprite);
//}
//
