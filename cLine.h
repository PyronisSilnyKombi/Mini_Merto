#pragma once
#include<vector>
#include <GL/freeglut.h>
#include"cStation.h"


// friend z klas¹ sStation;
class cLine{
protected:
	unsigned char color_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue;
	std::vector<cStation*> line_stations_; // stores stations 1, 2, 3 ... , 1
	bool loop_;

public:
	cLine(unsigned char color = 'r', bool loop = false);
	void erase_station(const cStation& a);
	void add_station(const cStation& a);

	bool Loop(); // spr czy linia jest petla;

	bool loop() { return loop_; }
	unsigned char color() { return color_; }

	void draw();

};

