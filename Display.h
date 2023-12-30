#pragma once

#include <ncurses.h>
#include <vector>
#include <string>
#include <memory>
using namespace std;

struct WindowDeleter
{
    void operator()(WINDOW *win) const
    {
        delwin(win);
    }
};

class Display
{
public:
    Display();
    ~Display();
    Display(int gameWidth, int gameHeight);
    void initialize();
    void updateDisplay();
    void refresh();
    void clear();
    void addBorder();
    void addAt(int y, int x, char ch);
    void setGrid(vector<vector<char>> &grid);
    void setS1(string s1);
    void setS2(string s2);
    void setS3(string s3);

    int getUserInput();
    vector<vector<char>> getGrid();

    // void display();
    // void setup();

private:
    WINDOW *win;
    // unique_ptr<WINDOW, WindowDeleter> win; // TODO: change win to be a unique pointers
    vector<vector<char>> grid;
    string s1;
    string s2;
    string s3;
};