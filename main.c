#include "raylib.h"
#include "tile.h"

#define MAX_TILES 10

int main() {
    const int screen_width = 400;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "KeyTap");

    SetTargetFPS(60);

    /* Tile init */
    struct tile* tiles[MAX_TILES];

    for (int i = 0; i < MAX_TILES; i++) {
        tiles[i] = tile_init();
    }

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        /* Tile logic */
        for (int i = 0; i < MAX_TILES; i++) {
            tile_update(tiles[i]);
            tile_draw(tiles[i]);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
