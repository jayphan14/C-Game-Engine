#pragma once
#include <memory>
#include "Character.h"
#include "Relationship.h"

class BounceOff : public Relationship
{
public:
    BounceOff(shared_ptr<Character> c1, shared_ptr<Character> c2);
    void handleCollision() override;
};