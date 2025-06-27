#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "raylib.h"
#include "tile.h"

int main() {
    const int screen_width = 360;
    const int screen_height = 640;

    InitWindow(screen_width, screen_height, "TileTap");

    SetTargetFPS(FPS);

    /* Tile init */
    struct tile* tiles[N_TILES];

    for (int i = 0; i < N_TILES; i++) {
        tiles[i] = tile_init(-i * TILE_HEIGHT);
    }

    while (!WindowShouldClose()) {
        for (int i = 0; i < N_COLS; i++) {
            int key;

            /* Map column number to key */
            switch (i) {
                case 0:
                    key = KEY_ONE;
                    break;
                case 1:
                    key = KEY_TWO;
                    break;
                case 2:
                    key = KEY_THREE;
                    break;
                case 3:
                    key = KEY_FOUR;
                    break;
                case 4:
                    key = KEY_FIVE;
                    break;
                case 5:
                    key = KEY_SIX;
                    break;
            };

            /* TODO: End game if clicked wrong */
            if (IsKeyPressed(key)) {
                /* Find the lowest tile in the first column */
                struct tile* lowest = malloc(sizeof(struct tile));

                /* Tile clickable from screen enter point */
                lowest->position.y = -TILE_HEIGHT;

                for (int j = 0; j < N_TILES; j++) {
                    if (tile_column(tiles[j]) == i &&
                        tile_position(tiles[j]).y > lowest->position.y &&
                        !tile_clicked(tiles[j])) {
                        lowest = tiles[j];
                    }
                }

                tile_click(lowest);
            }
        }

        /* Tile logic */
        for (int i = 0; i < N_TILES; i++) {
            /* TODO: End game if unclicked key hits bottom */
            tile_move(tiles[i]);

            /* Tile generate continuous */
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

    /* Tile free */
    for (int i = 0; i < N_TILES; i++) {
        free(tiles[i]);
    }

    CloseWindow();

    return 0;
}
