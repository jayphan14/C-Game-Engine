#pragma once
#include <iostream>
#include "Movement.h"
#include <memory>
#include <vector>
#include <set>
#include "Direction.h"

using namespace std;

class Character
{
public:
    Character(int startX, int startY, int startZ, int initialHealth, int initialAttack);

    // Getter functions
    int getX() const;
    int getY() const;
    int getZ() const;
    int getHealth() const;
    int getAttack() const;
    bool getShow() const;
    vector<shared_ptr<Movement>> &getMovements();

    // Setter functions
    void setX(int newX);
    void setY(int newY);
    void setZ(int newZ);
    void setStageX(int stageX);
    void setStageY(int stageY);

    void setShow(bool newShow);
    void setHealth(int newHealth);
    void setAttack(int newAttack);
    void addMovement(shared_ptr<Movement> newMovement);

    // Main functionality;
    void move(int tick, int userInput);
    virtual bool isInPos(int x, int y) = 0;
    virtual char getCharAt(int x, int y) = 0;
    virtual set<pair<int, int>> getAllCords() = 0;
    virtual Direction whereDidIGetHit(pair<int, int> prevPos, pair<int, int> currPos) = 0;
    void updateStagingPosition();

private:
    int x;
    int y;
    int z;
    int health;
    int attack;
    bool show = true;
    int stageX = -1;
    int stageY = -1;
    vector<shared_ptr<Movement>> movements;
};
