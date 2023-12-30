#include "PassThrough.h"

PassThrough::PassThrough(std::shared_ptr<Character> c1, std::shared_ptr<Character> c2)
    : Relationship(c1, c2){};

void PassThrough::handleCollision(){};