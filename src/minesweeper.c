#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "minesweeper.h"


void init_end(Minesweeper *game)
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            Box *tmp = &game->board[y][x];
            if (game->num_left != 0)    // lose
            {
                if (tmp->state == -1)   // mine
                {
                    if (tmp->clicked == NOT_CLICKED) tmp->draw = MINE;
                    else if (tmp->clicked == LMB)
                    {
                        tmp->draw = MINE;
                        tmp->inside = (Color){255, 147, 0, 255};
                    }
                    else if (tmp->clicked == RMB)
                    {
                        tmp->draw = FLAG;
                        tmp->inside = LIME;
                    } 
                }
                else                    // not mine
                {
                    if (tmp->clicked == RMB) tmp->inside = (Color){255, 147, 0, 255};
                }
            }

            else                        // win
            {
                if (tmp->state == -1)    // mine
                {
                    tmp->draw = FLAG;
                    tmp->inside = LIME;
                }
            }
        }
    }
}


void play_again(Minesweeper *game)
{
    DrawTexturePro(game->play_again, (Rectangle){0, 0, 512, 512}, (Rectangle){375, 100, 50, 50}, (Vector2){0, 0}, 0, WHITE);
}


void fill_zero(Minesweeper *game, int x, int y)

{
    if (game->board[y][x].clicked == LMB || game->board[y][x].state == -1) return;
    game->num_left--;
    game->board[y][x].clicked = LMB;
    game->board[y][x].inside = (Color){190, 190, 190, 255};
    if (game->board[y][x].state != 0)
    {
        game->board[y][x].draw = NUMBER;
        return;
    }

    for (int x_i = -1; x_i < 2; x_i++){
        for (int y_i = -1; y_i < 2; y_i++){
            if (x_i == 0 && y_i == 0) continue;
            if (x + x_i >= 0 && x + x_i < 10 && y + y_i >= 0 && y + y_i < 10){
                if (game->board[y + y_i][x + x_i].clicked == NOT_CLICKED) fill_zero(game, x + x_i, y + y_i);
            }
        }
    }
}


void draw_block(Minesweeper *game, int x, int y)
{
    Box *tmp = &game->board[y][x];
    DrawRectangle(tmp->rec.x, tmp->rec.y, tmp->rec.width, tmp->rec.height, game->board[y][x].inside);
    DrawRectangleLines(tmp->rec.x, tmp->rec.y, tmp->rec.width, tmp->rec.height, tmp->outside);

    if (tmp->draw == NUMBER && tmp->state != 0) DrawText(TextFormat("%d", tmp->state), tmp->rec.x + 11, tmp->rec.y + 8, 20, BLACK);

    else if (tmp->draw == FLAG) DrawTexture(game->flag, tmp->rec.x, tmp->rec.y, WHITE);

    else if (tmp->draw == MINE) DrawTexture(game->bomb, tmp->rec.x, tmp->rec.y, WHITE);
}


void draw_board(Minesweeper *minesweeper)
{
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            draw_block(minesweeper, x, y);
        }
    }
}


int mines_around(Minesweeper *minesweeper, int x, int y)
{
    int result = 0;
    for (int y_i = -1; y_i < 2; y_i++){
        for (int x_i = -1; x_i < 2; x_i++){
            if (y_i == 0 && x_i == 0) continue;
            if (x + x_i < 0 || x + x_i >= 10) continue;
            if (y + y_i < 0 || y + y_i >= 10) continue;
            if (minesweeper->board[y + y_i][x + x_i].state == -1) result++;
        }
    }
    return result;
}


void init_minesweeper(Minesweeper *minesweeper)

{
    Rectangle rec = {250, 250, 30, 30};
    minesweeper->play_again_rec = (Rectangle){375, 100, 50, 50};
    Box template = {rec, (Color){242, 234, 212, 255}, LIGHTGRAY , 0, 0, 0};
    minesweeper->first_click = 1;

    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            minesweeper->board[y][x] = template;
            template.rec.y += 30;
        }
        template.rec.y = 250;
        template.rec.x += 30;
    }
    int x, y, mines_left = 10;
    minesweeper->num_left = 100 - mines_left;
    //Placing mines
    while (mines_left > 0){
        x = GetRandomValue(0, 9);
        y = GetRandomValue(0, 9);
        if (minesweeper->board[y][x].state == -1) continue;
        else{
            minesweeper->board[y][x].state = -1;
            mines_left--;
        }
    }

    //Filling other spaces
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            if (minesweeper->board[y][x].state != -1){
                minesweeper->board[y][x].state = mines_around(minesweeper, x, y);
            }
        }
    }
}