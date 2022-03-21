#include "Board.h"
#include "Common.h"
#include "Game.h"

int main() {
	Common::setUpConsole();
	//Board::Board(4);
	Game g;
	g.startGame();
	return 0;
}