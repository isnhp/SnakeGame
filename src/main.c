#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "../include/game.h"
#include "../include/food.h"
#include "../include/snake.h"
#include "../include/render.h"
#include "../include/input.h"
#include "../include/collision.h"

char map[HEIGHT][WIDTH];


int main(void)
{
    // 创建游戏对象
    Game game;

    // 初始化游戏数据
    game.snakeLength = 5;
    game.gameOver = 0;
    game.direction = 0;   // 0 = 右，1 = 下，2 = 左，3 = 上
    game.score = 0;

    // 初始化随机数
    srand((unsigned int)time(NULL));


    // 初始化蛇
    initSnake(&game);

    // 第一次生成食物
    generateFood(&game);


    // 游戏主循环
    while (game.gameOver == 0)
    {
        // =========================
        // 1. 读取键盘
        // =========================

        handleInput(&game);

        // =========================
        // 2. 保存蛇尾位置
        // =========================

        int oldTailX =
            game.snakeX[game.snakeLength - 1];

        int oldTailY =
            game.snakeY[game.snakeLength - 1];


        // =========================
        // 3. 蛇移动
        // =========================

        moveSnake(&game);


        // =========================
        // 5. 检查是否吃到食物
        // =========================

        if (game.snakeX[0] == game.foodX &&
            game.snakeY[0] == game.foodY)
        {
            growSnake(&game, oldTailX, oldTailY);

            // 分数增加
            game.score++;

            // 重新生成食物
            generateFood(&game);
        }


        // =========================
        // 6. 检查撞到自己
        // =========================

       if (checkSelfCollision(&game))
        {
            game.gameOver = 1;
        }


        // =========================
        // 7. 检查撞墙
        // =========================

       if (checkWallCollision(&game))
        {
            game.gameOver = 1;
        }


        // =========================
        // 8. 创建地图
        // =========================

        renderGame(&game);

        // =========================
        // 9. 控制游戏速度
        // =========================

        Sleep(500);
    }


    return 0;
}
