#include "Apple.h"
//
Apple::Apple(SnakeArea &ar, SnakeBody &snake) : area(ar), snake(snake)
{
//    apple start position
    apple.x = 15;
    apple.y = 15;
}

void Apple::appleRandomPosition()
{
    if ((snake.snakeHeadX() == apple.x) && (snake.snakeHeadY() == apple.y)) {
//        body growth
        snake.bodyGrowth();
//        score counter
        increaseScore();
//        apple randomizer
        apple.x = rand() % area.getWidth();
        apple.y = rand() % area.getHeight();
    }

}

void Apple::drawApple(sf::RenderWindow &window, sf::Sprite &appleSprite)
{
    appleSprite.setTextureRect(sf::IntRect(0, 0, 25, 25));

    appleSprite.setPosition(apple.x * 25,apple.y * 25);

    window.draw(appleSprite);
}
//
