#ifndef GAME_H
#define GAME_H

#define WIDTH 40
#define HEIGHT 15
#define MAX_SNAKE_LENGTH 100

typedef struct
{
    int snakeX[MAX_SNAKE_LENGTH];
    int snakeY[MAX_SNAKE_LENGTH];

    int snakeLength;

    int foodX;
    int foodY;

    int direction;

    int score;

    int gameOver;

} Game;

#endif