#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "raylib.h"

int main() {
    const int screen_width = 360;
    const int screen_height = 640;

    InitWindow(screen_width, screen_height, "Tile Tap");

    SetTargetFPS(FPS);

    struct game *game = game_init();

    while (!WindowShouldClose()) {
        if (game_running(game)) {
            game_update(game);
        }

        game_draw(game);

        if (!game_running(game)) {
            if (IsKeyPressed(KEY_ESCAPE)) {
                break;
            }

            /* Restart game */
            if (IsKeyPressed(KEY_SPACE)) {
                game = game_reset(game);
            }
        }
    }

    game_free(game);

    CloseWindow();

    return 0;
}
