#pragma once
#include "Board.h"

class Game {
private:
	int _x, _y; // Tọa độ x y của console 
	bool _isLoop; // true/ false: game chạy/ dừng
	bool _isWin;
	bool _isLose;
	Board* _b;
public:
	Game();
	~Game();

	void startGame();

	void moveUp(); // di chuyển lên trên
	void moveDown(); // di chuyển xuống
	void moveLeft(); // di chuyển sang trái
	void moveRight(); // di chuyển sang phải
};