#include "BitMapCharacter.h"
#include "Character.h"
#include <utility>

BitMapCharacter::BitMapCharacter(int startX, int startY, int startZ, int initialHealth, int initialAttack, vector<tuple<int, int, char>> newBitmap)
    : Character(startX, startY, startZ, initialHealth, initialAttack), bitmap{vector<tuple<int, int, char>>()}
{
    // Update the new bitmap to store relative position to startX, startY;
    for (auto &[x, y, z] : newBitmap)
    {
        this->bitmap.push_back(make_tuple(x - startX, y - startY, z));
    }
};

bool BitMapCharacter::isInPos(int x, int y)
{
    for (const auto &item : bitmap)
    {
        if (get<0>(item) + this->getX() == x && get<1>(item) + this->getY() == y)
        {
            return true;
        }
    }

    return false;
};

// Need to make sure x, y is valid positions
char BitMapCharacter::getCharAt(int x, int y)
{
    for (const auto &item : bitmap)
    {
        if (get<0>(item) + this->getX() == x && get<1>(item) + this->getY() == y)
        {
            return get<2>(item);
        }
    }
};

// return all bits that the character currently occupy:
set<pair<int, int>> BitMapCharacter::getAllCords()
{
    set<pair<int, int>> allCords;

    for (auto cord : bitmap)
    {
        allCords.insert(make_pair(get<0>(cord) + this->getX(), get<1>(cord) + this->getY()));
    }

    return allCords;
};

Direction BitMapCharacter::whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos)
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
};