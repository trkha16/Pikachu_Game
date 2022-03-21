#pragma once
#include "Board.h"
#include "Common.h"

class Game {
private:
	int _x, _y; // Tọa độ x y của console 
	bool _isLoop; // true/ false: game chạy/ dừng
	bool _isWin; // Kiểm tra thắng
	bool _isLose; // Kiểm tra thua
	Board* _b; // Tạo bảng game
public:
	Game();
	~Game();

	void startGame(); // Bắt đầu game

	void moveUp(); // di chuyển lên trên
	void moveDown(); // di chuyển xuống
	void moveLeft(); // di chuyển sang trái
	void moveRight(); // di chuyển sang phải
};