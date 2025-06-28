#include "game.h"
#include "raylib.h"

int main() {
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
