#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include "raylib.h"

typedef struct {
    Rectangle rec;
    Color inside;
    Color outside;
    int state;
    int clicked;
} Box;

typedef struct{
    Box board[10][10];
    Texture2D flag;
    Texture2D bomb;
    Texture2D play_again;
    Rectangle play_again_rec;
    int num_left;
} Minesweeper;

void play_again(Minesweeper *game);

void fill_zero(Minesweeper *game, int pos_x, int pos_y);

void draw_block(Minesweeper *minesweeper, int pos_x, int pos_y);

void draw_board(Minesweeper *minesweeper);

int mines_around(Minesweeper *minesweeper, int pos_x, int pos_y);

void init_minesweeper(Minesweeper *minesweeper);

#endif