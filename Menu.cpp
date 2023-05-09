//
// Created by Ivan on 08/05/2023.
//

#include "Menu.h"

Menu::Menu(int ResolX, int ResolY)
{
    if (!menuFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }

    menuText[0] = {"      Play", menuFont, 80};
    menuText[0].setFillColor(sf::Color::White);
    menuText[0].setPosition(ResolX / 3.9 , ResolY / (maxOptionsAmount + 2) * 1);

    menuText[1] = {"Leaderboard", menuFont, 80};
    menuText[1].setFillColor(sf::Color::White);
    menuText[1].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (maxOptionsAmount + 2) * 2));

    menuText[2] = {"      Exit", menuFont, 80};
    menuText[2].setFillColor(sf::Color::White);
    menuText[2].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (maxOptionsAmount + 2) * 3));

    optionIndex = -1;
}

void Menu::drawMenu(sf::RenderWindow &window) {
    for (int i = 0; i < maxOptionsAmount; i++)
        window.draw(menuText[i]);
}

void Menu::moveUp() {
    std::cout << "index before: " << optionIndex << '\n';
    if (optionIndex - 1 >= -1) {
        menuText[optionIndex].setFillColor(sf::Color::White);

        optionIndex--;
    if (optionIndex == -1){
        optionIndex = 2;
    }

        menuText[optionIndex].setFillColor(sf::Color::Red);
    }
    std::cout << "index after: " << optionIndex << '\n';

}

void Menu::moveDown() {
    std::cout << "index before: " << optionIndex << '\n';
    if (optionIndex + 1 <= maxOptionsAmount) {
        menuText[optionIndex].setFillColor(sf::Color::White);

        optionIndex++;
        if (optionIndex == 3) {
            optionIndex = 0;
        }
        menuText[optionIndex].setFillColor(sf::Color::Red);
    }
    std::cout << "index after: " << optionIndex << '\n';
}

int Menu::optionSelected() {
    return optionIndex;
}
