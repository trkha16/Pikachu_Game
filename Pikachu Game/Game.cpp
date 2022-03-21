#include "Game.h"

Game::Game() {
	_x = 5; //  vị trí bắt đầu x = 5
	_y = 3; // vi trí bắt đầu y = 3
	_isLoop = true; // Game đang chạy
	_b = new Board(6); // Tạo bảng game size = 6
}

Game::~Game() {
	delete _b;
	_b = nullptr;
}

void Game::startGame() {
	_b->drawBoard();
	_b->randomCharacter();
	_b->printCharacter();
	Common::gotoXY(5, 3);
	while (_isLoop) {
		_b->cellSelect(_x, _y, 'A');
		switch (Common::getConsoleInput())
		{
		case 1:
			Common::clearConsole();
			Common::setConsoleColor(WHITE, BLACK);
			return;
		case 2:
			moveUp();
			break;
		case 3:
			moveLeft();
			break;
		case 4:
			moveRight();
			break;
		case 5:
			moveDown();
			break;
		case 6:
			break;
		default:
			break;
		}
	}
}

void Game::moveUp() {
	Common::gotoXY(_x, _y);
	Common::setConsoleColor(BLACK, WHITE);
	cout << 'A';
	int posY = _y - _b->getCellRow() + 1;
	if (posY >= 3) {
		_y = posY;
		Common::gotoXY(_x, _y);
	}
}

void Game::moveDown() {
	Common::gotoXY(_x, _y);
	Common::setConsoleColor(BLACK, WHITE);
	cout << 'A';
	int posY = _y + _b->getCellRow() - 1;
	if (posY <= 3 + (_b->getSize() - 1) * (_b->getCellRow() - 1)) {
		_y = posY;
		Common::gotoXY(_x, _y);
	}
}

void Game::moveLeft() {
	Common::gotoXY(_x, _y);
	Common::setConsoleColor(BLACK, WHITE);
	cout << 'A';
	int posX = _x - _b->getCellCol() + 1;
	if (posX >= 5) {
		_x = posX;
		Common::gotoXY(_x, _y);
	}
}

void Game::moveRight() {
	Common::gotoXY(_x, _y);
	Common::setConsoleColor(BLACK, WHITE);
	cout << 'A';
	int posX = _x + _b->getCellCol() - 1;
	if (posX <= 5 + (_b->getSize() - 1) * (_b->getCellCol() - 1)) {
		_x = posX;
		Common::gotoXY(_x, _y);
	}
}