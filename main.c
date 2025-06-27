#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "raylib.h"
#include "tile.h"

int main() {
    const int screen_width = 400;
    const int screen_height = 600;

    InitWindow(screen_width, screen_height, "TileTap");

    SetTargetFPS(FPS);

    /* Tile init */
    struct tile* tiles[N_TILES];

    for (int i = 0; i < N_TILES; i++) {
        tiles[i] = tile_init(-i * TILE_HEIGHT);
    }

    float next_tile_y = 0;

    while (!WindowShouldClose()) {
        /* Tile logic */
        for (int i = 0; i < N_TILES; i++) {
            tile_update(tiles[i]);

            if (tile_finished(tiles[i])) {
                float latest_pos = tiles[i]->position.y;
                free(tiles[i]);

                tiles[i] = tile_init(latest_pos - TILE_HEIGHT * N_TILES);
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        /* Tile draw */
        for (int i = 0; i < N_TILES; i++) {
            tile_draw(tiles[i]);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
