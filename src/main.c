#include "raylib.h"
#include "minesweeper.h"

int main(void) {
    InitWindow(800, 800, "Minesweeper");
    SetTargetFPS(60);

    Minesweeper game;
    init_minesweeper(&game);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_board(&game);
        EndDrawing();
    }
    return 0;
}