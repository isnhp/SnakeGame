#include <stdlib.h>

#include "food.h"

void generateFood(Game *game)
{
    int foodOnSnake = 1;

    while (foodOnSnake == 1)
    {
        game->foodX = rand() % (WIDTH - 2) + 1;
        game->foodY = rand() % (HEIGHT - 2) + 1;

        foodOnSnake = 0;

        for (int i = 0; i < game->snakeLength; i++)
        {
            if (game->snakeX[i] == game->foodX &&
                game->snakeY[i] == game->foodY)
            {
                foodOnSnake = 1;
                break;
            }
        }
    }
}