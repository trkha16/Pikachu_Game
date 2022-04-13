#include "Menu.h"

string Menu::optionList[] = { " PLAY", " HOW TO PLAY", " LEADERBOARD", " EXIT" };

void M(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++) {
			if (j == 0 || j == w) {
				Common::gotoXY(x + j, y + i);
				putchar(219);
			}

		}
	}
	int leftX = x + 1;
	int rightX = x + w - 1;
	int k = y;
	while (leftX <= rightX) {
		Common::gotoXY(leftX - 1, k);
		putchar(219);
		putchar(219);
		Common::gotoXY(rightX, k);
		putchar(219);
		putchar(219);
		k++;
		leftX++;
		rightX--;
	}

}

void A(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	int leftX = x;
	int rightX = x + w;
	int i = y + h;
	int midH = h / 2 + 1;
	while (leftX <= rightX) {
		if (i == y + midH) {
			int j = leftX + 1;
			Common::gotoXY(j, i);
			while (j < rightX) {
				putchar(254);
				j++;
			}
		}
		Common::gotoXY(leftX - 1, i);
		putchar(219);
		putchar(219);
		Common::gotoXY(rightX, i);
		putchar(219);
		putchar(219);
		i--;
		leftX++;
		rightX--;
	}
}

void T(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	Common::gotoXY(x, y);
	int midW = w / 2;
	for (int i = 0; i <= w; i++) {

		putchar(254);
	}
	for (int i = y + 1; i <= y + h; i++) {
		Common::gotoXY(x + midW, i);
		putchar(219);
	}

}

void C(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	for (int i = y; i <= y + h; i++) {
		if (i == y) {
			Common::gotoXY(x + 1, i);
			for (int j = x + 1; j <= x + w; j++) {
				putchar(219);
			}
		}
		else if (i == y + h) {
			Common::gotoXY(x + 1, i);
			for (int j = x + 1; j <= x + w; j++) {
				putchar(219);
			}
		}
		else {
			Common::gotoXY(x, i);
			putchar(219);
			putchar(219);
		}
	}
}

void H(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	for (int i = y; i <= y + h; i++) {
		if (i == y + h / 2) {
			Common::gotoXY(x + 1, i);
			for (int j = x + 1; j < x + w; j++) {
				putchar(254);
			}
		}
		Common::gotoXY(x, i);
		putchar(219);
		Common::gotoXY(x + w, i);
		putchar(219);
	}
}

void I(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);
	for (int i = y; i <= y + h; i++) {

		for (int j = x + 1; j <= x + w; j++) {
			Common::gotoXY(j, i);
			putchar(219);
		}
	}
}

void N(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	for (int i = y; i <= y + h; i++) {
		Common::gotoXY(x, i);
		putchar(219);
		Common::gotoXY(x + w, i);
		putchar(219);
	}

	int leftX = x + 1;
	int rightX = x + w - 1;
	int k = y;
	while (leftX <= rightX && k <= y + h) {
		Common::gotoXY(leftX++, k);
		putchar(219);
		k++;
	}

}

void G(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	for (int i = y; i <= y + h; i++) {
		if (i == y) {
			Common::gotoXY(x + 1, i);
			for (int j = x + 1; j <= x + w; j++) {
				putchar(219);
			}
		}
		else if (i == y + h) {
			Common::gotoXY(x + 1, i);
			for (int j = x + 1; j <= x + w; j++) {
				putchar(219);
			}
		}
		else {
			Common::gotoXY(x, i);
			putchar(219);
			putchar(219);
			if (i >= y + h / 2 && i < y + h) {
				if (i == y + h / 2) {
					Common::gotoXY(x + w - 2, i);
					putchar(219);
					putchar(219);
					putchar(219);
				}
				else {
					Common::gotoXY(x + w, i);
					putchar(219);
				}
			}
		}
	}
}

void E(int x, int y, int h, int w, int textcolor) {
	Common::setConsoleColor(BLACK, textcolor);

	for (int i = y; i <= y + h; i++) {
		if (i == y) {
			Common::gotoXY(x, i);
			for (int j = x; j <= x + w; j++)
				putchar(219);
		}
		else if (i == y + h / 3 + 1) {
			Common::gotoXY(x, i);
			for (int j = x; j <= x + w; j++)
				putchar(219);
		}
		else if (i == y + h) {
			Common::gotoXY(x, i);
			for (int j = x; j <= x + w; j++)
				putchar(219);
		}
		else {
			Common::gotoXY(x, i);
			putchar(219);
		}
	}
}

