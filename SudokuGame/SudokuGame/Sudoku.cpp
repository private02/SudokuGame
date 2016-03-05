//数独类实现 ： 2016年3月6日 ~  create by chenlei（3076954711）
#include "Sudoku.h"

Sudoku::Sudoku()
{

}

Sudoku::~Sudoku()
{

}

void Sudoku::emptyyz()
{
	for (int i = 0;i < 10;i++)
	{
		yz[i] = false;
	}
}

void Sudoku::Setnum(int x, int y, int num)
{
	a[x][y] = num;
}

bool Sudoku::validationSudoku()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			if (a[i][j] == 0) return false;
		}
	}


	for (int i = 0;i < 9;i++)
	{
		emptyyz();
		for (int j = 0;j < 9;j++)
		{
			if (yz[a[i][j]]) return false; else
			{
				yz[a[i][j]] = true;
			}
		}
	}

	for (int i = 0;i < 9;i++)
	{
		emptyyz();
		for (int j = 0;j < 9;j++)
		{
			if (yz[a[j][i]]) return false; else
			{
				yz[a[j][i]] = true;
			}
		}
	}

	for (int i = 0;i < 9;i++)
	{
		emptyyz();
		for (int j = location[i][2];j < location[i][4];j++)
		{
			for (int k = location[i][1];k < location[i][3];k++)
			{
				if (yz[a[j][k]]) return false; else
				{
					yz[a[j][k]] = true;
				}
			}
		}
	}


	return true;
}
