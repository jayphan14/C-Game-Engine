#include "Display.h"
#include "SingleCharacter.h"
#include "RectangleCharacter.h"
#include "BitMapCharacter.h"
#include "Engine.h"
#include <iostream>
#include <memory>
#include <curses.h>
#include <string>
#include "StraightLine.h"
#include "UserInputMovement.h"
#include "HideMovement.h"
#include "UnhideMovement.h"
#include "BounceOff.h"
#include "Battle.h"

using namespace std;
int main()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);

    Engine engine(80, 25);
    auto topBorder = make_shared<RectangleCharacter>(0, 1, 10, 0, 0, 78, 1, '-');
    auto topLeftCorner = make_shared<SingleCharacter>(0, 0, 10, 0, 0, '+');
    auto topRightCorner = make_shared<SingleCharacter>(0, 79, 10, 0, 0, '+');
    auto botLeftCorner = make_shared<SingleCharacter>(24, 0, 10, 0, 0, '+');
    auto botRightCorner = make_shared<SingleCharacter>(24, 79, 10, 0, 0, '+');
    auto botBorder = make_shared<RectangleCharacter>(24, 1, 10, 0, 0, 78, 1, '-');
    auto leftBorder = make_shared<RectangleCharacter>(1, 0, 10, 0, 0, 1, 23, '|');
    auto rightBorder = make_shared<RectangleCharacter>(1, 79, 10, 0, 0, 1, 23, '|');
    auto player = make_shared<RectangleCharacter>(22, 25, 10, 100, 10, 30, 1, '-');
    auto ball = make_shared<SingleCharacter>(1, 55, 10, 100, 2, 'o');

    auto movement1 = make_shared<StraightLine>(1, 1, 0);

    auto movement = make_shared<UserInputMovement>();
    player.get()->addMovement(std::move(movement));

    ball.get()->addMovement(std::move(movement1));

    std::vector<std::tuple<int, int, char>> myVectorOfTuples;
    myVectorOfTuples.push_back(std::make_tuple(1, 1, 'O'));
    myVectorOfTuples.push_back(std::make_tuple(2, 2, 'O'));
    myVectorOfTuples.push_back(std::make_tuple(3, 3, 'O'));
    myVectorOfTuples.push_back(std::make_tuple(4, 4, 'O'));

    auto bitmapChar1 = make_shared<BitMapCharacter>(1, 1, 15, 100, 2, myVectorOfTuples);

    engine.addCharacter(topBorder);
    engine.addCharacter(botBorder);
    engine.addCharacter(leftBorder);
    engine.addCharacter(rightBorder);
    engine.addCharacter(player);
    engine.addCharacter(ball);
    engine.addCharacter(topLeftCorner);
    engine.addCharacter(topRightCorner);
    engine.addCharacter(botLeftCorner);
    engine.addCharacter(botRightCorner);

    auto rela1 = make_shared<BounceOff>(ball, botBorder);
    auto rela2 = make_shared<BounceOff>(ball, topBorder);
    auto rela3 = make_shared<BounceOff>(ball, leftBorder);
    auto rela4 = make_shared<BounceOff>(ball, rightBorder);
    auto rela5 = make_shared<BounceOff>(ball, player);

    auto rela6 = make_shared<BounceOff>(ball, topLeftCorner);
    auto rela7 = make_shared<BounceOff>(ball, topRightCorner);
    auto rela8 = make_shared<BounceOff>(ball, botLeftCorner);
    auto rela9 = make_shared<BounceOff>(ball, botRightCorner);

    // BRICKS

    for (int col = 10; col < 70; col += 4)
    {
        for (int row = 4; row < 8; row++)
        {
            auto newBlock = make_shared<RectangleCharacter>(row, col, 10, 1, 0, 4, 1, '=');
            auto bounceRela = make_shared<BounceOff>(ball, newBlock);
            auto battleRela = make_shared<Battle>(ball, newBlock);
            engine.addCharacter(newBlock);
            engine.addRelationship(bounceRela);
            engine.addRelationship(battleRela);
        }
    }

    engine.addRelationship(rela1);
    engine.addRelationship(rela2);
    engine.addRelationship(rela3);
    engine.addRelationship(rela4);
    engine.addRelationship(rela5);
    engine.addRelationship(rela6);
    engine.addRelationship(rela7);
    engine.addRelationship(rela8);
    engine.addRelationship(rela9);

    engine.play();

    endwin();
    return 0;
};