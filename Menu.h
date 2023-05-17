
#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include "SFML/Graphics.hpp"
#include "SFMLClass.h"
#include <iostream>
#include <vector>
#include <string>



class Menu {
    const int menuMaxOptionsAmount = 3;
    const int scoreBoardAmount = 10;
    int optionIndex;
    sf::Font menuFont;
    sf::Text menuText[3];
    sf::Text levelsText[3];
    sf::Text scoreText[10];

public:
    Menu(int ResolX, int ResolY);
    void levelsWindow(int ResolX, int ResolY);

    static bool is_empty(std::ifstream& pFile);
    void scoreBoard(int ResolX, int ResolY, sf::RenderWindow &window);

    void drawMenu(sf::RenderWindow &window, sf::Text *text) const;

    void moveUp(sf::Text *text);
    void moveDown(sf::Text *text);

    int optionSelected() const;
    sf::Text* getMenuText();
    sf::Text* getLeveltext();


};


#endif //SNAKE_MENU_H
