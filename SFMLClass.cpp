#include "SFMLClass.h"


SFMLClass::SFMLClass(int Rx, int Ry) : ResolX(Rx), ResolY(Ry)
{
    this->cellSize = 25;
    this->timer = 0;
    this->delay = 0;
    menuWindow();
}

void SFMLClass::menuWindow()
{
    sf::RenderWindow mainMenu(sf::VideoMode(ResolX,ResolY), "Main menu");
    Menu menu(mainMenu.getSize().x, mainMenu.getSize().y);
    GameState::resetScore();
//  Main menu window  with UP/DOWN moves:

    while (mainMenu.isOpen())
    {
        sf::Event event;
        while (mainMenu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mainMenu.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    mainMenu.close();
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    menu.moveUp(menu.getMenuText());
                    break;
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    menu.moveDown(menu.getMenuText());
                    break;
                }
                if (event.key.code == sf::Keyboard::Return)
                {

//                  MENU CHOICE

                    int x = menu.optionSelected();
                    if (x == 0)
                    {
                        sf::RenderWindow playWindow(sf::VideoMode(ResolX, ResolY), "Levels");
                        menu.levelsWindow(playWindow.getSize().x, playWindow.getSize().y);
                        while (playWindow.isOpen())
                        {
                            sf::Event playEvent;
                            while (playWindow.pollEvent(playEvent))
                            {
                                if (playEvent.type == sf::Event::Closed)
                                {
                                    playWindow.close();
                                }
                                if (playEvent.type == sf::Event::KeyPressed)
                                {
                                    if(playEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        playWindow.close();
                                        menuWindow();
                                    }
                                }
                                if (playEvent.type == sf::Event::KeyReleased) {
                                    if (playEvent.key.code == sf::Keyboard::Up) {
                                        menu.moveUp(menu.getLeveltext());
                                        break;
                                    }
                                    if (playEvent.key.code == sf::Keyboard::Down) {
                                        menu.moveDown(menu.getLeveltext());
                                        break;
                                    }
                                    if (event.key.code == sf::Keyboard::Return)
                                    {
                                        int z = menu.optionSelected();
                                        if (z == 0) {
                                            playWindow.close();
                                            delay = 0.2;
                                            initGame();
                                        }
                                        if (z == 1) {
                                            playWindow.close();
                                            delay = 0.1;
                                            initGame();
                                        }
                                        if (z == 2) {
                                            playWindow.close();
                                            delay = 0.01;
                                            initGame();
                                        }
                                    }
                                }
                            }
                            mainMenu.close();
                            playWindow.clear();
                            menu.drawMenu(playWindow, menu.getLeveltext());
                            playWindow.display();
                        }
                    }
                    if (x == 1)
                    {
                        sf::RenderWindow leaderBoard(sf::VideoMode(ResolX, ResolY), "Leader Board");
                        while (leaderBoard.isOpen())
                        {
                            sf::Event leaderEvent;
                            while (leaderBoard.pollEvent(leaderEvent))
                            {
                                if (leaderEvent.type == sf::Event::Closed)
                                {
                                    leaderBoard.close();
                                }
                                if (leaderEvent.type == sf::Event::KeyPressed)
                                {
                                    if(leaderEvent.key.code == sf::Keyboard::Escape)
                                    {
                                        leaderBoard.close();
                                        menuWindow();
                                    }
                                }
                            }

                            mainMenu.close();
                            leaderBoard.clear();
                            menu.scoreBoard(leaderBoard.getSize().x, leaderBoard.getSize().y, leaderBoard);
                            leaderBoard.display();
                        }
//                        mainMenu.close();
//                        leaderBoard.close();
//                        exitGame.close();
                    }
                    if (x == 2)
                    {
                        mainMenu.close();
                    }

                }
            }
        }
        mainMenu.clear();
        menu.drawMenu(mainMenu, menu.getMenuText());
        mainMenu.display();
    }

}

void SFMLClass::initGame()
{
    sf::RenderWindow window(sf::VideoMode(ResolX, ResolY), "Snake");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

//    Menu menu(window.getSize().x, window.getSize().y);

    SnakeArea snakeArea(ResolX / cellSize, ResolY / cellSize);
    SnakeBody snake(snakeArea);
    Apple appleObj(snakeArea, snake);

    snakeTexture.loadFromFile("../images/snake.png");
    sf::Sprite snakeSprite(snakeTexture);


    appleTexture.loadFromFile("../images/apple.png");
    sf::Sprite appleSprite(appleTexture);

////    // run the program as long as the window is open
//    window.clear();
////    menu.drawMenu(window);
//    window.display();

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    menuWindow();
                }
            }
        }
        snakeArea.drawBoard(window);

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
            if (!snake.getGameState()){
                window.close();
                sf::RenderWindow gameOver(sf::VideoMode(ResolX, ResolY), "Game Over");
                while (gameOver.isOpen())
                {
                    sf::Event gameOverEvent;
                    while (gameOver.pollEvent(gameOverEvent)) {
                        if (gameOverEvent.type == sf::Event::Closed)
                            gameOver.close();
                        if (gameOverEvent.type == sf::Event::KeyPressed) {
                            if (gameOverEvent.key.code == sf::Keyboard::Escape) {
                                playerToScoreBoard();
                                gameOver.close();
                                menuWindow();
                            }
                        }
                    }
                    gameOver.clear();
                    SFMLClass::gameOverText(gameOver);
                    gameOver.display();
                }
            }
        }
        snake.drawSnake(window, snakeSprite);
        appleObj.drawApple(window, appleSprite);
        window.draw(appleSprite);
        window.display();
    }
}


void SFMLClass::gameOverText(sf::RenderWindow &window)
{
    sf::Font gameOverFont;
    if (!gameOverFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }
    sf::Text gameOverText;


//    "\n       Game Over\n\n Press ESC to restart"
    gameOverText = {"      Your score: " + std::to_string(GameState::getScore()) +
                    "\n\n       Game Over\n\n Press ESC to restart" , gameOverFont, 60};
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(sf::Vector2<float>(static_cast<float>(ResolX) / 5.5f , static_cast<float>(ResolY) / 4.f));
    window.draw(gameOverText);
}

int SFMLClass::getSizeOfCell() const
{
    return cellSize;
}

int SFMLClass::getResolX() const {
    return ResolX;
}

int SFMLClass::getResolY() const {
    return ResolY;
}

bool SFMLClass::compare_scores(playerScore ps1, playerScore ps2) {
    return ps1.score > ps2.score;
}

void SFMLClass::playerToScoreBoard() {
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

    // get the number of players and their scores from user input
        playerScore ps;
//        std::cout << "Enter the name of player: ";
        ps.name = "Player#";
        ps.score = GameState::getScore();
        scores.push_back(ps);

    // sort the player scores in descending order using the compare_scores function
    std::sort(scores.begin(), scores.end(), compare_scores);

    // create a file stream and write the player scores to the file in descending order
    std::ofstream outfile("../textfiles/results.txt");
    if (outfile.is_open()) {
        for (auto &score: scores) {
            outfile << score.name << " " << score.score << std::endl;
        }
        outfile.close();
    }

//        std::cout << "Scores saved to file.";
//    } else {
////        std::cout << "Error: unable to open file.";
//    }
}

bool SFMLClass::is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

std::vector<playerScore> SFMLClass::getScoreBoard() {
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
    return scores;
}
