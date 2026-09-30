#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"

void initSnake(Game *game);
void moveSnake(Game *game);
void growSnake(Game *game, int oldTailX, int oldTailY);

#endif