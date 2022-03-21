#include "Board.h"
#include "Common.h"
#include "Game.h"

int main() {
	Common::setUpConsole();
	Game g;
	g.startGame();
	return 0;
}