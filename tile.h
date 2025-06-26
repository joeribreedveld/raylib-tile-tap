#ifndef TILE_H
#define TILE_H

#include "raylib.h"

struct tile {
    Vector2 position;
    bool clicked;
};

struct tile *tile_init();

void tile_update(struct tile* tile);

void tile_draw(struct tile* tile);

bool tile_clicked(struct tile* tile);

Vector2 tile_position(struct tile* tile);

#endif