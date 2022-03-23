#pragma once
#include "Board.h"
#include "Common.h"
#include <algorithm>
using namespace std;

class Game {
private:
	int _x, _y; // Tọa độ x y của console 
	bool _isLoop; // true/ false: game chạy/ dừng
	bool _isWin; // Kiểm tra thắng
	bool _isLose; // Kiểm tra thua
	int _cntEnter; // Biến enter
	Board* _b; // Tạo bảng game
public:
	Game();
	~Game();

	void startGame(); // Bắt đầu game

	void moveUp(); // di chuyển lên trên
	void moveDown(); // di chuyển xuống
	void moveLeft(); // di chuyển sang trái
	void moveRight(); // di chuyển sang phải

	bool checkIMatching(pair<int, int>, pair<int, int>);
	bool checkZMatching(pair<int, int>, pair<int, int>);
	bool checkLMatching(pair<int, int>, pair<int, int>);
	bool checkUMatching(pair<int, int>, pair<int, int>);
	bool checkCharacterMatching(pair<int, int>, pair<int, int>); // Kiểm tra giá trị 2 char có bằng nhau
};