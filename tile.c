#include "tile.h"

#include <stdlib.h>

#define SPEED 4
#define TILE_WIDTH 100
#define TILE_HEIGHT 150

struct tile* tile_init(int index) {
    struct tile* tile = malloc(sizeof(struct tile));

    tile->position.x = GetRandomValue(0, 3) * 100;
    tile->position.y = -index * TILE_HEIGHT;

    return tile;
}

void tile_update(struct tile* tile) {
    tile->position.y += GetFrameTime() * 100 * SPEED;
}

void tile_draw(struct tile* tile) {
    DrawRectangle(tile->position.x, tile->position.y, TILE_WIDTH, TILE_HEIGHT,
                  BLACK);
}

bool tile_finished(struct tile* tile) {
    return tile->position.y >= GetScreenHeight();
}