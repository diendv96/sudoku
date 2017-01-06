#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include<iostream>

using namespace std;

class Sudoku {
private:
	const static int M = 3;
	const static int N = M * M;
    int **matrix;
public:
	Sudoku();
	~Sudoku();
	void showBoard();
	void resetBoard(int *count);
	void handleInput(int *row, int *col, int *value);
	int checkRow(int row, int value);
	int checkCol(int col, int value);
	int checkSpecial(int row, int col, int value);
	int upateBoard(int row, int col, int value);
	void run();
};

#endif // SUDOKU_H_INCLUDED
