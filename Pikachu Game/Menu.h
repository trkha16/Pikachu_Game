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

	void mainScreen(); // M�n h�nh ch�nh v�o game
	static void endScreen(); // M�n h�nh khi ho�n th�nh game
};
