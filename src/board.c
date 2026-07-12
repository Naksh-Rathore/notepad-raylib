#include "board.h"

#include "raylib.h"

struct Board Board_create(int boardWidth, int boardHeight, Color color) {
    struct Board board;

    board.board = GenImageColor(boardWidth, boardHeight, color);
    board.texture = LoadTextureFromImage(board.board);

    board.boardWidth = boardWidth;
    board.boardHeight = boardHeight;

    return board;
}

void Board_updateTexture(const struct Board *self) {
    UpdateTexture(self->texture, self->board.data);
}

void Board_draw(const struct Board *self, int posX, int posY, Color tint) {

    float screenCenterX = GetScreenWidth() / 2.0f;
    float screenCenterY = GetScreenHeight() / 2.0f;

    Rectangle sourceRec = { 0.0f, 0.0f, (float) self->texture.width, (float) self->texture.height };
    Rectangle destRec = { screenCenterX, screenCenterY, (float) self->texture.width, (float) self->texture.height };

    Vector2 origin = { (float) self->texture.width / 2.0f, (float) self->texture.height / 2.0f };

    DrawTexturePro(self->texture, sourceRec, destRec, origin, 0.0f, WHITE);
}

