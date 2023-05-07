#include <iostream>
#include "SnakeArea.h"
#include "SnakeBody.h"
#include "Apple.h"
#include "GameState.h"
#include "SFML/Window.hpp"

//using namespace sf;



int main() {
    srand(time(nullptr));
    int cellSize = 25;
    int ResolX = 800;
    int ResolY = 800;

    sf::RenderWindow window(sf::VideoMode(ResolX, ResolY), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    sf::Clock clock;
    float timer = 0;
    float delay = 0.1;

    SnakeArea snakeArea(ResolX / cellSize, ResolY / cellSize);
    SnakeBody snake(snakeArea);
    Apple appleObj(snakeArea, snake);

    sf::Texture snakeTexture;
    snakeTexture.loadFromFile("../images/snake.png");
    sf::Sprite snakeSprite(snakeTexture);

    sf::Texture appleTexture;
    appleTexture.loadFromFile("../images/apple.png");
    sf::Sprite appleSprite(appleTexture);

//    // run the program as long as the window is open

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        sf::Event event;
        snakeArea.drawBoard(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getDir() != RIGHT)
            snake.setDir(LEFT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getDir() != LEFT)
            snake.setDir(RIGHT);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getDir() != DOWN)
            snake.setDir(UP);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getDir() != UP)
            snake.setDir(DOWN);

        if (timer > delay && snake.getGameState()) {
            timer = 0;
            snake.snakeBody();
            appleObj.appleRandomPosition();
        }
        snake.drawSnake(window, snakeSprite);
        appleObj.drawApple(window, appleSprite);
        window.draw(appleSprite);
        window.display();
    }

    return 0;
}
