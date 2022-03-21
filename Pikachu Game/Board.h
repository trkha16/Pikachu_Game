#pragma once
#include <iostream>
#include <Windows.h>
#include "Common.h"
#include "Point.h"
using namespace std;

class Board{
private:
	int _size; // Size của bảng game, size x size
	char** _A; // Mảng 2 chiều lưu các characters
	int _cellRow; // ĐỘ CAO 1 Ô
	int _cellCol; // ĐỘ DÀI 1 Ô
public:
	Board(int); // Constructor khởi tạo Board
	~Board(); // Destructor 

	void drawBoard(); // Vẽ bảng game
	void cellSelect(int, int, char); // Chọn ô nào sẽ hiển thị màu ở ô đó
	void randomCharacter(); // Random character
	void printCharacter(); // In mảng character đã random ra console 
	int getCellRow(); // Lấy độ cao 1 ô
	int getCellCol(); // lấy độ dài 1 ô
	int getSize(); // lấy giá trị size
};