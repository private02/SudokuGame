//数独游戏主程序：2016-3-8 ~ 2016-3-10 create by chenlei
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Sudoku.h"
int zggs = 0;
using namespace std;
LRESULT CALLBACK WinSunProc
(
	HWND hwnd,
	UINT uMsg,

	WPARAM wParam,
	LPARAM lParam
	);

int WINAPI WinMain
(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,

	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;

	wndcls.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);

	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;

	wndcls.lpfnWndProc = WinSunProc;
	wndcls.lpszClassName = "Visual C++ Game";

	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);
	HWND hwnd;

	hwnd = CreateWindow(
		"Visual C++ Game",
		"Visual C++ 游戏开发",
		WS_OVERLAPPEDWINDOW,

		0,
		0,
		800,
		800,

		NULL,
		NULL,
		hInstance,
		NULL);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT uMsg,

	WPARAM wParam,
	LPARAM lParam
	)
{
	ifstream in("d:\\my.txt");
	
	//ofstream out("d:\\ans.txt");
	Sudoku s;
	char str[30] = { 0 };
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		if (IDYES == MessageBox(hwnd, "是否保存此次闯关信息？", "是否保存此次闯关信息？", MB_YESNOCANCEL))
		{
			ofstream outsud("d:\\out.sud");
			outsud << zggs;
			
		}
		PostQuitMessage(0);
		return 0;
	}
	case WM_PAINT:
	{
		
		HDC  hdc;
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);
		for (int ii = 0;ii < 31;ii++)
		{
			ofstream out("d:\\ans.txt");
			in >> str;
			int lo = 0;
			while (str[lo] != 0)
			{
				lo++;
			}
			TextOut(hdc, 0, 0, str, lo);
			for (int j = 0;j < 81;j++)
			{
				int x;
				in >> x;
				out << x << " ";
				if (j % 9 == 8)
				{
					out << "\n";

				}
				char st[1] = { 0 };
				st[0] = x + 48;
				TextOut(hdc, j % 9 * 20 + 20, j / 9 * 20 + 20, st, 1);
			}
			out.~basic_ofstream();
			system("\"d:\\ans.txt\"");
			while (IDNO == MessageBox(hwnd, "如果已经把答案保存好，请按是继续", "如果已经把答案保存好，请按是继续", MB_YESNO));
			ifstream sui("d:/ans.txt");
			Sudoku x;
			for (int j = 0;j < 9;j++)
			{
				for (int k = 0;k < 9;k++)
				{
					x.Setnum(j, k, s.Seenum(j,k));
				}
			}
			for (int j = 0;j < 9;j++)
			{
				for (int k = 0;k < 9;k++)
				{
					int xx;
					sui >> xx;
					s.Setnum(j, k, xx);
				}
			}
			bool rf = true;//(s.compare(x) && s.validationSudoku());
			sui.~basic_ifstream();
			if (!rf)
			{
				system("\"d:\\ans.txt\"");
				while (IDNO == MessageBox(hwnd, "点是开始第二次验证，请保证正确", "点是开始第二次验证，请保证正确", MB_YESNO));
				ifstream sui("d:/ans.txt");
				x.clear();
				//Sudoku xy;
				for (int j = 0;j < 9;j++)
				{
					for (int k = 0;k < 9;k++)
					{
						x.Setnum(j, k, s.Seenum(j, k));
					}
				}
				for (int j = 0;j < 9;j++)
				{
					for (int k = 0;k < 9;k++)
					{
						int xx;
						sui >> xx;
						s.Setnum(j, k, xx);
					}
				}
				bool rf = (s.compare(x) && s.validationSudoku());
				if (!rf)
				{
					
				}
				else {
					zggs++;
					
				}
			}
			else {
				zggs++;
				
			}
			x.~Sudoku();
		}
		EndPaint(hwnd, &ps);
		return 0;
	}
	/*case WM_KEYDOWN:
	{
		switch ((int)wParam)
		{
		case VK_LEFT:
		{
			return 0;
		}
		}
	}*/
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

