//数独类实现 ： 2016年3月6日 ~  create by chenlei（3076954711）
#include "Sudoku.h"
#include <iostream>


using namespace std;
Sudoku::Sudoku()
{

}

Sudoku::~Sudoku()
{

}

void Sudoku::emptyyz()
{
	for (int i = 0;i <= 10;i++)
	{
		yz[i] = false;
	}
}

void Sudoku::Setnum(int x, int y, int num)
{
	a[x][y] = num;
}

bool Sudoku::validationSudoku()  /*这是用来验证数组是否正确的。*/
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

bool Sudoku::SolveSudoku()  /*这是用来解数独的*/
{
	bool f;
	int ne = 0;
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			if (a[i][j] == 0) ne++;
		}
	}


	for (int i = 0;i < 9;i++)
	{
		emptyyz();
		for (int j = 0;j < 9;j++)
		{
			if (a[i][j] == 0) continue;
			if (yz[a[i][j]])
			{
				return false;
			}
			else
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
			if (a[j][i] == 0) continue;
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
				if (a[i][j] == 0) continue;
				if (yz[a[j][k]]) return false; else
				{
					yz[a[j][k]] = true;
				}
			}
		}
	}
	
	for (int i = 0;i < 9;i++)
	{
		
		int x = 0;
		int wz = 0;
		emptyyz();
		for (int j = 0;j < 9;j++)
		{
			if (a[i][j] == 0)
			{
				x++;
				wz = j;
				continue; 
			}
			yz[a[i][j]] = true;
		}


		if (x == 1) /*判断这一行是否只有一个空*/
		{
			for (int j = 1;j <= 10;j++)
			{
				if (!yz[j])
				{
					a[i][wz] = j;
					break;
				}
			}
		}

	}

	return true;
}

void Sudoku::showall()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
