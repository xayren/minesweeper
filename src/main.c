#include <stdlib.h>
#include "raylib.h"
#include "minesweeper.h"

typedef enum {
    Game,
    Explosion
} Game_State;

int main(void) {
    InitWindow(800, 800, "Minesweeper");
    SetTargetFPS(60);

    Color White_b = {220, 220, 220, 255};
    Color Green_b = {126, 234, 124, 255};
    Vector2 mouse = {0, 0};

    Game_State game_state = Game;
    Minesweeper *game = malloc(sizeof(Minesweeper));
    init_minesweeper(game);
    game->flag = LoadTexture("resources/flag.png");
    game->bomb = LoadTexture("resources/bomb.png");

    while (!WindowShouldClose()) {

        switch (game_state)
        {
        case Game:
        mouse = GetMousePosition();
        for (int x = 0; x < 10; x++){
            for (int y = 0; y < 10; y++){
                game->board[y][x].outside = LIGHTGRAY;
                if (CheckCollisionPointRec(mouse, game->board[y][x].rec)){
                    game->board[y][x].outside = BLACK;
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                        if (game->board[y][x].state == 0) fill_zero(game, x, y);
                        else if (game->board[y][x].state == -1){
                            game_state = Explosion;
                        }
                        game->board[y][x].clicked = 1;
                        game->board[y][x].inside = White_b;
                    }
                    else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
                        if (game->board[y][x].clicked == 1) continue;
                        if (game->board[y][x].clicked == 0) game->board[y][x].clicked = 2;
                        else if (game->board[y][x].clicked == 2) game->board[y][x].clicked = 0;
                    }
                }
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_board(game);
        EndDrawing();
            break;
        
        case Explosion:
        BeginDrawing();

        EndDrawing();
            break;
        }
    }

    UnloadTexture(game->flag);
    free(game);
    return 0;
}