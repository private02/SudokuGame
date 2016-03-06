#include "Sudoku.h"

#include <iostream>
using namespace std;
int a[9][9] = {
	{4,6,1,9,7,5,0,8,3},
	{3,2,9,6,8,1,0,5,4},
	{7,8,5,3,4,2,0,6,1},
	{6,9,8,5,3,7,0,1,2},
	{5,4,7,1,2,8,0,9,6},
	{2,1,3,4,9,6,0,7,5},
	{9,5,2,7,6,3,0,4,8},
	{1,3,4,8,5,9,0,2,7},
	{8,7,6,2,1,4,0,3,9}
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

	bool f = sudoku.SolveSudoku();
	cout << f << endl;
	sudoku.showall();

	system("pause");
	return 0;
}