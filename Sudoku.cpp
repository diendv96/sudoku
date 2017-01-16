#include "Sudoku.h"
#include <iostream>
#include <cmath>
#include <bitset>
#include <cstdlib>
using namespace std;

void Sudoku::loadinput(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (inputgrid[i][j] == 0){

				grid[i][j].fixed = false;
				grid[i][j].number = 0;
			}

			else{
				grid[i][j].fixed = true;
				grid[i][j].number = inputgrid[i][j];
			}
		}
	}
}

void Sudoku::printgrid() {
    int i, j;
    int k;
    cout << "\n";
    for( i=0; i<9; i++ )
    {
        for(k=0; k <= 4*9; k++ )
        {
            cout << "-";
        }
        cout << "\n|";
        for( j=0; j<9; j++ )
        {
            if( grid[i][j].number == 0 )
            {
                cout << "   |";
            } else
            {
                cout << " " << grid[i][j].number << " |";
            }
            }
            cout << "\n";
            }
            for(k=0; k<=4*9; k++ )
            {
                cout << "-";
            }
            cout << "\n";

            return;
}
bool Sudoku::checkrow(int row, int column){
	for (int i = 0; i < 9; i++){
		if (i != column){
			if (grid[row][i].number == grid[row][column].number ){
				return false;
			}
		}
	}
	return true;
}
bool Sudoku::checkcolumn(int row, int column){

	for (int i = 0; i < 9; i++){
		if (i != row){
			if (grid[i][column].number == grid[row][column].number ){
				return false;
			}
		}
	}
	return true;
}
bool Sudoku::checksquare(int row, int column){
	int vsquare = row/3;
	int hsquare = column/3;

           	      for (int i = vsquare * 3; i < (vsquare*3 + 3); i++){
		for (int j = hsquare * 3; j < (hsquare*3 + 3); j++){
			if (!(i == row && j == column)){
				if (grid[ row ][ column ].number == grid[i][j].number){
				return false;
				}
			}
		}
	}
	return true;
}
bool Sudoku::checkValidSudoku()
{
    for (int i=0; i<9; i += 3)
    for (int j=0; j<9; j += 3) {
        std::bitset<9> filled;
        for (int k=0; k<3; k++)
            for (int l=0; l<3; l++)
                filled.set(grid[i+k][j+l].number - 1);
        if (filled.count() != 9)
            return false;
    }
    return true;
}
bool Sudoku::solve(int row, int column){
		while (grid[row][column].fixed == true)
{
		column++;

		if(column > 8){
			column = 0;
			row++;
		}
		if (row > 8){
			return true;
		}
	}

	for (int n = 1; n < 10; n++){
		int nextrow, nextcolumn;

		grid[row][column].number = n;

		if ( checkcolumn(row, column)
		  && checkrow(row, column)
		  && checksquare(row, column)){
			nextrow = row;
			nextcolumn = column;

			nextcolumn++;
			if(nextcolumn > 8){
			nextcolumn = 0;
			nextrow++;
			}
			if (nextcolumn == 0 && nextrow == 9){
				return true;
			}
			if(solve(nextrow, nextcolumn)){
				return true;
			}
		}
	}
	grid[row][column].number = 0;
	return false;

}
void Sudoku::randomHide()
{
    for (int i =0; i < 2; i++)
    {
        int ran1 = rand() % 9 + 1;
        int ran2 = rand() % 9 + 1;
        grid[ran1][ran2].number = 0;
    }
}
int Sudoku::countEmptyCell()
{
    int count = 0;
    for (int i =0; i < 9; i++)
    {
        for (int j =0; j < 9; j++)
        {
            if (grid[i][j].number == 0)
            {
                count +=1;
            }
        }
    }
    return count;
}
void Sudoku::handleInput()
{
	    int row, col, value;
		int i=0;
        do {
            if( i != 0 ){
                cout << "Invalid column/ row index.\n"
                     <<	"Please try again\n";
            }
            cout << "Enter row / column / value : ";
            cin >> row >> col >> value;
            i=1;
        } while ( !((row> 0 && row<=9) && (col> 0 && col<=9)
					&& (value> 0 && value<=9)));
        row -=1;
        col -=1;
        grid[row][col].number = value;
}
void Sudoku::resetBoard()
	{
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                grid[i][j].number = 0;
            }
        }
	}
void Sudoku::Run()
{
    cout << "WELCOME TO SUDOKU GAME" << endl;
    cout << "CODE BY DANG VAN DIEN && NGUYEN DANG DAI" << endl;
	cout << endl;

	cout << "RULES:    "<< endl;
	cout << endl;

	cout << "->You'll be given a 9x9 board with some numbers filled"<< endl;
	cout << endl;

	cout << "->You have to arrange numbers from 1 to 9 so that a number shows up once in one row, one column and in a 3x3 box." << endl;
	cout << endl;

	cout << "So, let's get started" << endl;

	cout << endl;
	cout <<endl;
	//resetBoard();
	solve(0, 0);
    randomHide();
	printgrid();
	int count = 0;
	while( count < countEmptyCell())
		{
			handleInput();
			system("cls");
			printgrid();
		}
    int kq = checkValidSudoku();
    if (kq == true)
    {
        cout << "Valid sudoku";
    }
    else {
        cout << "Try again";
    }
}
