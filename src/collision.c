#include "collision.h"

int checkWallCollision(Game *game)
{
    if (game->snakeX[0] <= 0 ||
        game->snakeX[0] >= WIDTH - 1 ||
        game->snakeY[0] <= 0 ||
        game->snakeY[0] >= HEIGHT - 1)
    {
        return 1;
    }

    return 0;
}


int checkSelfCollision(Game *game)
{
    for (int i = 1; i < game->snakeLength; i++)
    {
        if (game->snakeX[i] == game->snakeX[0] &&
            game->snakeY[i] == game->snakeY[0])
        {
            return 1;
        }
    }

    return 0;
}