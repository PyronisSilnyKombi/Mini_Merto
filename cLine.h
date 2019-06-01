#pragma once
#include<vector>
#include<list>
#include <GL/freeglut.h>
#include"cStation.h"


// friend z klas¹ sStation;
class cLine{
protected:
	char color_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue;
	std::list<cStation*> line_stations_; // stores stations 1, 2, 3 ... , 1
	bool loop_;

public:
	cLine(cStation &s, char color = 'r', bool loop = false);

	void erase_station(cStation& s);
	void add_station(cStation& s);

	bool Loop(); // spr czy linia jest petl¹;

	//getery
	bool loop() { return loop_; }
	char color() { return color_; }
	std::list<cStation*> line_stations() { return line_stations_; }

	//setery
	void set_color(const char& color) { color_ = color; }
	void set_loop(const bool& x) { loop_ = x; }


};

