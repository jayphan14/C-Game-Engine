#include "Character.h"

// Constructor
Character::Character(int startX, int startY, int startZ, int initialHealth, int initialAttack)
    : x{startX}, y{startY}, z{startZ}, health{initialHealth}, attack{initialAttack}
{
}

// Getter functions
int Character::getX() const
{
    return x;
}

int Character::getY() const
{
    return y;
}

int Character::getZ() const
{
    return z;
}

int Character::getHealth() const
{
    return health;
}

int Character::getAttack() const
{
    return attack;
}

bool Character::getShow() const
{
    return show;
}

// Setter functions
void Character::setX(int newX)
{
    x = newX;
}

void Character::setY(int newY)
{
    y = newY;
}

void Character::setZ(int newZ)
{
    z = newZ;
}

void Character::setStageX(int stageX)
{
    stageX = stageX;
}

void Character::setStageY(int stageY)
{
    stageY = stageY;
}

void Character::setHealth(int newHealth)
{
    health = newHealth;
}

void Character::setAttack(int newAttack)
{
    attack = newAttack;
}

void Character::setShow(bool newShow)
{
    show = newShow;
}

void Character::addMovement(shared_ptr<Movement> newMovement)
{
    movements.push_back(std::move(newMovement));
}

void Character::move(int tick, int userInput)
{
    for (auto &movement : movements)
    {
        movement.get()->applyMovement(this->x, this->y, this->show, userInput, tick);
    }
}

vector<shared_ptr<Movement>> &Character::getMovements()
{
    return this->movements;
}

void Character::updateStagingPosition()
{
    if (stageX != -1 && stageY != -1)
    {
        this->setX(stageX);
        this->setY(stageY);

        this->stageX = -1;
        this->stageY = -1;
    }
}
