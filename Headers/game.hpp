//
//  game.hpp
//  TicTacToeGame
//
//  Created by Henry Cevallos on 11/2/19.
//  Copyright © 2019 Henry Cevallos. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#include "player.hpp"
#include "level.hpp"

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Player _player;
    Level _level;
};

#endif

