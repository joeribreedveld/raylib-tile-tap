#include "game.h"

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "raylib.h"
#include "tile.h"

struct game *game_init() {
    struct game *game = malloc(sizeof(struct game));

    const int screen_width = 360;
    const int screen_height = 640;

    InitWindow(screen_width, screen_height, "TileTap");

    SetTargetFPS(FPS);

    game->score = 0;
    game->is_running = 1;

    for (int i = 0; i < N_TILES; i++) {
        game->tiles[i] = malloc(sizeof(struct tile));
        game->tiles[i] = tile_init(-i * TILE_HEIGHT);
    }

    return game;
}

void game_reset(struct game *game) {
    game->score = 0;
    game->is_running = 1;
}

void game_draw(struct game *game) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    /* Tile draw */
    for (int i = 0; i < N_TILES; i++) {
        tile_draw(game->tiles[i]);
    }

    EndDrawing();
}

void game_update(struct game *game) {
    /* TODO: Abstract this to other file */
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

        if (IsKeyPressed(key)) {
            bool found = false;
            /* Find the lowest tile in the first column */
            struct tile *lowest = malloc(sizeof(struct tile));

            /* Tile clickable from screen enter point */
            lowest->position.y = -TILE_HEIGHT;

            for (int j = 0; j < N_TILES; j++) {
                if (tile_column(game->tiles[j]) == i &&
                    tile_position(game->tiles[j]).y > lowest->position.y &&
                    !tile_clicked(game->tiles[j])) {
                    lowest = game->tiles[j];
                    found = true;
                }
            }

            if (!found) {
                game_end(game);
            }

            tile_click(lowest);
        }
    }

    /* Tile logic */
    for (int i = 0; i < N_TILES; i++) {
        /* TODO: End game if unclicked key hits bottom */
        tile_move(game->tiles[i]);

        /* Tile generate continuous */
        if (tile_finished(game->tiles[i])) {
            float latest_pos = game->tiles[i]->position.y;
            free(game->tiles[i]);

            game->tiles[i] = tile_init(latest_pos - TILE_HEIGHT * N_TILES);
        }
    }
}

void game_end(struct game *game) { game->is_running = false; }

bool game_running(struct game *game) { return game->is_running; }

void game_free(struct game *game) {
    for (int i = 0; i < N_TILES; i++) {
        free(game->tiles[i]);
    }

    free(game);
}