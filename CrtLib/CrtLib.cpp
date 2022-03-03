#include "pch.h"
#include "windows.h"

namespace crt
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	void GotoXY(int x, int y)
	{
		COORD cp;
		cp.X = x;
		cp.Y = y;
		SetConsoleCursorPosition(hStdOut, cp);
	}

	void ShowCursor(bool visible)
	{
		CONSOLE_CURSOR_INFO inf;
		GetConsoleCursorInfo(hStdOut, &inf);
		inf.bVisible = visible;
		SetConsoleCursorInfo(hStdOut, &inf);
	}

	void SetTextColor(int color)
	{
		CONSOLE_SCREEN_BUFFER_INFO inf;
		GetConsoleScreenBufferInfo(hStdOut, &inf);
		color = color & 0x0f;
		inf.wAttributes = inf.wAttributes & 0xf0;
		inf.wAttributes = inf.wAttributes | color;
		SetConsoleTextAttribute(hStdOut, inf.wAttributes);
	}


	void SetTextBackground(int color)
	{
		CONSOLE_SCREEN_BUFFER_INFO inf;
		GetConsoleScreenBufferInfo(hStdOut, &inf);
		color = color & 0x0f;
		inf.wAttributes = inf.wAttributes & 0x0f;
		inf.wAttributes = inf.wAttributes | (color << 4);
		SetConsoleTextAttribute(hStdOut, inf.wAttributes);
	}
}