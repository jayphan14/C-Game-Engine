#include <ncurses.h>
#include "Display.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

Display::Display(int gameWidth, int gameHeight) : win{newwin(gameHeight, gameWidth, 0, 0)}
{
    if (win == nullptr)
    {
        cout << "window cant be created" << endl;
    }

    // Init the display
    initialize();
};
Display::Display() : win{newwin(0, 0, 0, 0)} {};

Display::~Display()
{
    delwin(win);
}

void Display::initialize()
{
    addBorder();
    refresh();
}
void Display::clear()
{
    wclear(win);
}
void Display::addBorder()
{
    box(win, 0, 0);
}
void Display::refresh()
{
    wrefresh(win);
}

void Display::addAt(int y, int x, char ch)
{
    mvwaddch(this->win, y, x, ch);
}
void Display::updateDisplay()
{
    for (size_t i = 0; i < grid.size(); ++i)
    {
        for (size_t j = 0; j < grid[0].size(); ++j)
        {
            wmove(this->win, i, j);
            waddch(this->win, grid[i][j]);
        };
    };

    wrefresh(win);
};

void Display::setGrid(vector<vector<char>> &grid)
{
    this->grid = grid;
};

void Display::setS1(string s1)
{
    this->s1 = s1;
};
void Display::setS2(string s2)
{
    this->s2 = s2;
};
void Display::setS3(string s3)
{
    this->s3 = s3;
};

vector<vector<char>> Display::getGrid()
{
    return this->grid;
};

int Display::getUserInput()
{
    int ch = getch();

    // Check if there is no input
    if (ch == ERR)
    {
        return -1;
    }

    return ch;
}
