#include "Battle.h"
#include "StraightLine.h"
#include "Direction.h"

Battle::Battle(std::shared_ptr<Character> c1, std::shared_ptr<Character> c2)
    : Relationship(c1, c2){};

void Battle::handleCollision()
{
    int currX = this->getCollidedPosition().first;
    int currY = this->getCollidedPosition().second;
    if (currX == -1 || c1->getZ() != c2->getZ() || !c1->getShow() || !c2->getShow())
        return;

    c1->setHealth(c1->getHealth() - c2->getAttack());
    c2->setHealth(c2->getHealth() - c1->getAttack());

    // Remove the item completely from array?
    // Hide the item
    if (c1->getHealth() < 0)
        c1->setShow(false);
    if (c2->getHealth() < 0)
        c2->setShow(false);
};
