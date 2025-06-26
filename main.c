#include "raylib.h"

int main() {
    const int screen_width = 850;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "KeyTap");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}