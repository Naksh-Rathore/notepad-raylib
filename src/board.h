#pragma once

#include "raylib.h"

struct Board {
    Image board;
    Texture2D texture;

    int boardWidth;
    int boardHeight;
};

struct Board Board_create(int boardWidth, int boardHeight, Color color);

void Board_updateTexture(const struct Board *self);
void Board_draw(const struct Board *self, int posX, int posY, Color tint);

