#include "tile.h"

#include <math.h>
#include <stdlib.h>

#include "config.h"

struct tile *tile_init(float position_y) {
    struct tile *tile = malloc(sizeof(struct tile));

    /* Tile random column */
    tile->position.x =
        (float)GetRandomValue(0, N_COLS - 1) * (float)GetScreenWidth() / N_COLS;
    tile->position.y = position_y;
    tile->state = DEFAULT;

    return tile;
}

void tile_move(struct game *game, struct tile *tile) {
    tile->position.y +=
        GetFrameTime() * 100 * SPEED * sqrt(time(NULL) - game->start_time) / 10;
}

void tile_draw(struct tile *tile) {
    /* Draw color based on clicked state */
    Color color;

    switch (tile->state) {
        case CLICKED:
            color = LIGHTGRAY;
            break;
        case MISSED:
            color = RED;
            break;
        case DEFAULT:
            color = BLACK;
            break;
        default:
            color = BLACK;
            break;
    }

    DrawRectangle(tile->position.x, tile->position.y, GetScreenWidth() / N_COLS,
                  TILE_HEIGHT, color);
}

bool tile_finished(struct tile *tile) {
    return tile->position.y >= GetScreenHeight() - TILE_HEIGHT;
}

int tile_column(struct tile *tile) {
    return tile->position.x / ((float)GetScreenWidth() / N_COLS);
}

void tile_click(struct tile *tile) { tile->state = CLICKED; }

bool tile_clicked(struct tile *tile) { return tile->state == CLICKED; }

Vector2 tile_position(struct tile *tile) { return tile->position; }

void tile_miss(struct tile *tile) { tile->state = MISSED; }