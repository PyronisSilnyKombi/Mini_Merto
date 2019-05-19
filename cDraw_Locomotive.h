#pragma once
#include "cLocomotive.h"
#include <GL/freeglut.h>

class cDraw_locomotive {

public:

	void draw_locomotive();
	void add_wagon();
	void draw_passenger(char type);
	void change_position();
	void rotate(float angle);
	void set_color(double r, double g, double b);
	bool is_clicked(double openglX, double openglY);
	bool is_unclicked(double openglX, double openglY);
	friend class cLocomotive;
};
