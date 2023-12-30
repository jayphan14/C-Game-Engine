#include "BounceOff.h"
#include "StraightLine.h"
#include "Direction.h"

BounceOff::BounceOff(std::shared_ptr<Character> c1, std::shared_ptr<Character> c2)
    : Relationship(c1, c2){};

void BounceOff::handleCollision()
{
    int currX = this->getCollidedPosition().first;
    int currY = this->getCollidedPosition().second;
    if (currX == -1 || c1->getZ() != c2->getZ() || !c1->getShow() || !c2->getShow())
        return;

    auto &movements = c1->getMovements();
    for (auto &movement : movements)
    {
        auto straightLine = dynamic_cast<StraightLine *>(movement.get());

        // Use dynamic_cast to check if the movement is of type StraightLine
        if (straightLine != nullptr)
        {
            // Get last position
            int prevX = straightLine->getLastX();
            int prevY = straightLine->getLastY();

            Direction whichPartGotHit = c2->whereDidIGetHit(make_pair(prevX, prevY), make_pair(currX, currY));
            c1->setStageX(prevX);
            c1->setStageY(prevY);
            switch (whichPartGotHit)
            {
            case Direction::Left:
                straightLine->reflectY();
                break;

            case Direction::Right:
                straightLine->reflectY();
                break;

            case Direction::Top:
                straightLine->reflectX();
                break;

            case Direction::Bottom:
                straightLine->reflectX();
                break;

            case Direction::TopLeft:
            case Direction::TopRight:
            case Direction::BottomLeft:
            case Direction::BottomRight:
                straightLine->reflectX();
                straightLine->reflectY();
                break;

            default:
                break;
            }
        }
    }
};
