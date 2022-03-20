#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>

class Common {
public:
	static void setUpConsole(); // Hàm khởi tạo console 
	static void gotoXY(int, int); // Chuyen con tro den vi tri (x,y)
	static void hideScrollBars(); // Ẩn thanh cuộn chuột console 
	static void setConsoleTitle(); // Thay doi console title
	static void setConsoleColor(int); // Thay đổi màu chữ console 
	static int getConsoleInput(); // Lấy ký tự nhập từ bàn phím
};
