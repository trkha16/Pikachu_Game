#include "Menu.h"

void Menu::endScreen(int score, int time) {
	Common::clearConsole();
	// In chữ victory
	{
		Common::setConsoleColor(BLACK, LIGHT_GREEN);
		Common::gotoXY(25, 10);
		cout << "      (`-.                     .-') _                _  .-')               ";
		Common::gotoXY(25, 11);
		cout << "    _(OO  )_                  (  OO) )              ( \\( -O )              ";
		Common::gotoXY(25, 12);
		cout << ",--(_/   ,. \\ ,-.-')   .-----./     '._  .-'),-----. ,------.   ,--.   ,--.";
		Common::gotoXY(25, 13);
		cout << "\\   \\   /(__/ |  |OO) '  .--./|'--...__)( OO'  .-.  '|   /`. '   \\  `.'  / ";
		Common::gotoXY(25, 14);
		cout << " \\   \\ /   /  |  |  \\ |  |('-.'--.  .--'/   |  | |  ||  /  | | .-')     /  ";
		Common::gotoXY(25, 15);
		cout << "  \\   '   /,  |  |(_//_) |OO  )  |  |   \\_) |  |\\|  ||  |_.' |(OO  \\   /   ";
		Common::gotoXY(25, 16);
		cout << "   \\     /__),|  |_.'||  |`-'|   |  |     \\ |  | |  ||  .  '.' |   /  /\\_  ";
		Common::gotoXY(25, 17);
		cout << "    \\   /   (_|  |  (_'  '--'\\   |  |      `'  '-'  '|  |\\  \\  `-./  /.__) ";
		Common::gotoXY(25, 18);
		cout << "     `-'      `--'     `-----'   `--'        `-----' `--' '--'   `--'      ";
	} // In chữ victory
	Common::gotoXY(50, 30);
	cout << "SCORE: " << score;
	Common::gotoXY(50, 31);
	cout << "TIME: " << time;
	while (true) {
		int ch = Common::getConsoleInput();
		if (ch == 6) {
			break;
		}
	}
	Game g;
	g.startGame();
}