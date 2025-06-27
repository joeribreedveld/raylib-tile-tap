#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "tile.h"

#define MAX_TILES 10
#define TILE_HEIGHT 150

int main() {
    const int screen_width = 400;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "TileTap");

    SetTargetFPS(60);

    /* Tile init */
    struct tile* tiles[MAX_TILES];

    for (int i = 0; i < MAX_TILES; i++) {
        tiles[i] = tile_init(-i * TILE_HEIGHT);
    }

    float next_tile_y = 0;

    while (!WindowShouldClose()) {
        /* Tile logic */
        for (int i = 0; i < MAX_TILES; i++) {
            tile_update(tiles[i]);

            if (tile_finished(tiles[i])) {
                float latest_pos = tiles[i]->position.y;
                free(tiles[i]);

                tiles[i] = tile_init(latest_pos - TILE_HEIGHT * MAX_TILES);
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        /* Tile draw */
        for (int i = 0; i < MAX_TILES; i++) {
            tile_draw(tiles[i]);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
