#include <stdlib.h>
#include "raylib.h"
#include "minesweeper.h"

int main(void) {
    InitWindow(800, 800, "Minesweeper");
    SetTargetFPS(60);

    Color White_b = {220, 220, 220, 255};
    Color Green_b = {126, 234, 124, 255};
    Vector2 mouse = {0, 0};

    Minesweeper *game = malloc(sizeof(Minesweeper));
    init_minesweeper(game);

    while (!WindowShouldClose()) {

        mouse = GetMousePosition();
        for (int x = 0; x < 10; x++){
            for (int y = 0; y < 10; y++){
                game->board[y][x].outside = LIGHTGRAY;
                if (CheckCollisionPointRec(mouse, game->board[y][x].rec)){
                    game->board[y][x].outside = BLACK;
                    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) game->board[y][x].inside = RED;
                    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        if (game->board[y][x].state == 0) fill_zero(game, x, y);
                        game->board[y][x].clicked = 1;
                        game->board[y][x].inside = White_b;
                    }
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_board(game);
        EndDrawing();
    }
    free(game);
    return 0;
}