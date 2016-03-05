#include "Sudoku.h"
#include <iostream>


using namespace std;

int a[9][9] = {
	{4,6,1,9,7,5,2,8,3},
	{3,2,9,6,8,1,7,5,4},
	{7,8,5,3,4,2,9,6,1},
	{6,9,8,5,3,7,4,1,2},
	{5,4,7,1,2,8,3,9,6},
	{2,1,3,4,9,6,8,7,5},
	{9,5,2,7,6,3,1,4,8},
	{1,3,4,8,5,9,6,2,7},
	{8,7,6,2,1,4,5,3,9}
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
	bool f = sudoku.validationSudoku();
	std::cout << f << std::endl;

	system("pause");
	return 0;
}