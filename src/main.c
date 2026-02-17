#include <stdlib.h>
#include "raylib.h"
#include "minesweeper.h"

int main(void) {
    InitWindow(800, 800, "Minesweeper");
    SetTargetFPS(60);

    Color White_b = {242, 234, 212, 255};
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
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) game->board[y][x].inside = Green_b;
                    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                        game->board[y][x].clicked = 1;
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