//
// Created by Ivan on 04/05/2023.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions" // for inline static int score


#ifndef SNAKE_GAMESTATE_H
#define SNAKE_GAMESTATE_H

#include <iostream>
class GameState {
    bool gameStatus;
    inline static int score;
public:
    GameState();
    bool getGameState() const;
    void setGameState();
    static int getScore();
    static void increaseScore();
    static void showScore();
};


#endif //SNAKE_GAMESTATE_H

#pragma clang diagnostic pop