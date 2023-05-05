#include <iostream>
#include "SFML/Window.hpp"
#include "SnakeArea.h"
#include "SnakeObject.h"
int main() {

    sf::RenderWindow window(sf::VideoMode(1900, 1200), "Grafika w C++/SFML", sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    SnakeArea snakeArea(100,100);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        snakeArea.drawBoard(window);
        window.display();
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
    }

    return 0;
}
