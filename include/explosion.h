#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "types.h"
#include "raylib.h"

Vector2 rand_x_y_circle(int r);

void draw_explosion_color(Particles *particles, Color color);

void draw_explosion(Minesweeper *game);

void step_explosion(Minesweeper *game);

void init_explosion(Rectangle rec, Minesweeper *game);

#endif