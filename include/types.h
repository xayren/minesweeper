#ifndef TYPES_H
#define TYPES_H

#include "raylib.h"

#define MAX_PARTICLES 10
#define NUM_OF_COLORS 10
#define CHANGE_COLOR (256 / NUM_OF_COLORS)

typedef enum
{
    EMPTY,
    NUMBER,
    FLAG,
    MINE
} draw;

typedef enum
{
    NOT_CLICKED,
    LMB,
    RMB
} clicked;

typedef enum
{
    Game,
    Explosion,
    Victory
} Game_State;

typedef struct
{
    Rectangle rec;
    Vector2 vel;
} Particle;

typedef struct
{
    Particle particle[MAX_PARTICLES];
} Particles;

typedef struct
{
    Rectangle rec;
    Color inside;
    Color outside;
    int state;
    int clicked;
    int draw;
} Box;

typedef struct
{
    Box board[10][10];
    Texture2D flag;
    Texture2D bomb;
    Texture2D play_again;
    Rectangle play_again_rec;
    int num_left;
    Texture2D trophy;
    int first_click;
    Particles explosion[NUM_OF_COLORS];
    float timer;
} Minesweeper;

#endif