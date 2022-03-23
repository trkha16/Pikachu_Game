#pragma once
#include <iostream>
#include <Windows.h>
#include "Common.h"
using namespace std;

class Board {
private:
	int _size; // Size của bảng game, size x size
	char** _A; // Mảng 2 chiều lưu các characters
	int _cellRow; // ĐỘ CAO 1 Ô
	int _cellCol; // ĐỘ DÀI 1 Ô
public:
	Board(int); // Constructor khởi tạo Board
	~Board(); // Destructor 

	void drawBoard(); // Vẽ bảng game
	void cellSelect(int, int); // Lướt đến ô nào sẽ hiển thị màu ở ô đó
	void deleteCellSelect(int, int); // Lướt đến ô khác sẽ bỏ hiển thị màu ở ô này
	void randomCharacter(); // Random character
	void printCharacter(); // In mảng character đã random ra console 
	int getCellRow(); // Lấy độ cao 1 ô
	int getCellCol(); // lấy độ dài 1 ô
	int getSize(); // lấy giá trị size
	char getCharacterByXY(int, int); // Lấy ký tự tại ô có vị trí x y trên console 
	char getCharacterByIJ(int, int); // lấy ký tự tại ô có vị trí i j trên bảng
	int getXInConsole(int); // Lấy vị trí X trên console của character 
	int getYInConsole(int); // Lấy vị trí Y trên console của character
	void cellLockColor(int, int); // Khi nhấn enter ô đó
};