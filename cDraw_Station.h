#pragma once
#include "cStation.h"
#include <GL/freeglut.h>

class cDraw_Station {

public:

	void draw_station();
	void draw_passenger(char type);
	void draw_overcrowd_timer(double angle);
	void set_color(double r, double g, double b);
	//bool is_clicked(double openglX, double openglY);
	//bool is_unclicked(double openglX, double openglY);
	friend class cStation;
};
