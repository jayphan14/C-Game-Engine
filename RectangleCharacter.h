#include "Character.h"

class RectangleCharacter : public Character
{
public:
    RectangleCharacter(int startX, int startY, int startZ, int initialHealth, int initialAttack, int width, int height, char symbol);
    bool isInPos(int x, int y) override;
    char getCharAt(int x, int y) override;
    set<pair<int, int>> getAllCords() override;
    Direction whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos) override;

private:
    int width;
    int height;
    char symbol;
};