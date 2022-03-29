#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Menu {
	string Menus[5] = {
		"Play",
		"Tutorial",
		"Leaderboard",
		"Exit"
	};
	int index = 0;
};
