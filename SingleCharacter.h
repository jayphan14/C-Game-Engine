#pragma once
#include "Character.h"
#include "Direction.h"

class SingleCharacter : public Character
{
public:
    SingleCharacter(int startX, int startY, int startZ, int initialHealth, int initialAttack, char symbol);
    bool isInPos(int x, int y) override;
    char getCharAt(int x, int y) override;
    set<pair<int, int>> getAllCords() override;
    Direction whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos) override;

private:
    char symbol;
};