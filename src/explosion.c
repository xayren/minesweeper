#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "explosion.h"
#include "minesweeper.h"


Vector2 rand_x_y_circle(int r)
{
    Vector2 result;
    float angle = GetRandomValue(0, 360) * PI / 180;
    float dist = (float)GetRandomValue(0, r * 1000000) / 1000000.0F;
    result.x = dist * cos(angle);
    result.y = dist * sin(angle);
    return result;
}


void draw_explosion(Particles *particles)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        Particle *p = &particles->particle[i];
        DrawRectangle(p->rec.x, p->rec.y, p->rec.width, p->rec.width, RED);
    }
}


void step_explosion(Particles *particles)
{

    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        Particle *p = &particles->particle[i];
        p->rec.x += p->vel.x;
        p->rec.y += p->vel.y;
    }
}


void init_explosion(Rectangle rec, Particles *particles)
{
    Particle template = {(Rectangle){0, 0, 3, 3}, (Vector2){0, 0}, 0.0F};
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        Vector2 tmp = rand_x_y_circle(5);
        template.rec.x = tmp.x + rec.x + 15;
        template.rec.y = tmp.y + rec.y + 15;
        template.vel = rand_x_y_circle(5);
        particles->particle[i] = template;
    }
}