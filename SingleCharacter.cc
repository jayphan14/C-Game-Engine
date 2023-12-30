#include "SingleCharacter.h"
#include "Character.h"

SingleCharacter::SingleCharacter(int startX, int startY, int startZ, int initialHealth, int initialAttack, char symbol)
    : Character(startX, startY, startZ, initialHealth, initialAttack), symbol(symbol){};

bool SingleCharacter::isInPos(int x, int y)
{
    return (this->getX() == x && this->getY() == y);
};

// Need to make sure x, y is valid positions
char SingleCharacter::getCharAt(int x, int y)
{
    return this->symbol;
};

// return all bits that the character currently occupy:
set<pair<int, int>> SingleCharacter::getAllCords()
{
    set<pair<int, int>> allCords;

    allCords.insert(make_pair(this->getX(), this->getY()));

    return allCords;
};

Direction SingleCharacter::whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos)
{
    int deltaX = currPos.first - prevPos.first;
    int deltaY = currPos.second - prevPos.second;

    if (deltaX > 0 && deltaY > 0)
    {
        // Case 1: Collision at bottom-right
        return Direction::TopLeft;
    }
    else if (deltaX == 0 && deltaY > 0)
    {
        // Case 2: Collision at Left
        return Direction::Left;
    }
    else if (deltaX < 0 && deltaY > 0)
    {
        // Case 3: Collision at bottom-left
        return Direction::BottomLeft;
    }
    else if (deltaX > 0 && deltaY == 0)
    {
        // Case 4: Collision at top
        return Direction::Top;
    }
    else if (deltaX < 0 && deltaY == 0)
    {
        // Case 5: Collision at bottom
        return Direction::Bottom;
    }
    else if (deltaX > 0 && deltaY < 0)
    {
        // Case 6: Collision at top-right
        return Direction::TopRight;
    }
    else if (deltaX == 0 && deltaY < 0)
    {
        // Case 7: Collision at left
        return Direction::Right;
    }
    else if (deltaX < 0 && deltaY < 0)
    {
        // Case 8: Collision at bottom right
        return Direction::BottomRight;
    }
}
