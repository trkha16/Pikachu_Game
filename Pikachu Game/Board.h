#pragma once
#include <iostream>
#include <Windows.h>
#include "Common.h"
#include "Point.h"
using namespace std;

class Board{
private:
	Point** _A;
	int _size;
public:
	Board(int size); // Constructor khởi tạo Board
	static void DrawBoard(int); // Vẽ bảng game
	static void cellSelect(int, int, char); // Chọn ô nào sẽ hiển thị màu ở ô đó
};