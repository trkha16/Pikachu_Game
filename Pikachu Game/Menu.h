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
	static void endScreen(int, int); // M�n h�nh khi ho�n th�nh game
	static void leaderboardScreen(); // M�n h�nh leaderboard
};
