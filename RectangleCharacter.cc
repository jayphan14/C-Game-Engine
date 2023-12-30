#include "RectangleCharacter.h"
#include "Character.h"

RectangleCharacter::RectangleCharacter(int startX, int startY, int startZ, int initialHealth, int initialAttack, int width, int height, char symbol)
    : Character(startX, startY, startZ, initialHealth, initialAttack), width{width}, height{height}, symbol(symbol){};

bool RectangleCharacter::isInPos(int x, int y)
{
    return (this->getX() <= x && x <= this->getX() + height - 1 && this->getY() <= y && y <= this->getY() + width - 1);
};

// Need to make sure x, y is valid positions
char RectangleCharacter::getCharAt(int x, int y)
{
    return this->symbol;
};

// return all bits that the character currently occupy:
set<pair<int, int>> RectangleCharacter::getAllCords()
{
    set<pair<int, int>> allCords;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            allCords.insert(make_pair(this->getX() + i, this->getY() + j));
        }
    }

    return allCords;
};

Direction RectangleCharacter::whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos)
{
    int prevX = prevPos.first;
    int currX = currPos.first;
    int prevY = prevPos.second;
    int currY = currPos.second;

    int deltaX = abs(currPos.first - prevPos.first);
    int deltaY = abs(currPos.second - prevPos.second);

    // Handle prev in the 8 quads around it
    //     |  |
    //     |  |
    // ----XXXX----
    //     XXXX
    //     XXXX
    // ----XXXX----
    //     |  |
    //     |  |

    if (this->getX() <= prevX && prevX <= this->getX() + height - 1)
    {
        if (prevY < this->getY())
            return Direction::Left;
        return Direction::Right;
    }

    if (this->getY() <= prevY && prevY <= this->getY() + width - 1)
    {
        if (prevX < this->getX())
            return Direction::Top;
        return Direction::Bottom;
    }

    // TOP LEFT QUAD
    if (prevX < this->getX() && prevY < this->getY())
    {
        int topLeftX = this->getX();
        int topLeftY = this->getY();

        if (currX == topLeftX && currY == topLeftY)
        {
            if (deltaX == deltaY)
                return Direction::TopLeft;

            return abs(topLeftX - prevX) < abs(topLeftY - prevY) ? Direction::Left : Direction::Top;
        }
        else if (currX > topLeftX)
        {
            return Direction::Left;
        }
        else if (currY > topLeftY)
        {
            return Direction::Top;
        }
    }

    // TOP RIGHT QUAD
    if (prevY >= this->getY() + width && prevX < this->getX())
    {
        int topRightX = this->getX();
        int topRightY = this->getY() + width - 1;

        if (currX == topRightX && currY == topRightY)
        {
            if (deltaX == deltaY)
                return Direction::TopRight;

            return abs(topRightX - prevX) < abs(topRightY - prevY) ? Direction::Right : Direction::Top;
        }
        else if (currX > topRightX)
        {
            return Direction::Right;
        }
        else if (currY < topRightY)
        {
            return Direction::Top;
        }
    }

    // BOT LEFT QUAD
    if (prevX >= this->getX() + height && prevY < this->getY())
    {
        int botLeftX = this->getX() + height - 1;
        int botLeftY = this->getY();

        if (currX == botLeftX && currY == botLeftY)
        {
            if (deltaX == deltaY)
                return Direction::BottomLeft;

            return abs(botLeftX - prevX) < abs(botLeftY - prevY) ? Direction::Left : Direction::Bottom;
        }
        else if (currX < botLeftX)
        {
            return Direction::Left;
        }
        else if (currY > botLeftY)
        {
            return Direction::Bottom;
        }
    }

    // BOT RIGHT QUAD
    if (prevX >= this->getX() + height && prevY >= this->getY() + width)
    {
        int botRightX = this->getX() + height - 1;
        int botRightY = this->getY() + width - 1;

        if (currX == botRightX && currY == botRightY)
        {
            if (deltaX == deltaY)
                return Direction::BottomRight;

            return abs(botRightX - prevX) < abs(botRightY - prevY) ? Direction::Right : Direction::Bottom;
        }
        else if (currX < botRightX)
        {
            return Direction::Right;
        }
        else if (currY < botRightY)
        {
            return Direction::Bottom;
        }
    }
}