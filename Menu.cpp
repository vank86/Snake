
#include "Menu.h"


Menu::Menu(int ResolX, int ResolY)
{
    if (!menuFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }
//      main menu objects
    menuText[0] = {"      Play", menuFont, 80};
    menuText[0].setFillColor(sf::Color::Red);
    menuText[0].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (menuMaxOptionsAmount + 2) * 1));

    menuText[1] = {"Leaderboard", menuFont, 80};
    menuText[1].setFillColor(sf::Color::White);
    menuText[1].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (menuMaxOptionsAmount + 2) * 2));

    menuText[2] = {"      Exit", menuFont, 80};
    menuText[2].setFillColor(sf::Color::White);
    menuText[2].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (menuMaxOptionsAmount + 2) * 3));

//  menu option selected (start)
    optionIndex = 0;
}

void Menu::levelsWindow(int ResolX, int ResolY){
    if (!menuFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }
//      main menu -> levels objects

    levelsText[0] = {" Easy Level", menuFont, 80};
    levelsText[0].setFillColor(sf::Color::Red);
    levelsText[0].setPosition(sf::Vector2<float>(ResolX / 4 , ResolY / (menuMaxOptionsAmount + 2) * 1));

    levelsText[1] = {"Medium level", menuFont, 80};
    levelsText[1].setFillColor(sf::Color::White);
    levelsText[1].setPosition(sf::Vector2<float>(ResolX / 4 , ResolY / (menuMaxOptionsAmount + 2) * 2));

    levelsText[2] = {"  Hard level", menuFont, 80};
    levelsText[2].setFillColor(sf::Color::White);
    levelsText[2].setPosition(sf::Vector2<float>(ResolX / 4 , ResolY / (menuMaxOptionsAmount + 2) * 3));


    optionIndex = 0;
}

bool Menu::is_empty(std::ifstream& pFile)
{
/*    function to check if file is empty
 *    this function is need for read all the previous results
 *    and write them to vector, otherwise we will get
 *    playerScore->name = "", playerScore->score = 0/1/2 (from previous results)
 */

    return pFile.peek() == std::ifstream::traits_type::eof();
}

void Menu::scoreBoard(int ResolX, int ResolY, sf::RenderWindow &window){
    if (!menuFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }

/*   read previous results from file and write them to vector
 *   and show them as a list (Menu -> Leaderboard)
 *   [sorting is in SFMLClass]
 */
    std::vector<playerScore> scores {};
    std::ifstream infile("../textfiles/results.txt");
    if (infile.is_open()) {
        while (!infile.eof()) {
            playerScore ps;
            if (!is_empty(infile)) {
                infile >> ps.name >> ps.score;
                if (ps.name.empty())
                    break;
                scores.push_back(ps);
            }
        }
        infile.close();
    }

    for (int i = 0; i < 10; ++i)
    {
        if (i == 9)
        {
            scoreText[i] = {"\n" + scores[i].name + " " + std::to_string(i+1) + "      "
                            + std::to_string(scores[i].score), menuFont, 55};
            scoreText[i].setFillColor(sf::Color::Red);
            scoreText[i].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (scoreBoardAmount + 2) * i+1));
            window.draw(scoreText[i]);
            continue;
        }
        scoreText[i] = {"\n" + scores[i].name + " " + std::to_string(i+1) + "        "
                        + std::to_string(scores[i].score), menuFont, 55};
        scoreText[i].setFillColor(sf::Color::Red);
        scoreText[i].setPosition(sf::Vector2<float>(ResolX / 3.9 , ResolY / (scoreBoardAmount + 2) * i+1));
        window.draw(scoreText[i]);
    }

    optionIndex = 0;
}

void Menu::drawMenu(sf::RenderWindow &window, sf::Text *text) const {
    for (int i = 0; i < menuMaxOptionsAmount; i++)
        window.draw(text[i]);
}


// moving through menu options with a keyboard

void Menu::moveUp(sf::Text *text) {
    if (optionIndex - 1 >= -1) {
        text[optionIndex].setFillColor(sf::Color::White);

        optionIndex--;
    if (optionIndex == -1){
        optionIndex = 2;
    }

        text[optionIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::moveDown(sf::Text *text) {
    if (optionIndex + 1 <= 3) {
        text[optionIndex].setFillColor(sf::Color::White);

        optionIndex++;
        if (optionIndex == 3) {
            optionIndex = 0;
        }
        text[optionIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::optionSelected() const {
    return optionIndex;
}

sf::Text *Menu::getMenuText() {
    return menuText;
}

sf::Text *Menu::getLeveltext() {
    return levelsText;
}
