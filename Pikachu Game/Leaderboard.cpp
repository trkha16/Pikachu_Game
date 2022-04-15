#include "Leaderboard.h"

void Leaderboard::LeaderboardScreen() {
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