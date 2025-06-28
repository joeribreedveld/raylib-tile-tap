#ifndef TILE_H
#define TILE_H

#include "raylib.h"

struct tile {
    Vector2 position;
    /* TODO: Tile enum default, clicked, missed */
    bool clicked;
};

struct tile *tile_init(float position_y);

void tile_move(struct tile* tile);

void tile_draw(struct tile* tile);

bool tile_finished(struct tile* tile);

int tile_column(struct tile* tile);

void tile_click(struct tile* tile);

bool tile_clicked(struct tile* tile);

Vector2 tile_position(struct tile* tile);

#endif
