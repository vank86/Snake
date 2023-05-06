#include <iostream>
#include "SnakeArea.h"
//#include "SnakeObject.h"
#include "SFML/Window.hpp"

//using namespace sf;



int main() {
    int cellSize = 25;
    int ResolX = 1200;
    int ResolY = 800;

    sf::RenderWindow window(sf::VideoMode(ResolX, ResolY), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

//    sf::Clock clock;
//    float timer = 0;
//    float delay = 0.5;

    SnakeArea snakeArea(ResolX / cellSize,ResolY / cellSize);
//    SnakeObject snake;

//    sf::Texture snakeHeadTexture;
//    snakeHeadTexture.loadFromFile("../images/body.png");
//    sf::Sprite snakeBody(snakeHeadTexture);
//    sf::Texture snakeBodyTexture;
//    snakeBodyTexture.loadFromFile("../images/head.png");
//    sf::Sprite snakeHead (snakeHeadTexture);
//    // run the program as long as the window is open

    while (window.isOpen())
    {
//        float time = clock.getElapsedTime().asSeconds();
//        clock.restart();
//        timer += time;

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        snakeArea.drawBoard(window);
        while (window.pollEvent(event))
        {
//            snake.snakeMove(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
//

//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//            snake.setDir(LEFT);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//            snake.setDir(RIGHT);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//            snake.setDir(UP);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//            snake.setDir(DOWN);

//        if (timer > delay) {
//            timer = 0;
//            snake.snakeBody();
//        }
//
//        for(int i = 0; i < 5; i++)
//        {
////            if (i == 0)
//            snakeHead.setTextureRect(sf::IntRect(0,0,25,25));
////            else
////                snakeBody.setTextureRect(sf::IntRect(0,0,25,25));
//            snakeHead.setPosition(sn[0].x * 25, sn[0].y * 25);
////            snakeBody.setPosition(snake[0 + i].x * 25, snake[0 + i].y*25);
//            window.draw(snakeHead);
////            window.draw(snakeBody);
//
//
//        }

        window.display();
    }

    return 0;
}
