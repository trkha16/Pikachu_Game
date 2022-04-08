#pragma once
#include <iostream>
#include <string>
#include "Common.h"
#include "Game.h"
#include "Board.h"
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

struct Menu {
	static void endScreen(int, int); // Màn hình khi hoàn thành game
	static void leaderboardScreen(); // Màn hình leaderboard
	static void drawBoardLeaderboard(); // vẽ bảng hiển thị của leaderboard
};
