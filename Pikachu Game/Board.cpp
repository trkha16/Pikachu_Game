#include "Board.h"
#include "Common.h"

Board::Board(int size) {
	_size = size; // Khởi tạo size
	_cellRow = 5;
	_cellCol = 9;
	// Khởi tạo mảng characters
	_A = new char* [_size + 1];
	for (int i = 1; i <= _size; i++) {
		_A[i] = new char[_size + 1];
	}
}

Board::~Board()
{
	for (int i = 1; i <= _size; i++) {
		delete[] _A[i];
	}
	delete[] _A;
}



void Board::randomCharacter() {
	for (int i = 1; i <= _size; i++) {
		for (int j = 1; j <= _size; j++) {
			_A[i][j] = 'A';
		}
	}
}

void Board::printCharacter() {
	// Phần tử đầu tiên bắt đầu tại vị trí x = 5, y = 3
	int startX = 5, startY = 3;
	for (int i = 1; i <= _size; i++) {
		for (int j = 1; j <= _size; j++) {
			int x = startX + (j - 1) * (_cellCol - 1); // Công thức tính vị trí x của phần tử
			int y = startY + (i - 1) * (_cellRow - 1); // Công thức tính vị trí y của phần từ
			Common::gotoXY(x, y); // chuyển con trỏ console tới vị trí x y
			cout << _A[i][j]; // in character ra console 
		}
	}
}

void Board::drawBoard() {
	int COLUMN = 8 * _size + 1; // ĐỘ DÀI BẢNG
	int ROW = 4 * _size + 1; // ĐỘ CAO BẢNG

	// Tao bien tren cua bang
	Common::gotoXY(1, 1);
	putchar(201); // Góc trái trên
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(i, 1);
		if ((i - 1) % (_cellCol - 1) == 0) {
			putchar(203);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(COLUMN, 1);
	putchar(187); // góc phải trên

	// Tao bien duoi cua bang
	Common::gotoXY(1, ROW);
	putchar(200); // góc trái dưới
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(i, ROW);
		if ((i - 1) % (_cellCol - 1) == 0) {
			putchar(202);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(COLUMN, ROW);
	putchar(188); // góc phải dưới

	//Tao bien trai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(1, i);
		if ((i - 1) % (_cellRow - 1) == 0) {
			putchar(204);
		}
		else {
			putchar(186);
		}
	}

	//Tao bien phai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(COLUMN, i);
		if ((i - 1) % (_cellRow - 1) == 0) {
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
			if ((j - 1) % (_cellCol - 1) == 0) {
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
			if ((j - 1) % (_cellRow - 1) == 0) {
				putchar(206);
			}
			else{
				putchar(186);
			}
			i += 8;
		}
		Sleep(20);
	}
}

void Board::cellSelect(int x, int y, char symbol) {
	Common::gotoXY(x, y);
	Common::setConsoleColor(WHITE, BLACK);
	cout << symbol;
	Common::gotoXY(x, y);
}

int Board::getCellCol() {
	return _cellCol;
}

int Board::getCellRow() {
	return _cellRow;
}

int Board::getSize() {
	return _size;
}