void Menu::drawLogo() {
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	Common::gotoXY(27, 3);
	cout << "  __  __   _ _____ ___ _  _ ___ _  _  ___    ___   _   __  __ ___ ";
	Common::gotoXY(27, 4);
	cout << " |  \\/  | /_\\_   _/ __| || |_ _| \\| |/ __|  / __| /_\\ |  \\/  | __|";
	Common::gotoXY(27, 5);
	cout << " | |\\/| |/ _ \\| || (__| __ || || .` | (_ | | (_ |/ _ \\| |\\/| | _| ";
	Common::gotoXY(27, 6);
	cout << " |_|  |_/_/ \\_\\_| \\___|_||_|___|_|\\_|\\___|  \\___/_/ \\_\\_|  |_|___|";
}

void Menu::GameTitle() {

	/*M(3, 2, 6, 9, RED);
	A(14, 2, 6, 9, BLUE);
	T(22, 2, 6, 6, YELLOW);
	C(28, 4, 3, 5, BRIGHT_WHITE);
	H(32, 2, 6, 6, LIGHT_RED);
	I(40, 4, 3, 2, LIGHT_PURPLE);
	N(45, 4, 3, 5, GRAY);
	G(52, 2, 6, 5, GREEN);

	G(65, 2, 6, 5, LIGHT_YELLOW);
	A(70, 0, 8, 12, LIGHT_GREEN);
	M(81, 2, 4, 7, RED);
	E(90, 2, 6, 6, AQUA);*/
	drawLogo();
}

void Menu::PlayMode() {
	Common::gotoXY(43, 11);
	Common::setConsoleColor(0, 6);
	//Common::setFontInfo(20, 30);
	cout << "Play Mode";
}

void Menu::Tutorial() {
	Tutorial1();
}

void Menu::Leaderboard() {
	Common::clearConsole();

	ifstream fs;
	fs.open("leaderboard.txt");

	struct Player {
		string name;
		int score;
		int time;
	};

	Player player[1000];
	string s;
	int size = 0;
		if (fs) {
			while (!fs.eof()) {
				getline(fs, player[size].name, '/');
				getline(fs, s, '/');
				player[size].score = stoi(s);
				getline(fs, s);
				player[size].time = stoi(s);
				size++;
			}

			for (int i = 0; i < size - 1; i++) {
				for (int j = i + 1; j < size; j++) {
					if (player[i].score < player[j].score) {
						swap(player[i], player[j]);
					}
					else if (player[i].score == player[j].score) {
						if (player[i].time > player[j].time) {
							swap(player[i], player[j]);
						}
					}
				}
			}

			//drawBoardLeaderboard();

			for (int i = 0; i < min(10, size - 1); i++) {
				//cout << player[i].score << endl;
				cout << player[i].name << " " << player[i].score << " " << player[i].time << endl;
			}
		}
		else {
			cout << "Error opening file";
		}
	fs.close();
}

void Menu::ExitGame() {
	system("cls");
	Common::showCursor(false);
	Common::setConsoleColor(BLACK, AQUA);
	drawBorder(20, 1, 45, 8, 1);

	Common::gotoXY(34, 3);
	//Common::setFontInfo(0, 36);
	cout << "Exit Confirmation";

	//Common::setFontInfo(0, 14);
	Common::gotoXY(26, 5);
	cout << "Are you sure you want to quit game?";

	int textcolor[] = { RED,WHITE };
	char key;
	int CurPos = 1;

	while (true) {
		Common::gotoXY(34, 7);
		Common::setConsoleColor(0, textcolor[0]);
		cout << "YES";

		Common::gotoXY(48, 7);
		Common::setConsoleColor(0, textcolor[1]);
		cout << "NO";

		key = _getch();

		if ((key == 77 || tolower(key) == 'd') && CurPos == 1)	//RIGHT ARROW
			CurPos++;
		if ((key == 75 || tolower(key) == 'a') && CurPos == 2)	//LEFT ARROW
			CurPos--;

		if (key == '\r') {
			if (CurPos == 1) {
				Common::gotoXY(19, 10);
				cout << "THANK YOU FOR PLAYING OUR GAME! HAVE A NICE DAY!" << endl;
				exit(EXIT_SUCCESS);
			}
			if (CurPos == 2) {
				system("cls");
				mainMenu();
			}
		}
		textcolor[0] = WHITE;
		textcolor[1] = WHITE;

		if (CurPos == 1)
			textcolor[0] = RED;
		if (CurPos == 2)
			textcolor[1] = GREEN;

	}
}

