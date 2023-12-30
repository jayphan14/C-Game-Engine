#include "UserInputMovement.h"

void UserInputMovement::applyMovement(int &x, int &y, bool &show, int userInput, int tick)
{
    switch (userInput)
    {
    case 'a':
        y--;
        break;
    case 's':
        x++;
        break;
    case 'd':
        y++;
        break;
    case 'w':
        x--;
        break;
    default:
        break;
    }
}