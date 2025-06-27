#ifndef TILE_H
#define TILE_H

#include "raylib.h"

struct tile {
    Vector2 position;
    bool clicked;
};

struct tile *tile_init(int index);

void tile_update(struct tile* tile);

void tile_draw(struct tile* tile);

bool tile_finished(struct tile* tile);

#endif