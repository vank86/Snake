//
// Created by Ivan on 04/05/2023.
//

#ifndef SNAKE_GAMESTATE_H
#define SNAKE_GAMESTATE_H


class GameState {
    bool gameStatus;
public:
    GameState();
    bool getGameState() const;
    void setGameState();
};


#endif //SNAKE_GAMESTATE_H
