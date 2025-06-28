#include <stdbool.h>
#include "config.h"

struct game {
   bool is_running;
   int score;
   struct tile *tiles[N_TILES];
};

struct game *game_init();

struct game *game_reset(struct game *game);

void game_draw(struct game *game);

void game_update(struct game *game);

void game_end(struct game *game);

bool game_running(struct game *game);

void game_free(struct game *game);

void game_score_increment(struct game *game);