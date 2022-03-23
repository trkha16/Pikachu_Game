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
			solveMatching();
			break;
		default:
			break;
		}
	}
}

void Game::setX(int x) {
	_x = x;
}

void Game::setY(int y) {
	_y = y;
}

int Game::getX() {
	return _x;
}

int Game::getY() {
	return _y;
}

void Game::moveUp() {
	int posY = _y - _b->getCellRow() + 1;
	if (posY >= 3) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->deleteCellSelect(_x, _y);
		}
		_y = posY;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellSelect(_x, _y);
		}
	}
}

void Game::moveDown() {
	int posY = _y + _b->getCellRow() - 1;
	if (posY <= 3 + (_b->getSize() - 1) * (_b->getCellRow() - 1)) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->deleteCellSelect(_x, _y);
		}
		_y = posY;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellSelect(_x, _y);
		}
	}
}

void Game::moveLeft() {
	int posX = _x - _b->getCellCol() + 1;
	if (posX >= 5) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->deleteCellSelect(_x, _y);
		}
		_x = posX;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellSelect(_x, _y);
		}
	}
}

void Game::moveRight() {
	int posX = _x + _b->getCellCol() - 1;
	if (posX <= 5 + (_b->getSize() - 1) * (_b->getCellCol() - 1)) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->deleteCellSelect(_x, _y);
		}
		_x = posX;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellSelect(_x, _y);
		}
	}
}

bool Game::checkIMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	if ((iA != iB) && (jA != jB)) {
		return false;
	}
	
	if (checkCharacterMatching(firstBlock, secondBlock) == false) {
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

bool Game::checkZMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	return false;
}

bool Game::checkLMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	return false;
}

bool Game::checkUMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	return false;
}

bool Game::checkCharacterMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int xa = firstBlock.first;
	int ya = firstBlock.second;
	int xb = secondBlock.first;
	int yb = secondBlock.second;
	char firstChar = _b->getCharacterByIJ(xa, ya);
	char secondChar = _b->getCharacterByIJ(xb, yb);

	if (firstChar == secondChar) {
		return true;
	}
	return false;
}

bool Game::checkMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	return false;
}

void Game::solveMatching() {
	_cntEnter++;
	if (_cntEnter == 1) {
		_b->setCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		firstBlock = make_pair(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		_b->cellLockColor(_x, _y);
	}
	else {
		_b->setCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		secondBlock = make_pair(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		_cntEnter = 0;
	}
}