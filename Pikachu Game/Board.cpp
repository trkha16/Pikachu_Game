#include "Board.h"
#include "Common.h"

Board::Board(int size) {
	_size = size;
	_A = new Point * [_size + 1];
	for (int i = 1; i <= _size; i++) {
		_A[i] = new Point[_size + 1];
	}
}

void Board::DrawBoard(int size) {
	int COLUMN = 8 * size + 1; // ĐỘ DÀI BẢNG
	int ROW = 4 * size + 1; // ĐỘ CAO BẢNG
	int cellRow = 5; // ĐỘ CAO 1 Ô
	int cellCol = 9; // ĐỘ DÀI 1 Ô

	// Tao bien tren cua bang
	Common::gotoXY(1, 1);
	putchar(201);
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(i, 1);
		if ((i - 1) % (cellCol - 1) == 0) {
			putchar(203);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(COLUMN, 1);
	putchar(187);

	// Tao bien duoi cua bang
	Common::gotoXY(1, ROW);
	putchar(200);
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(i, ROW);
		if ((i - 1) % (cellCol - 1) == 0) {
			putchar(202);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(COLUMN, ROW);
	putchar(188);

	//Tao bien trai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(1, i);
		if ((i - 1) % (cellRow - 1) == 0) {
			putchar(204);
		}
		else {
			putchar(186);
		}
	}

	//Tao bien phai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(COLUMN, i);
		if ((i - 1) % (cellRow - 1) == 0) {
			putchar(185);
		}
		else {
			putchar(186);
		}
	}

	// VE BANG THEO CHIEU NGANG

	for (int j = 2; j < COLUMN; j++) {
		int i = 5;
		while (i < ROW) {
			Common::gotoXY(j, i);
			if ((j - 1) % (cellCol - 1) == 0) {
				putchar(206);
			}
			else {
				putchar(205);
			}
			i += 4;
		}
		Sleep(10);
	}

	// VE BANG THEO CHIEU DOC

	for (int j = 2; j < ROW; j++) {
		int i = 9;
		while (i < COLUMN) {
			Common::gotoXY(i, j);
			if ((j - 1) % (cellRow - 1) == 0) {
				putchar(206);
			}
			else{
				putchar(186);
			}
			i += 8;
		}
		Sleep(20);
	}

	// Test
	int y = 3;
	while(y<=ROW) {
		int x = 5;
		while (x <= COLUMN) {
			Common::gotoXY(x, y);
			cout << "A";
			x += cellCol - 1;
		}
		y += cellRow - 1;
	}
}

void Board::cellSelect(int x,int y, char symbol) {

	/*for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 3; j <= x + 3; j++) {
			Common::gotoXY(j, i);
			putchar(219);
		}
	}*/
	Common::gotoXY(x, y);
	Common::setConsoleColor(2);
	cout << symbol;
}