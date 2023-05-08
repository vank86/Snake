#include "SFMLClass.h"


SFMLClass::SFMLClass(int Rx, int Ry, float delay) : ResolX(Rx), ResolY(Ry), delay(delay)
{
    this->cellSize = 25;
    this->timer = 0;
//    this->delay = 0.3;
}

void SFMLClass::initGame()
{
    sf::RenderWindow window(sf::VideoMode(ResolX, ResolY), "Snake");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    Menu menu(window.getSize().x, window.getSize().y);

    SnakeArea snakeArea(ResolX / cellSize, ResolY / cellSize);
    SnakeBody snake(snakeArea);
    Apple appleObj(snakeArea, snake);

    snakeTexture.loadFromFile("../images/snake.png");
    sf::Sprite snakeSprite(snakeTexture);


    appleTexture.loadFromFile("../images/apple.png");
    sf::Sprite appleSprite(appleTexture);

//    // run the program as long as the window is open


    while (window.isOpen())
    {
//        float time = clock.getElapsedTime().asSeconds();
//        clock.restart();
//        timer += time;
        window.clear();
        menu.drawMenu(window);
        window.display();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
//        snakeArea.drawBoard(window);

//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDir() != RIGHT)
//            snake.setDir(LEFT);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getDir() != LEFT)
//            snake.setDir(RIGHT);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getDir() != DOWN)
//            snake.setDir(UP);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDir() != UP)
//            snake.setDir(DOWN);

//        if (timer > delay && snake.getGameState()) {
//            timer = 0;
//            snake.snakeBody();
//            appleObj.appleRandomPosition();
//        }
//        snake.drawSnake(window, snakeSprite);
//        appleObj.drawApple(window, appleSprite);
//        window.draw(appleSprite);
//        window.display();
    }
}

int SFMLClass::getSizeOfCell() const
{
    return cellSize;
}

int SFMLClass::getResolX() {
    return ResolX;
}

int SFMLClass::getResolY() {
    return ResolY;
}



