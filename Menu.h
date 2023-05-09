//
// Created by Ivan on 08/05/2023.
//

#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include "SFML/Graphics.hpp"
#include "SFMLClass.h"
#include <iostream>
class Menu {
    const int menuMaxOptionsAmount = 3;
    const int levelMaxOptionsAmount = 4;
    int optionIndex;
    sf::Font menuFont;
    sf::Text menuText[3];
    sf::Text levelsText[4];
//    sf::RenderWindow &window;

public:
    Menu(int ResolX, int ResolY);
    void levelsWindow(int ResolX, int ResolY);
    void drawMenu(sf::RenderWindow &window, sf::Text *text);
    void drawLevels(sf::RenderWindow &window, sf::Text *text);

    void moveUp(sf::Text *text);
    void moveDown(sf::Text *text);
    int optionSelected();
    sf::Text* getMenuText();
    sf::Text* getLeveltext();
    int getMenuMaxOptionsAmout() const;
    int getLevelMaxOptionsAmout() const;

};


#endif //SNAKE_MENU_H
