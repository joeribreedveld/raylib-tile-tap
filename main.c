#include "game.h"
#include "raylib.h"

int main() {
    struct game *game = game_init();

    while (!WindowShouldClose()) {
        if (game_running(game)) {
            game_update(game);
        }

        game_draw(game);

        if (IsKeyPressed(KEY_SPACE)) {
            break;
        }
    }

    game_free(game);

    CloseWindow();

    return 0;
}
