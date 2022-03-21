#pragma once

class Point {
private:
	int _x;
	int _y;
public:
	// Constructor
	Point(int, int);
	// Setter getter
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};