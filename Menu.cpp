//
// Created by Ivan on 08/05/2023.
//

#include "Menu.h"

Menu::Menu(int ResolX, int ResolY)
{
    if (!menuFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }
//
//
//    font.loadFromFile("../font/arial.ttf");
//    sf::Text text("GAME OVER", font, 80);
//    text.setFillColor(sf::Color::Red);
//    text.setPosition(board.getSizeOfCell() * 2.4, board.getSizeOfCell() * 3);
//
    menuText[0] = {"Play", menuFont, 80};
    menuText[0].setFillColor(sf::Color::Red);
    menuText[0].setPosition(ResolX / 2.5 , ResolY / (maxOptionsAmount + 2) * 1);

    menuText[1] = {"Level", menuFont, 80};
    menuText[1].setFillColor(sf::Color::White);
    menuText[1].setPosition(sf::Vector2<float>(ResolX / 2.5 , ResolY / (maxOptionsAmount + 2) * 2));

    menuText[2] = {"Exit", menuFont, 80};
    menuText[2].setFillColor(sf::Color::White);
    menuText[2].setPosition(sf::Vector2<float>(ResolX / 2.5 , ResolY / (maxOptionsAmount + 2) * 3));

}

void Menu::drawMenu(sf::RenderWindow &window) {
    for (int i = 0; i < maxOptionsAmount; i++)
        window.draw(menuText[i]);
}
