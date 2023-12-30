#include "Character.h"
#include <tuple>
#include <vector>

class BitMapCharacter : public Character
{
public:
    BitMapCharacter(int startX, int startY, int startZ, int initialHealth, int initialAttack, vector<tuple<int, int, char>> bitmap);
    bool isInPos(int x, int y) override;
    char getCharAt(int x, int y) override;
    set<pair<int, int>> getAllCords() override;
    Direction whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos) override;

private:
    vector<tuple<int, int, char>> bitmap;
};