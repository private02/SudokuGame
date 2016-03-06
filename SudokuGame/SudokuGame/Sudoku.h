//数独类 ： 2016年3月6日 ~  create by chenlei（3076954711）



#pragma once

#ifndef _SUDOKU_
#define _SUDOKU_





class Sudoku {
public:
	void emptyyz();
	
	void Setnum(int x, int y, int num);

	explicit Sudoku();
	
	~Sudoku();


	bool validationSudoku();

	bool SolveSudoku();

	void showall();
private:
	int a[9][9] = { 0 };
	bool yz[10] = { false };

	int location[9][4] =
	{
		{ 1,1,3,3 },
		{ 1,4,3,6 },
		{ 1,7,3,9 },
		{ 4,1,6,3 },
		{ 4,4,6,6 },
		{ 4,7,6,9 },
		{ 7,1,9,3 },
		{ 7,4,9,6 },
		{ 7,7,9,9 }
	};

};







#endif