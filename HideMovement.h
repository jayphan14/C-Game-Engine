#pragma once
#include "Movement.h"

class HideMovement : public Movement
{
public:
    void applyMovement(int &x, int &y, bool &show, int userInput, int tick) override;
};
