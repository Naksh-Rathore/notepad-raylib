#include "raylib.h"

int main() {
    const int screenWidth = 800, screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Notepad");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("Notepad", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
