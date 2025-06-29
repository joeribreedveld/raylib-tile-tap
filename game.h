#include <stdbool.h>
#include "config.h"
#include <time.h>

struct game {
   bool is_running;
   int score;
   time_t start_time;
   struct tile *tiles[N_TILES];
   int error_col;
};

struct game *game_init();

struct game *game_reset(struct game *game);

void game_draw(struct game *game);

void game_update(struct game *game);

void game_end(struct game *game);

bool game_running(struct game *game);

void game_free(struct game *game);

void game_score_increment(struct game *game);