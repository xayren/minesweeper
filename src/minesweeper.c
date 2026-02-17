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


int mines_around(Minesweeper *minesweeper, int pos_x, int pos_y)
{
    int result = 0;
    for (int y = -1; y < 2; y++){
        for (int x = -1; x < 2; x++){
            if (y == 0 && x == 0) continue;
            if (pos_x + x < 0 || pos_x + x >= 10) continue;
            if (pos_y + y < 0 || pos_y + y >= 10) continue;
            if (minesweeper->board[pos_y + y][pos_x + x].state == -1) result++;
        }
    }
    return result;
}


void init_minesweeper(Minesweeper *minesweeper) {
    Rectangle rec = {250, 250, 30, 30};
    Box template = {rec, (Color){242, 234, 212, 255}, LIGHTGRAY , 0};

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            minesweeper->board[y][x] = template;
            template.rec.y += 30;
        }
        template.rec.y = 250;
        template.rec.x += 30;
    }
}