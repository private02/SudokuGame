#include "Sudoku.h"

#include <iostream>
using namespace std;
int a[9][9] = {
	{0,6,1,9,7,0,0,0,3},
	{0,2,9,6,0,0,0,0,4},
	{0,0,5,0,0,2,0,6,0},
	{6,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,8,3,0,6},
	{2,0,0,4,9,0,0,7,0},
	{0,0,2,0,0,0,1,0,8},
	{0,0,0,8,5,0,0,0,0},
	{8,0,6,2,1,4,0,0,0}
};

int main()
{
	Sudoku sudoku;
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			sudoku.Setnum(i, j, a[i][j]);
		}
	}
	//bool f = sudoku.validationSudoku();
	bool f = sudoku.SolveSudoku();
	cout << f << endl;
	sudoku.showall();

	system("pause");


	return 0;
}