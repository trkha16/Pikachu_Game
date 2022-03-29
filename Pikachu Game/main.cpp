#include "Board.h"
#include "Common.h"
#include "Game.h"

int main() {
	srand(time(0));
	Common::setUpConsole();
	Game g;
	g.startGame();
	sleep(5000);
	return 0;
}