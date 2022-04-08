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

void Menu::leaderboardScreen() {
	ifstream fs;
	fs.open("leaderboard.txt");

	struct Player {
		string name;
		string score;
		string time;
	};

	Player player[1000];
	int size = 0;

	if (fs) {
		while (!fs.eof()) {
			getline(fs, player[size].name, '/');
			getline(fs, player[size].score, '/');
			getline(fs, player[size].time);
			size++;
		}

		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (player[i].score < player[j].score) {
					swap(player[i], player[j]);
				}
				else if (player[i].score == player[j].score) {
					if (player[i].time > player[j].time) {
						swap(player[j], player[i]);
					}
				}
			}
		}

		drawBoardLeaderboard();

		for (int i = 0; i < min(10, size - 1); i++) {
			cout << player[i].name << " " << player[i].score << " " << player[i].time << endl;

		}
	}
	else {
		cout << "Error opening file";
	}
	fs.close();
}

void Menu::drawBoardLeaderboard() {
	// Tao bien tren cua bang
	Common::gotoXY(1, 1);
	putchar(201); // Góc trái trên
	for (int i = 2; i < 55; i++) {
		Common::gotoXY(i, 1);
		if (i == 5 || i == 35 || i == 48) {
			putchar(203);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(55, 1);
	putchar(187); // góc phải trên

	// Tao bien duoi cua bang
	Common::gotoXY(1, 1 + 2 * 10);
	putchar(200); // góc trái dưới

	for (int i = 2; i < 55; i++) {
		Common::gotoXY(i, 1 + 2 * 10);
		if (i == 5 || i == 35 || i == 48) {
			putchar(202);
		}
		else {
			putchar(205);
		}
	}

	Common::gotoXY(55, 1 + 2 * 10);
	putchar(188); // góc phải dưới

	//Tao bien trai cua bang
	for (int i = 2; i < 1 + 2 * 10; i++) {
		Common::gotoXY(1, i);
		if ((i - 1) % 2 == 0) {
			putchar(204);
		}
		else {
			putchar(186);
		}
	}

	//Tao bien phai cua bang
	for (int i = 2; i < 1 + 2 * 10; i++) {
		Common::gotoXY(55, i);
		if ((i - 1) % (2) == 0) {
			putchar(185);
		}
		else {
			putchar(186);
		}
	}

	// VE BANG THEO CHIEU NGANG

	for (int j = 2; j < 55; j++) {
		int i = 3;
		while (i < 1 + 2 * 10) {
			Common::gotoXY(j, i);
			if (j == 5 || j == 35 || j == 48) {
				putchar(206);
			}
			else {
				putchar(205);
			}
			i += 2;
		}
	}

	// VE BANG THEO CHIEU DOC

	for (int i = 2; i < 1 + 2 * 10; i++) {
		// o 1
		int j = 5;
		Common::gotoXY(j, i);
		if ((i - 1) % 2 == 0) {
			putchar(206);
		}
		else {
			putchar(186);
		}

		// o 2
		j = 35;
		Common::gotoXY(j, i);
		if ((i - 1) % 2 == 0) {
			putchar(206);
		}
		else {
			putchar(186);
		}

		// o 3
		j = 48;
		Common::gotoXY(j, i);
		if ((i - 1) % 2 == 0) {
			putchar(206);
		}
		else {
			putchar(186);
		}
	}
}