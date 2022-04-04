#pragma once
#include <iostream>
#include <string>
#include "Common.h"
#include "Game.h"
using namespace std;

struct Menu {
	string _Menu[5] = {
		"PLAY",
		"TUTORIAL",
		"LEADERBOARD",
		"EXIT"
	};
	int index = 0;

	void mainScreen(); // Màn hình chính vào game
	static void endScreen(); // Màn hình khi hoàn thành game
};
