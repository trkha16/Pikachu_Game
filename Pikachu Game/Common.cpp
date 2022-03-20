#include "Common.h"

void Common::setUpConsole() {
    Common::setConsoleTitle();
    Common::hideScrollBars();
}

void Common::gotoXY(int x, int y) {
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}


void Common::hideScrollBars()
{
    HWND hwnd = GetConsoleWindow();
    ShowScrollBar(hwnd, SB_BOTH, 0);
}

void Common::setConsoleTitle()
{
    SetConsoleTitle(L"PIKACHU GAME");
}

void Common::setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int Common::getConsoleInput() {
    int key = _getch();

	if (key == 27)                  //esc
		return 1;
	else if (key == 87 || key == 119) //W, w
		return 2;
	else if (key == 65 || key == 97)  //A, a
		return 3;
	else if (key == 68 || key == 100) //D, d
		return 4;
	else if (key == 83 || key == 115) //S, s
		return 5;
	else if (key == 13)             //Enter
		return 6;
	else
		return 0;                 //nút khác
}