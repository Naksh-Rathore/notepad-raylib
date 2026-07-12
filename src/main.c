#include "raylib.h"

#include <string.h>

#include "board.h"
#include "toolbox.h"

int main(int argc, char **argv) {

    int screenWidth = 0, screenHeight = 0;

    #ifndef NDEBUG
    if (argc == 2 && strcmp(argv[1], "--windowed") == 0) {
        screenWidth = 1920;
        screenHeight = 1080;
    }
    #endif

    if (argc == 2 && strcmp(argv[1], "--windowed") != 0)
        SetConfigFlags(FLAG_FULLSCREEN_MODE);


    InitWindow(screenWidth, screenHeight, "Notepad");
    SetTargetFPS(60);

    struct Board board = Board_create(2400, 1350, WHITE);
    struct ToolBox toolbox = ToolBox_create((GetScreenWidth() / 2.0f) - (2000 / 2.0f), 20, 2000, 384, 0.2, 0);

    while (!WindowShouldClose()) {
    
        Board_updateTexture(&board);

        BeginDrawing();

            ClearBackground(GRAY);
            Board_draw(&board, (screenWidth / 2.0f) - (board.boardWidth / 2.0f), (screenHeight / 2.0f) - (board.boardHeight / 2.0f), RAYWHITE);
            ToolBox_draw(&toolbox, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
