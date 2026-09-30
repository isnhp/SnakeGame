#include <stdio.h>

#include "render.h"

char map[HEIGHT][WIDTH];

void renderGame(Game *game)
{
    // 重新创建地图
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (x == 0 ||
                x == WIDTH - 1 ||
                y == 0 ||
                y == HEIGHT - 1)
            {
                map[y][x] = '#';
            }
            else
            {
                map[y][x] = ' ';
            }
        }
    }

    // 画蛇
    for (int i = 0; i < game->snakeLength; i++)
    {
        map[game->snakeY[i]][game->snakeX[i]] = 'O';
    }

    // 画食物
    map[game->foodY][game->foodX] = '@';

    // 输出地图
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            printf("%c", map[y][x]);
        }

        printf("\n");
    }

    // 输出分数
    printf("Score: %d\n", game->score);
}