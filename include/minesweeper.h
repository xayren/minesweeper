#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "types.h"
#include "raylib.h"

int flags_around(Minesweeper *game, int x, int y);

void is_victory(Minesweeper *game, Game_State *game_state);

void free_game(Minesweeper *game);

void init_game(Minesweeper *minesweeper);

void play_again(Minesweeper *game, Game_State *game_state);

void mouse_liner(Minesweeper *game);

void handle_LMB(Minesweeper *game, Game_State *game_State, int x, int y);

void handle_RMB(Minesweeper *game, Game_State *game_State, int x, int y);

void handle_mouse_input(Minesweeper *game, Game_State *game_state);

void init_end(Minesweeper *game);

void trophy_draw(Minesweeper *game);

void play_again_draw(Minesweeper *game);

void fill_zero(Minesweeper *game, int pos_x, int pos_y);

void draw_block(Minesweeper *minesweeper, int pos_x, int pos_y);

void draw_board(Minesweeper *minesweeper);

int mines_around(Minesweeper *minesweeper, int pos_x, int pos_y);

void init_minesweeper(Minesweeper *minesweeper);

#endif