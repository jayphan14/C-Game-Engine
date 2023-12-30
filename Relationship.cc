#include "Relationship.h"

Relationship::Relationship(shared_ptr<Character> c1, shared_ptr<Character> c2)
{
    this->c1 = c1;
    this->c2 = c2;
};

pair<int, int> Relationship::getCollidedPosition()
{
    if (c1.get()->getZ() != c2.get()->getZ())
        return make_pair(-1, -1);

    auto set1 = c1.get()->getAllCords();
    auto set2 = c2.get()->getAllCords();

    for (const auto &tuple : set1)
    {
        if (set2.find(tuple) != set2.end())
        {
            return tuple;
        }
    }

    return make_pair(-1, -1);
}