//
//  sprite.cpp
//  TicTacToeGame
//
//  Created by Henry Cevallos on 11/4/19.
//  Copyright © 2019 Henry Cevallos. All rights reserved.
//

#include "sprite.hpp"
#include "graphics.hpp"
#include "globals.hpp"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
        float posX, float posY) :
                _x(posX),
                _y(posY)
{
    this->_sourceRect.x = sourceX;
    this->_sourceRect.y = sourceY;
    this->_sourceRect.w = width;
    this->_sourceRect.h = height;

    this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
    if (this->_spriteSheet == NULL) {
        printf("\nError: Unable to load image\n");
    }

}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y) {
    SDL_Rect destinationRectangle = { x, y, static_cast<int>(this->_sourceRect.w * globals::SPRITE_SCALE),
        static_cast<int>(this->_sourceRect.h * globals::SPRITE_SCALE) };
    graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::update() {}
