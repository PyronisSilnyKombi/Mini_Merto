#pragma once
#include<vector>
#include<list>
#include <GL/freeglut.h>
#include"cStation.h"


// friend z klas¹ sStation;
class cLine{
protected:
	int color_; //0 - red, 1 - blue, 2 - yellow, 3 - green, 4 - orange, 5 - purple, 6 - light blue;
	std::list<cStation*> line_stations_; // stores stations 1, 2, 3 ... , 1
	bool loop_;
	int length;

public:
	cLine(cStation &s, int color = 0, bool loop = false);
	
	bool Loop(); // spr czy linia jest petl¹;

	void erase_station(cStation& s);

	//getery
	bool loop() { return loop_; }
	char color() { return color_; }
	std::list<cStation*> line_stations() { return line_stations_; }

	//setery
	void set_color(const char& color) { color_ = color; }
	void set_loop(const bool& x) { loop_ = x; }


};

