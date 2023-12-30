#pragma once
#include <memory>
#include "Character.h"

class Relationship
{
public:
    Relationship(shared_ptr<Character> c1, shared_ptr<Character> c2);
    virtual void handleCollision() = 0;
    pair<int,int> getCollidedPosition();

protected:
    shared_ptr<Character> c1;
    shared_ptr<Character> c2;
};