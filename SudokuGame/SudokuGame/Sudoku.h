//数独类 ： 2016年3月6日  create by chenlei（3076954711）



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


	void Candidate(int m, int x, int y);

	bool canplace(int , int , int);

	void clear();

	int Seenum(int x, int y);

	bool compare(Sudoku& s);
private:
	int a[9][9] = { 0 };
	int a2[9][9] = { 0 };
	bool yz[10] = { false };

	int location[9][4] =
	{
		{ 0,0,2,2 },
		{ 0,3,2,5 },
		{ 0,6,2,8 },
		{ 3,0,5,2 },
		{ 3,3,5,5 },
		{ 3,6,5,8 },
		{ 6,0,8,2 },
		{ 6,3,8,5 },
		{ 6,6,8,8 }
	};
	
	bool f = false;
};







#endif


