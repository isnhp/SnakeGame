#include "snake.h"

void initSnake(Game *game)
{
    game->snakeLength = 5;

    game->snakeX[0] = 10;
    game->snakeY[0] = 5;

    game->snakeX[1] = 9;
    game->snakeY[1] = 5;

    game->snakeX[2] = 8;
    game->snakeY[2] = 5;

    game->snakeX[3] = 7;
    game->snakeY[3] = 5;

    game->snakeX[4] = 6;
    game->snakeY[4] = 5;
}


void moveSnake(Game *game)
{
    for (int i = game->snakeLength - 1; i > 0; i--)
    {
        game->snakeX[i] = game->snakeX[i - 1];
        game->snakeY[i] = game->snakeY[i - 1];
    }

    if (game->direction == 3)
    {
        game->snakeY[0]--;
    }
    else if (game->direction == 2)
    {
        game->snakeX[0]--;
    }
    else if (game->direction == 1)
    {
        game->snakeY[0]++;
    }
    else if (game->direction == 0)
    {
        game->snakeX[0]++;
    }
}


void growSnake(Game *game, int oldTailX, int oldTailY)
{
    game->snakeLength++;

    game->snakeX[game->snakeLength - 1] = oldTailX;
    game->snakeY[game->snakeLength - 1] = oldTailY;
}