#include "Game.h"

Game::Game() {
	_x = 5; //  vị trí bắt đầu x = 5
	_y = 3; // vi trí bắt đầu y = 3
	_cntEnter = 0;
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
	_b->cellSelect(_x, _y);
	while (_isLoop) {
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
		{
			pair<int, int> a;
			pair<int, int> b; 

			_cntEnter++;
			if (_cntEnter == 1) {
				a = make_pair(_x,_y);
				_b->cellLockColor(_x, _y);
			}
			else {
				b = make_pair(_x, _y);
				_b->cellLockColor(_x, _y);
				_cntEnter = 0;
			}
			break;
		}
		default:
			break;
		}
	}
}

void Game::moveUp() {
	int posY = _y - _b->getCellRow() + 1;
	if (posY >= 3) {
		_b->deleteCellSelect(_x, _y);
		_y = posY;
		Common::gotoXY(_x, _y);
		_b->cellSelect(_x, _y);
	}
}

void Game::moveDown() {
	int posY = _y + _b->getCellRow() - 1;
	if (posY <= 3 + (_b->getSize() - 1) * (_b->getCellRow() - 1)) {
		_b->deleteCellSelect(_x, _y);
		_y = posY;
		Common::gotoXY(_x, _y);
		_b->cellSelect(_x, _y);
	}
}

void Game::moveLeft() {
	int posX = _x - _b->getCellCol() + 1;
	if (posX >= 5) {
		_b->deleteCellSelect(_x, _y);
		_x = posX;
		Common::gotoXY(_x, _y);
		_b->cellSelect(_x, _y);
	}
}

void Game::moveRight() {
	int posX = _x + _b->getCellCol() - 1;
	if (posX <= 5 + (_b->getSize() - 1) * (_b->getCellCol() - 1)) {
		_b->deleteCellSelect(_x, _y);
		_x = posX;
		Common::gotoXY(_x, _y);
		_b->cellSelect(_x, _y);
	}
}

bool Game::checkIMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = firstBlock.first;
	int jB = firstBlock.second;
	char firstChar = _b->getCharacterByIJ(iA, jA);
	char secondChar = _b->getCharacterByIJ(iB, jB);

	if ((iA != iB) && (jA != jB)) {
		return false;
	}
	if (firstChar != secondChar) {
		return false;
	}

	// Kiểm tra hàng dọc
	if (jA == jB) {
		if (iA > iB) {
			swap(iA, iB);
		}
		for (int i = iA + 1; i <= iB; i++) {
			if (i == iB) {
				return true;
			}
			if (_b->getCharacterByIJ(i, jA) != '0') {
				return false;
			}
		}
	}

	// Kiểm tra hàng ngang
	if (iA == iB) {
		if (jA > jB) {
			swap(jA, jB);
		}
		for (int i = jA + 1; i <= jB; i++) {
			if (i == jB) {
				return true;
			}
			if (_b->getCharacterByIJ(iA, i) != '0') {
				return false;
			}
		}
	}
}

bool Game::checkCharacterMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int xa = firstBlock.first;
	int ya = firstBlock.second;
	int xb = secondBlock.first;
	int yb = secondBlock.second;
	char firstChar = _b->getCharacterByIJ(xa, ya);
	char secondChar = _b->getCharacterByIJ(xb, yb);

	return firstChar == secondChar;
}