void Menu::drawBorder(int upperleftcornerX, int upperleftcornerY, int width, int Hpercell, int n) {
	int x = upperleftcornerX;
	int y = upperleftcornerY;

	for (int i = y; i <= y + Hpercell * n; i++) {
		if ((i - y) % Hpercell == 0) {
			if (i == y) {
				Common::gotoXY(x, i);
				putchar(218);		//goc trai tren
				Common::gotoXY(x + width, i);
				putchar(191);		//goc phai tren
			}
			else if (i < y + Hpercell * n) {
				Common::gotoXY(x, i);
				putchar(195);		//nga 3 sang trai
				Common::gotoXY(x + width, i);
				putchar(180);		//nga 3 sang phai
			}
			else {
				Common::gotoXY(x, i);
				putchar(192);		//goc trai duoi
				Common::gotoXY(x + width, i);
				putchar(217);		//goc phai duoi
			}
			Common::gotoXY(x + 1, i);
			for (int j = x + 1; j < x + width; j++) {
				putchar(196);		//bien ngang
			}
		}
		else {
			Common::gotoXY(x, i);
			putchar(179);			//bien doc
			Common::gotoXY(x + width, i);
			putchar(179);
		}

	}
}

void Menu::setupMainOption() {
	int setTextColor[] = { RED,YELLOW,YELLOW,YELLOW,YELLOW };
	char key;
	int pos = 1;

	Common::setConsoleColor(BLACK, YELLOW);
	drawBorder(55, 25, 16, 2, 4);

	/*int widthPerChar = 30;
	int heightPerChar = 20;*/
	//Common::setFontInfo(widthPerChar, heightPerChar);

	Common::showCursor(false);

	int Xfor1stOpt = 60;
	int Yfor1stOpt = 26;
	while (true) {
		Common::gotoXY(Xfor1stOpt, Yfor1stOpt);
		Common::setConsoleColor(BLACK, setTextColor[0]);

		cout << optionList[0];			//play

		Common::gotoXY(Xfor1stOpt - 3, Yfor1stOpt + 2);
		Common::setConsoleColor(BLACK, setTextColor[1]);

		cout << optionList[1];			//how to play

		Common::gotoXY(Xfor1stOpt - 3, Yfor1stOpt + 4);
		Common::setConsoleColor(BLACK, setTextColor[2]);

		cout << optionList[2];			//Leaderboard

		Common::gotoXY(Xfor1stOpt, Yfor1stOpt + 6);
		Common::setConsoleColor(BLACK, setTextColor[3]);

		cout << optionList[3];			//exit

		key = _getch();

		if ((key == 72 || tolower(key) == 'w') && (pos >= 1 && pos <= 4)) {
			if (pos > 1)
				pos--;
			else pos = 4;
		}// UP ARROW
		if ((key == 80 || tolower(key) == 's') && (pos >= 1 && pos <= 4)) {
			if (pos < 4)
				pos++;
			else pos = 1;
		}// DOWN ARROW
		if (key == '\r') {

			if (pos == 1) {
				Game g;
				g.startGame();
				break;
			}
			if (pos == 2) {
				system("cls");
				Tutorial();
				break;
			}
			if (pos == 3) {
				Leaderboard();
				break;
			}
			if (pos == 4) {
				ExitGame();
			}
		}
		setTextColor[0] = YELLOW;
		setTextColor[1] = YELLOW;
		setTextColor[2] = YELLOW;
		setTextColor[3] = YELLOW;

		if (pos == 1)
			setTextColor[0] = RED;
		if (pos == 2)
			setTextColor[1] = RED;
		if (pos == 3)
			setTextColor[2] = RED;
		if (pos == 4)
			setTextColor[3] = RED;
	}

}

void Menu::mainMenu() {
	Common::showCursor(false);

	GameTitle();
	setupMainOption();
}

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

string Menu::inputName() {
	Common::clearConsole();
	string s;
	cout << "YOUR NAME: ";
	getline(cin, s);
	return s;
}