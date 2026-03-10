#include <stdlib.h>
#include "raylib.h"
#include "minesweeper.h"


int main(void) {
    InitWindow(800, 800, "Minesweeper");
    SetTargetFPS(60);

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

            mouse_liner(game);
            handle_mouse_input(game, &game_state);

            if (game->num_left <= 0){
                init_end(game);
                game_state = Victory;
            }

        BeginDrawing();
            draw_board(game);
        EndDrawing();
            break;
        
        case Victory:

            mouse_liner(game);
            play_again(game, &game_state);

        BeginDrawing();
            draw_board(game);
            DrawTexture(game->trophy, 372, 40, WHITE);
            play_again_draw(game);
        EndDrawing();
            break;


        case Explosion:

            mouse_liner(game);
            play_again(game, &game_state);

        BeginDrawing();
            draw_board(game);
            play_again_draw(game);
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