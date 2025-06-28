#include "game.h"
#include "raylib.h"

int main() {
    struct game *game = game_init();

    const int screen_width = 360;
    const int screen_height = 640;

    InitWindow(screen_width, screen_height, "TileTap");

    SetTargetFPS(FPS);

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
