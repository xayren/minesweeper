#include <math.h>
#include "raylib.h"
#include "types.h"
#include "explosion.h"


Vector2 rand_x_y_circle(int r)
{
    Vector2 result;
    float angle = GetRandomValue(0, 360) * PI / 180;
    float dist = (float)GetRandomValue(0, r * 1000000) / 1000000.0F;
    result.x = dist * cos(angle);
    result.y = dist * sin(angle);
    return result;
}


void draw_explosion_color(Particles *particles, Color color)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        Particle *p = &particles->particle[i];
        DrawRectangle(p->rec.x, p->rec.y, p->rec.width, p->rec.height, color);
    }
}


void draw_explosion(Minesweeper *game)
{
    Color color = (Color){255, 0, 0, 255};
    for (int i = 0; i < NUM_OF_COLORS; i ++)
    {
        color.g += CHANGE_COLOR;
        draw_explosion_color(&game->explosion[i], color);
    }
}


void step_explosion(Minesweeper *game)
{
    game->timer += GetFrameTime();
    for (int j = 0; j < NUM_OF_COLORS; j++)
    {
        for (int i = 0; i < MAX_PARTICLES; i++)
        {
            Particle *p = &game->explosion[j].particle[i];
            p->rec.x += p->vel.x;
            p->rec.y += p->vel.y;
            if (game->timer > 0.05F && p->rec.width > 0)
            {
                p->rec.width -= 0.4F;
                p->rec.height -= 0.4F;
                p->vel.x *= 0.7F;
                p->vel.y *= 0.7F;
            }
            if (p->rec.width < 0)
            {
                p->rec.width = 0.0F;
                p->rec.height = 0.0F;
            }
        }
    }
    if (game->timer > 0.05F) game->timer = 0.0F;
}


void init_explosion(Rectangle rec, Minesweeper *game)
{
    game->timer = 0.0F;
    Particle template = {(Rectangle){0, 0, 9, 9}, (Vector2){0, 0}};
    for (int i = 0; i < NUM_OF_COLORS; i++)
    {
        for (int j = 0; j < MAX_PARTICLES; j++)
        {
            Vector2 tmp = rand_x_y_circle(5);
            template.rec.x = tmp.x + rec.x + 15;
            template.rec.y = tmp.y + rec.y + 15;
            template.vel = rand_x_y_circle(10);
            game->explosion[i].particle[j] = template;
        }
    }
}