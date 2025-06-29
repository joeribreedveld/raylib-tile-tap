#ifndef TILE_H
#define TILE_H

#include "raylib.h"
#include "game.h"

enum tile_state {
    DEFAULT, 
    CLICKED, 
    MISSED
};

struct tile {
    Vector2 position;
    enum tile_state state;
};

struct tile *tile_init(float position_y);

void tile_move(struct game *game, struct tile *tile);

void tile_draw(struct tile *tile);

bool tile_finished(struct tile *tile);

int tile_column(struct tile *tile);

void tile_click(struct tile *tile);

bool tile_clicked(struct tile *tile);

Vector2 tile_position(struct tile *tile);

void tile_miss(struct tile *tile);

#endif
