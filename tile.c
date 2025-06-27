#include "tile.h"

#include <stdlib.h>

#include "config.h"

struct tile* tile_init(float position_y) {
    struct tile* tile = malloc(sizeof(struct tile));

    tile->position.x =
        (float)GetRandomValue(0, N_COLS - 1) * (float)GetScreenWidth() / N_COLS;
    tile->position.y = position_y;

    return tile;
}

void tile_update(struct tile* tile) {
    tile->position.y += GetFrameTime() * 100 * SPEED;
}

void tile_draw(struct tile* tile) {
    DrawRectangle(tile->position.x, tile->position.y, GetScreenWidth() / N_COLS,
                  TILE_HEIGHT, BLACK);
}

bool tile_finished(struct tile* tile) {
    return tile->position.y >= GetScreenHeight();
}