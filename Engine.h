#pragma once

#include <ncurses.h>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>
#include "Display.h"
#include "Character.h"
#include "Relationship.h"

using namespace std;
class Engine
{
public:
    Engine(int gameWidth, int gameHeight);
    void play();
    void addCharacter(shared_ptr<Character> newCharacter);
    void addRelationship(shared_ptr<Relationship> newRelation);

private:
    void moveCharacters(int tick, int userInput);
    vector<vector<char>> createTopDownView();
    unique_ptr<Display> display;
    vector<shared_ptr<Character>> characters;
    vector<shared_ptr<Relationship>> relationships;
    vector<vector<pair<int, char>>> gameGrid;
    int gameWidth;
    int gameHeight;
};