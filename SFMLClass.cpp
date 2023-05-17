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

//                  menu choices
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
//                                      levels depends on delay(less -> gaster)
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
    sf::RenderWindow gameWindow(sf::VideoMode(ResolX, ResolY), "Snake");
    gameWindow.setVerticalSyncEnabled(true);
    gameWindow.setFramerateLimit(30);


    SnakeArea snakeArea(ResolX / cellSize, ResolY / cellSize);
    SnakeBody snake(snakeArea);
    Apple appleObj(snakeArea, snake);


    snakeTexture.loadFromFile("../images/snake.png");
    sf::Sprite snakeSprite(snakeTexture);

    appleTexture.loadFromFile("../images/apple.png");
    sf::Sprite appleSprite(appleTexture);

    while (gameWindow.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;


        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    gameWindow.close();
                    menuWindow();
                }
            }
        }
//        updating board sprites
        snakeArea.drawBoard(gameWindow);

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
                gameWindow.close();
                sf::RenderWindow gameOver(sf::VideoMode(ResolX, ResolY), "Game Over");
                while (gameOver.isOpen())
                {
                    sf::Event gameOverEvent;
                    while (gameOver.pollEvent(gameOverEvent)) {
                        if (gameOverEvent.type == sf::Event::Closed)
                            gameOver.close();
                        if (gameOverEvent.type == sf::Event::KeyPressed) {
                            if (gameOverEvent.key.code == sf::Keyboard::Escape) {
//                              saving result to results.txt
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
        snake.drawSnake(gameWindow, snakeSprite);
        appleObj.drawApple(gameWindow, appleSprite);
        gameWindow.draw(appleSprite);
        gameWindow.display();
    }
}


void SFMLClass::gameOverText(sf::RenderWindow &window) const
{
    sf::Font gameOverFont;
    if (!gameOverFont.loadFromFile("../fonts/arial.ttf")){
        std::cout << "Not found";
    }

    sf::Text gameOverText;

    gameOverText = {"      Your score: " + std::to_string(GameState::getScore()) +
                    "\n\n       Game Over\n\n Press ESC to restart" , gameOverFont, 60};
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(sf::Vector2<float>(static_cast<float>(ResolX) / 5.5f , static_cast<float>(ResolY) / 4.f));
    window.draw(gameOverText);
}

//  comparison function
bool SFMLClass::compare_scores(const playerScore& ps1, const playerScore& ps2) {
    return ps1.score > ps2.score;
}

void SFMLClass::playerToScoreBoard() {
//    reading all previous result from file and saving them to vector
//    to sort after the last game will be overed
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

//      saving the last result to vector
        playerScore ps;
        ps.name = "Player#";
        ps.score = GameState::getScore();
        scores.push_back(ps);

//  sorting the players scores in descending order using the compare_scores function
    std::sort(scores.begin(), scores.end(), compare_scores);

    // saving all results to .txt file
    std::ofstream outfile("../textfiles/results.txt");
    if (outfile.is_open()) {
        for (auto &score: scores) {
            outfile << score.name << " " << score.score << std::endl;
        }
        outfile.close();
    }
}
// checking if the file is empty (described in Menu.cpp)
bool SFMLClass::is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

