#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "raylib.h"

typedef struct {
    Rectangle rec;
    Color inside;
    Color outside;
} Box;

typedef struct {
    Box board[10][10];
} Minesweeper;

void draw_block(Minesweeper *minesweeper, int pos_x, int pos_y);

void draw_board(Minesweeper *minesweeper);

void init_minesweeper(Minesweeper *minesweeper);

#endif