#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "raylib.h"
#include "tile.h"

struct game *game_init() {
    struct game *game = malloc(sizeof(struct game));

    /* TODO: figure out what kind of globals to use where */

    game->score = 0;
    game->is_running = 1;
    game->start_time = time(NULL);
    game->error_col = -1;

    for (int i = 0; i < N_TILES; i++) {
        game->tiles[i] = malloc(sizeof(struct tile));
        game->tiles[i] = tile_init(-i * TILE_HEIGHT - TILE_HEIGHT);
    }

    return game;
}

struct game *game_reset(struct game *game) {
    game_free(game);

    struct game *new_game = game_init();

    return new_game;
}

void game_draw(struct game *game) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    char score_string[12];
    snprintf(score_string, sizeof(score_string), "%d", game->score);

    /* Col missclick user feedback */
    if (game->error_col != -1) {
        Color red_transparent = GetColor(0xFF000040);

        DrawRectangle(game->error_col * (GetScreenWidth() / N_COLS), 0,
                      GetScreenWidth() / N_COLS, GetScreenHeight(),
                      red_transparent);
    }

    /* Tile draw */
    for (int i = 0; i < N_TILES; i++) {
        tile_draw(game->tiles[i]);
    }

    /* Score draw */
    DrawText(score_string,
             (GetScreenWidth() - MeasureText(score_string, 64)) / 2, 30, 64,
             GRAY);

    /* TODO: Game start and end screens */

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
                /* Handle wrong column click */
                game->error_col = i;
                game_end(game);
            } else {
                tile_click(lowest);
                game_score_increment(game);
            }
        }
    }

    /* Tile logic */
    for (int i = 0; i < N_TILES; i++) {
        tile_move(game, game->tiles[i]);

        /* Tile generate continuous */
        if (tile_finished(game->tiles[i])) {
            /* Handle game end and feedback on tile miss */
            if (game->tiles[i]->state != CLICKED) {
                game->tiles[i]->state = MISSED;
                game_end(game);
            }

            float latest_pos = game->tiles[i]->position.y;
            if (game->tiles[i]->state == CLICKED &&
                game->tiles[i]->position.y >= GetScreenHeight()) {
                free(game->tiles[i]);
                game->tiles[i] = tile_init(latest_pos - TILE_HEIGHT * N_TILES);
            }
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

void game_score_increment(struct game *game) { game->score++; }
