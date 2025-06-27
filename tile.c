#include "tile.h"

#include <stdlib.h>

#include "config.h"

struct tile* tile_init(float position_y) {
    struct tile* tile = malloc(sizeof(struct tile));

    /* Tile random column */
    tile->position.x =
        (float)GetRandomValue(0, N_COLS - 1) * (float)GetScreenWidth() / N_COLS;
    tile->position.y = position_y;

    return tile;
}

void tile_move(struct tile* tile) {
    tile->position.y += GetFrameTime() * 100 * SPEED;
}

void tile_draw(struct tile* tile) {
    /* Draw color based on clicked state */
    Color color = tile->clicked ? LIGHTGRAY : BLACK;

    DrawRectangle(tile->position.x, tile->position.y, GetScreenWidth() / N_COLS,
                  TILE_HEIGHT, color);
}

bool tile_finished(struct tile* tile) {
    return tile->position.y >= GetScreenHeight();
}

int tile_column(struct tile* tile) {
    return tile->position.x / ((float)GetScreenWidth() / N_COLS);
}

void tile_click(struct tile* tile) { tile->clicked = true; }

bool tile_clicked(struct tile* tile) { return tile->clicked; }

Vector2 tile_position(struct tile* tile) { return tile->position; }