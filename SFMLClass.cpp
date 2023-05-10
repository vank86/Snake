#include "SFMLClass.h"

void gameOverText(sf::RenderWindow &window);

SFMLClass::SFMLClass(int Rx, int Ry, float delay) : ResolX(Rx), ResolY(Ry), delay(delay)
{
    this->cellSize = 25;
    this->timer = 0;
//    this->delay = 0.3;
}

void SFMLClass::menuWindow()
{
    sf::RenderWindow mainMenu(sf::VideoMode(ResolX,ResolY), "Main menu");
    Menu menu(mainMenu.getSize().x, mainMenu.getSize().y);

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
                    sf::RenderWindow playWindow(sf::VideoMode(ResolX, ResolY), "Levels");
                    sf::RenderWindow leaderBoard(sf::VideoMode(ResolX, ResolY), "Leader Board");
                    sf::RenderWindow exitGame(sf::VideoMode(ResolX, ResolY), "Exit");


//                  MENU CHOICE

                    int x = menu.optionSelected();
                    if (x == 0)
                    {
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
                            leaderBoard.close();
                            exitGame.close();
                            mainMenu.close();
                            playWindow.clear();
                            menu.drawMenu(playWindow, menu.getLeveltext());
                            playWindow.display();
                        }
                    }
                    if (x == 1)
                    {
//                        mainMenu.close();
//                        leaderBoard.close();
//                        exitGame.close();
                    }
                    if (x == 2)
                    {
                        mainMenu.close();
                        leaderBoard.close();
                        exitGame.close();
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
                                gameOver.close();
                                menuWindow();
                            }
                        }
                    }
                    gameOver.clear();
                    SFMLClass::gameOverText(gameOver);
                    gameOver.display();
                }
//                menuWindow();
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

    gameOverText = {"        Game Over\n\n Press ESC to restart", gameOverFont, 60};
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(sf::Vector2<float>(ResolX / 5.5 , ResolY / 3));
    window.draw(gameOverText);
}

int SFMLClass::getSizeOfCell() const
{
    return cellSize;
}

int SFMLClass::getResolX() {
    return ResolX;
}

int SFMLClass::getResolY() {
    return ResolY;
}


