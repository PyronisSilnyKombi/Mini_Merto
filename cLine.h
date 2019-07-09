#pragma once
#include<vector>
#include<list>
#include <GL/freeglut.h>
#include"cStation.h"

// friend z klas¹ sStation;
class cLine {
protected:
	int color_; //0 - red, 1 - blue, 2 - yellow, 3 - green, 4 - orange, 5 - purple, 6 - light blue;
	std::list<cStation*> line_stations_; // stores stations 1, 2, 3 ... , 1
	std::vector<cLocomotive*> line_loco_;
	bool loop_;

	void Loop(); // spr czy linia jest petl¹;
public:
	cLine(cStation &s, int color = 0, bool loop = false);
	cLine(std::list<cStation*> s, int color, bool loop); // Zmodyfikowa³em trochê konstruktor aby pasowa³ do kodu w którym przekazywane s¹ dane.

	//konstruktor domyœlny
	cLine()
	{
	}

	//getery
	bool loop() { Loop(); return loop_; }
	int color() { return color_; }
	std::list<cStation*> line_stations() { return line_stations_; }

	//setery
	void set_color(const int& color) { color_ = color; }
	void set_loop(const bool& x) { loop_ = x; }
	void set_line_stations(std::list<cStation*> line_stations) { line_stations_ = line_stations; }

	void loco_push_back(cLocomotive& loco);
	void loco_erase(cLocomotive& loco);

	//setery line_stationions_
	void push_back(cStation& s);
	void push_front(cStation& s);
	void pop_back();
	void pop_front();
	void insert(const int& miejsce, cStation& s);
	void erase(const int& ktora);
	void erase(cStation& s);
};

