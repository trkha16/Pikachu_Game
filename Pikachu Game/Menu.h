#pragma once
#include <iostream>

#include <cctype>
#include "Common.h"
#include "Game.h"
#include "GTutorial.h"
#include <string>
using namespace std;

struct Menu {

	static string optionList[4];

	static void mainMenu();

	static void drawBorder(int upperleftX, int upperleftY, int width, int Hpercell, int soluong);
	static void setupMainOption();
	static void drawLogo();
	static string inputName(); // Nhập tên người chơi

	static void GameTitle();
	static void PlayMode();
	static void Tutorial();
	static void Leaderboard();
	static void endScreen(int, int); // Màn hình khi hoàn thành game
	static void ExitGame();
};