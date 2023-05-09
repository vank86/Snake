//
// Created by Ivan on 08/05/2023.
//

#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include "SFML/Graphics.hpp"
#include "SFMLClass.h"
#include <iostream>
class Menu {
    const int maxOptionsAmount = 3;
    int optionIndex;
    sf::Font menuFont;
    sf::Text menuText[3];
//    sf::RenderWindow &window;

public:
    Menu(int ResolX, int ResolY);
    void drawMenu(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int optionSelected();
};


#endif //SNAKE_MENU_H
