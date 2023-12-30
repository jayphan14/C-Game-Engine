#pragma once
class Movement
{

public:
    virtual void applyMovement(int &x, int &y, bool &show, int userInput, int tick) = 0;
    // virtual void reverse(int &x, int &y, bool &show) = 0;
    // virtual void reflect(int &x, int &y, bool &show) = 0;
};