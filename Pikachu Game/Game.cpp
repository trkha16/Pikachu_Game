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
	_b->cellColor(_x, _y, WHITE, BLACK);
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
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_y = posY;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

void Game::moveDown() {
	int posY = _y + _b->getCellRow() - 1;
	if (posY <= 3 + (_b->getSize() - 1) * (_b->getCellRow() - 1)) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_y = posY;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

void Game::moveLeft() {
	int posX = _x - _b->getCellCol() + 1;
	if (posX >= 5) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_x = posX;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

void Game::moveRight() {
	int posX = _x + _b->getCellCol() - 1;
	if (posX <= 5 + (_b->getSize() - 1) * (_b->getCellCol() - 1)) {
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_x = posX;
		Common::gotoXY(_x, _y);
		if (!_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x))) {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

bool Game::checkIMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	if (iA == iB && jA == jB) return true; // 2 điểm là một

	// Không cùng hàng hoặc cột
	if ((iA != iB) && (jA != jB)) {
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
	// Duyệt theo chiều ngang dọc ngang
	// điểm 1 nằm bên trái, điểm 2 nằm bên phải
	if (firstBlock.second > secondBlock.second) {
		swap(firstBlock, secondBlock);
	}

	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	for (int i = jA; i <= jB; i++) {
		pair<int, int> break1(iA, i);
		pair<int, int> break2(iB, i);
		bool line1 = checkIMatching(firstBlock, break1);
		bool line2 = checkIMatching(break1, break2);
		bool line3 = checkIMatching(break2, secondBlock);

		if (line1 && line2 && line3) return true;
	}

	// Duyệt theo chiều dọc ngang dọc
	// Điểm 1 nằm ở trên, điểm 2 nằm ở dưới
	if (firstBlock.first > secondBlock.first) {
		swap(firstBlock, secondBlock);
	}

	iA = firstBlock.first;
	jA = firstBlock.second;
	iB = secondBlock.first;
	jB = secondBlock.second;

	for (int i = iA; i <= iB; i++) {
		pair<int, int> break1(i, jA);
		pair<int, int> break2(i, jB);
		bool line1 = checkIMatching(firstBlock, break1);
		bool line2 = checkIMatching(break1, break2);
		bool line3 = checkIMatching(break2, secondBlock);

		if (line1 && line2 && line3) return true;
	}

	return false;
}

bool Game::checkUMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	// Duyệt theo chiều ngang dọc ngang
	// điểm 1 nằm bên trên, điểm 2 nằm bên dưới
	if (firstBlock.first > secondBlock.first) {
		swap(firstBlock, secondBlock);
	}

	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	for (int i = 0; i <= _b->getSize() + 1; i++) {
		pair<int, int> break1(iA, i);
		pair<int, int> break2(iB, i);
		bool line1 = checkIMatching(firstBlock, break1);
		bool line2 = checkIMatching(break1, break2);
		bool line3 = checkIMatching(break2, secondBlock);

		if (line1 && line2 && line3) return true;
	}

	// Duyệt theo chiều dọc ngang dọc
	// điểm 1 nằm bên trái, điểm 2 nằm bên phải
	if (firstBlock.second > secondBlock.second) {
		swap(firstBlock, secondBlock);
	}

	iA = firstBlock.first;
	jA = firstBlock.second;
	iB = secondBlock.first;
	jB = secondBlock.second;

	for (int i = 0; i <= _b->getSize() + 1; i++) {
		pair<int, int> break1(i, jA);
		pair<int, int> break2(i, jB);
		bool line1 = checkIMatching(firstBlock, break1);
		bool line2 = checkIMatching(break1, break2);
		bool line3 = checkIMatching(break2, secondBlock);

		if (line1 && line2 && line3) return true;
	}

	return false;
}

bool Game::checkCharacterMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int xa = firstBlock.first;
	int ya = firstBlock.second;
	int xb = secondBlock.first;
	int yb = secondBlock.second;
	char firstChar = _b->getCharacterByIJ(xa, ya); // Giá trị block 1
	char secondChar = _b->getCharacterByIJ(xb, yb); // Giá trị block 2

	if (firstChar == secondChar) {
		return true;
	}
	return false;
}

bool Game::checkMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	// Giá trị của 2 ô khác nhau thì false
	if (checkCharacterMatching(firstBlock, secondBlock) == false) {
		return false;
	}

	// Kiểm tra xem 2 ô đó có trùng vị trí hay không
	if (firstBlock.first == secondBlock.first && firstBlock.second == secondBlock.second) {
		return false;
	}

	return checkIMatching(firstBlock, secondBlock) || checkUMatching(firstBlock, secondBlock);
}

void Game::solveMatching() {
	_cntEnter++;
	if (_cntEnter == 1) {
		_b->setCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lock ô thứ 1
		firstBlock = make_pair(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lưu index ô thứ 1
		_b->cellColor(_x, _y, BLUE, WHITE); // Hiện màu đã chọn ô thứ 1
	}
	else {
		int iA = firstBlock.first; // i của ô 1
		int jA = firstBlock.second; // j của ô 1
		_b->setCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lock ô thứ 2
		secondBlock = make_pair(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lưu index ô thứ 2
		int iB = secondBlock.first; // i của ô 2
		int jB = secondBlock.second; // j của ô 2

		// ô 1 và ô 2 match với nhau
		if (checkMatching(firstBlock, secondBlock) == true) {
			_b->setCharacterByIJ(iA, jA); // xóa ô 1 trong bảng
			_b->setCharacterByIJ(iB, jB); // xóa ô 2 trong mảng

			// TEST
			Common::gotoXY(50, 0);
			cout << checkMatching(firstBlock, secondBlock);
			
			// Tô lại màu cho ô 1
			Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
			_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), BLACK, BLACK);

			// Tô lại màu cho ô 2
			Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
			_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), BLACK, BLACK);
		}
		else { // Nếu 2 ô không match với nhau
			_b->setCharacterLocked(firstBlock.first, firstBlock.second); // Bỏ lock ô 1
			_b->setCharacterLocked(secondBlock.first, secondBlock.second); // Bỏ lock ô 2

			// Tô lại màu cho ô 1
			Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
			_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), BLACK, WHITE);

			// Tô lại màu cho ô 2
			Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
			_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), BLACK, WHITE);
		}

		// reset biến count
		_cntEnter = 0;
	}
}