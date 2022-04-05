#include "Board.h"
#include "Common.h"
#include "Game.h"
#include "Menu.h"

int main() {
	srand(time(0));
	Common::setUpConsole();
	/*Game g;
	g.startGame();*/
	Menu::leaderboardScreen();
	return 0;
}