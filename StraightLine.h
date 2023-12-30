#pragma once
#include "Movement.h"

class StraightLine : public Movement
{
    int dx;
    int dy;
    int dz;
    int lastX;
    int lastY;

public:
    StraightLine(int dx, int dy, int dz);
    int getDX();
    int getDY();
    int getDZ();
    int getLastX();
    int getLastY();
    void setDX(int newDX);
    void setDY(int newDY);
    void setDZ(int newDZ);
    void reflectX();
    void reflectY();
    void applyMovement(int &x, int &y, bool &show, int userInput, int tick) override;
};
