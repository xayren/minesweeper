#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "raylib.h"

#define MAX_PARTICLES 500

typedef struct
{
    Rectangle rec;
    Vector2 vel;
    float timer;
} Particle;

typedef struct
{
    Particle particle[MAX_PARTICLES];
} Particles;

Vector2 rand_x_y_circle(int r);

void draw_explosion(Particles *particles);

void step_explosion(Particles *particles);

void init_explosion(Rectangle rec, Particles *particles);

#endif