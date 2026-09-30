#include <conio.h>

#include "input.h"

void handleInput(Game *game)
{
    if (_kbhit())
    {
        char key = _getch();

        if ((key == 'w' || key == 'W') &&
            game->direction != 1)
        {
            game->direction = 3;
        }
        else if ((key == 's' || key == 'S') &&
                 game->direction != 3)
        {
            game->direction = 1;
        }
        else if ((key == 'a' || key == 'A') &&
                 game->direction != 0)
        {
            game->direction = 2;
        }
        else if ((key == 'd' || key == 'D') &&
                 game->direction != 2)
        {
            game->direction = 0;
        }
    }
}