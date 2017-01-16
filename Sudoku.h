#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <iostream>
#include <cmath>
#include <bitset>
#include <cstdlib>
using namespace std;

class Sudoku
{
private:
    int inputgrid[9][9];
    struct Playinggrid
    {
        int number;
        bool fixed;
    } grid[9][9];
public:
    void loadinput();
    void printgrid();
    bool checkrow(int row, int column);
    bool checkcolumn(int row, int column);
    bool checksquare(int row, int column);
    bool checkValidSudoku();
    bool solve(int row, int column);
    void randomHide();
    int countEmptyCell();
    void handleInput();
    void resetBoard();
    void Run();
};

#endif // SUDOKU_H_INCLUDED
