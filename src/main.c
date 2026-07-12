#include "raylib.h"

#include <string.h>

#include "board.h"

int main(int argc, char **argv) {

    int screenWidth = 1920, screenHeight = 1080;

    if (argc == 2 && strcmp(argv[1], "--fullscreen") == 0) {
        SetConfigFlags(FLAG_FULLSCREEN_MODE);

        screenWidth = 0;
        screenHeight = 0;
    }

    InitWindow(screenWidth, screenHeight, "Notepad");
    SetTargetFPS(60);

    struct Board board = Board_create(2400, 1350, WHITE);

    while (!WindowShouldClose()) {
    
        Board_updateTexture(&board);

        BeginDrawing();

            ClearBackground(GRAY);
            Board_draw(&board, (screenWidth / 2.0f) - (board.boardWidth / 2.0f), (screenHeight / 2.0f) - (board.boardHeight / 2.0f), RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
