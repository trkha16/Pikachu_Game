#include "Board.h"
#include "Common.h"

int main() {
	Common::setUpConsole();
	Board::DrawBoard(6);
	Common::gotoXY(0, 20);
	while (true) {
		cout << Common::getConsoleInput() << endl;
	}
	Sleep(10000);
	return 0;
}