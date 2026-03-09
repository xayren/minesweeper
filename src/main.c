#include <stdlib.h>
#include "raylib.h"
#include "minesweeper.h"


int main(void) {
    InitWindow(800, 800, "Minesweeper");
    SetTargetFPS(60);

    Color White_b = {190, 190, 190, 255};
    Color Green_b = {126, 234, 124, 255};
    Vector2 mouse = {0, 0};

    Game_State game_state = Game;
    Minesweeper *game = malloc(sizeof(Minesweeper));
    init_minesweeper(game);
    game->flag = LoadTexture("resources/flag.png");
    game->bomb = LoadTexture("resources/bomb.png");
    game->trophy = LoadTexture("resources/trophy.png");
    game->play_again = LoadTexture("resources/play_again.png");

    while (!WindowShouldClose()) {

        switch (game_state)
        {
        case Game:

        handle_mouse_input(game, &game_state);

        if (game->num_left <= 0){
            init_end(game);
            game_state = Victory;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_board(game);
        EndDrawing();
            break;
        
        case Victory:

        mouse = GetMousePosition();
            for (int x = 0; x < 10; x++){
                for (int y = 0; y < 10; y++){
                    game->board[y][x].outside = LIGHTGRAY;
                    if (CheckCollisionPointRec(mouse, game->board[y][x].rec)) game->board[y][x].outside = BLACK;
                    if (CheckCollisionPointRec(mouse, game->play_again_rec)){
                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                            init_minesweeper(game);
                            game_state = Game;
                        }
                    }
                }
            }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_board(game);
            DrawTexture(game->trophy, 372, 40, WHITE);
            play_again(game);
        EndDrawing();
            break;


        case Explosion:

        mouse = GetMousePosition();
            for (int x = 0; x < 10; x++){
                for (int y = 0; y < 10; y++){
                    game->board[y][x].outside = LIGHTGRAY;
                    if (CheckCollisionPointRec(mouse, game->board[y][x].rec)) game->board[y][x].outside = BLACK;
                    if (CheckCollisionPointRec(mouse, game->play_again_rec)){
                        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                            init_minesweeper(game);
                            game_state = Game;
                        }
                    }
                }
            }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_board(game);
            play_again(game);
        EndDrawing();
            break;
        }
    }

    UnloadTexture(game->flag);
    UnloadTexture(game->bomb);
    UnloadTexture(game->play_again);
    UnloadTexture(game->trophy);
    free(game);
    return 0;
}