#include "minesweeper.h"


void draw_block(Minesweeper *minesweeper, int pos_x, int pos_y)
{
    Box *game = &minesweeper->board[pos_y][pos_x];
    DrawRectangle(game->rec.x, game->rec.y, game->rec.width, game->rec.height, game->inside);
    DrawRectangleLines(game->rec.x, game->rec.y, game->rec.width, game->rec.height, game->outside);
}


void draw_board(Minesweeper *minesweeper)
{
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            draw_block(minesweeper, x, y);
        }
    }
}


void init_minesweeper(Minesweeper *minesweeper) {
    Rectangle rec = {250, 250, 30, 30};
    Box template = {rec, (Color){242, 234, 212, 255}, LIGHTGRAY };

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            minesweeper->board[y][x] = template;
            template.rec.y += 30;
        }
        template.rec.y = 250;
        template.rec.x += 30;
    }
}