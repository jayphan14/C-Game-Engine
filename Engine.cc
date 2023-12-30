#include "Display.h"
#include "Engine.h"
#include <iostream>
#include <memory>
#include <utility>
#include <thread>
#include <chrono>
#include <limits>

using namespace std;

Engine::Engine(int gameWidth, int gameHeight) : gameWidth{gameWidth}, gameHeight{gameHeight}
{
    display = std::make_unique<Display>(gameWidth, gameHeight);
    this->gameGrid = std::vector<std::vector<std::pair<int, char>>>(gameHeight, std::vector<std::pair<int, char>>(gameWidth, std::make_pair(0, ' ')));
}
void Engine::play()
{
    display->initialize();
    bool gameOver = false;
    int tick = 0;
    while (!gameOver)
    {
        tick += 1;
        if (tick == std::numeric_limits<int>::max() - 1)
        {
            tick = 1;
        }
        int userInput = display->getUserInput();

        // Move all the characters
        moveCharacters(tick, userInput);

        // Detect and handle collisions:
        for (auto rela : relationships)
        {
            rela.get()->handleCollision();
        }

        for (auto &c : characters)
        {
            c->updateStagingPosition();
        }

        auto newGrid = createTopDownView();
        display->setGrid(newGrid);
        display->updateDisplay();
        display->refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        // gameOver = true;
    };
}

void Engine::addCharacter(shared_ptr<Character> newCharacter)
{
    characters.push_back(newCharacter);
}

void Engine::addRelationship(shared_ptr<Relationship> newRelation)
{
    relationships.push_back(newRelation);
}

vector<vector<char>> Engine::createTopDownView()
{
    vector<vector<char>> topDownView(gameHeight, std::vector<char>(gameWidth));
    for (int i = 0; i < gameHeight; ++i)
    {
        for (int j = 0; j < gameWidth; ++j)
        {
            gameGrid[i][j].first = 0;
            gameGrid[i][j].second = ' ';
            for (const auto &c : characters)
            {
                if (c->getShow() && c->isInPos(i, j) && (c->getZ() > gameGrid[i][j].first))
                {
                    gameGrid[i][j].first = c->getZ();
                    gameGrid[i][j].second = c->getCharAt(i, j);
                }
            }
            topDownView[i][j] = gameGrid[i][j].second;
        }
    }
    return topDownView;
};

void Engine::moveCharacters(int tick, int userInput)
{
    for (auto &c : characters)
    {
        c.get()->move(tick, userInput);
    }
}