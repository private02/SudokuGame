//数独类实现 ： 2016年3月6日  create by chenlei（3076954711）
#include "Sudoku.h"
#include <iostream>
#include <fstream>

//#include <Windows.h>
//#include <process.h>

using namespace std;
Sudoku::Sudoku()
{

}

Sudoku::~Sudoku()
{
	ofstream outry("d:\\a.txt");
	outry << "sudoku desctoucr" << endl;
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
		for (int j = location[i][1];j < location[i][3];j++)
		{
			for (int k = location[i][0];k < location[i][2];k++)
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
	//HANDLE hd;
	int num = 0;
	/*以下是直观法（未完善）*/
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
				int abc = 1 + 2;
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
		for (int j = location[i][1];j < location[i][3];j++)
		{
			for (int k = location[i][0];k < location[i][2];k++)
			{
				if (a[j][k] == 0) continue;
				if (yz[a[j][k]]) return false; else
				{
					yz[a[j][k]] = true;
				}
			}
		}
	}
	while (1)
	{
		if (num > 20)
			break;
		for (int i = 0;i < 9;i++)
		{

			int x = 0;
			int wz = -1;
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
						ne--;
						break;
					}
				}
			}

		}



		if (ne == 0)
		{
			return true;
		}



		for (int i = 0;i < 9;i++)
		{

			int x = 0;
			int wz = -1;
			emptyyz();

			for (int j = 0;j < 9;j++)
			{

				if (a[j][i] == 0)
				{
					x++;
					wz = j;
					continue;
				}
				yz[a[j][i]] = true;

			}


			if (x == 1) /*判断这一列是否只有一个空*/
			{
				for (int j = 1;j <= 10;j++)
				{
					if (!yz[j])
					{
						a[wz][i] = j;
						ne--;
						break;
					}
				}
			}

		}
		if (ne == 0)
		{

			return true;
		}

		for (int i = 0;i < 9;i++)
		{
			int x = 0, wzx = -1, wzy = -1;
			emptyyz();
			for (int j = location[i][1];j < location[i][3];j++)
			{
				for (int k = location[i][0];k < location[i][2];k++)
				{
					if (a[j][k] == 0)
					{
						x++;
						wzx = j;
						wzy = k;
						continue;
					}
					yz[a[j][k]] = true;
				}
			}


			if (x == 1) /*判断这个九宫格中是否只有一个空*/
			{
				for (int j = 1;j <= 10;j++)
				{
					if (!yz[j])
					{
						a[wzx][wzy] = j;
						ne--;
						break;
					}
				}
			}
		}

		if (ne == 0)
		{
			return true;
		}
		num++;
	}

	//int ap = 1;


	f = false;



	/*以下是候选数法*/
	Candidate(0,0,0);
	
	f = false;
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			a[i][j] = a2[i][j];
		}
	}

	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			if (a[i][j] == 0)
			{
				return false;
			}
		}
	}
	
	return true;
}

void Sudoku::showall()
{
	//ofstream out("d:/ans.txt");
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	
}


bool Sudoku::canplace(int h, int l, int x)
{
	return true;
}

void Sudoku::clear()
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			a[i][j] = 0;
		}
	}
}

int Sudoku::Seenum(int x, int y)
{
	return a[x][y];
}

bool Sudoku::compare(Sudoku & s)
{
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			if (s.Seenum(i, j) == 0)
			{
				continue;
			}
			if (s.Seenum(i, j) != a[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Sudoku::Candidate(int m, int x, int y)
{
	
}


