#include "StraightLine.h"

StraightLine::StraightLine(int dx, int dy, int dz) : dx{dx}, dy{dy}, dz{dz} {}

int StraightLine::getDX()
{
    return dx;
}

int StraightLine::getDY()
{
    return dy;
}

int StraightLine::getDZ()
{
    return dz;
}

int StraightLine::getLastX()
{
    return lastX;
}
int StraightLine::getLastY()
{
    return lastY;
}

void StraightLine::setDX(int newDX)
{
    dx = newDX;
}

void StraightLine::setDY(int newDY)
{
    dy = newDY;
}

void StraightLine::setDZ(int newDZ)
{
    dz = newDZ;
}

void StraightLine::applyMovement(int &x, int &y, bool &show, int userInput, int tick)
{
    lastX = x;
    lastY = y;
    x += dx;
    y += dy;
}

void StraightLine::reflectX()
{
    dx *= -1;
}

void StraightLine::reflectY()
{
    dy *= -1;
}
