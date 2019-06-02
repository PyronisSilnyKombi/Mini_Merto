#pragma once
#include "cScene.h"
#include <GL/freeglut.h>

class cDraw_Locomotive {
	double x_, y_;

public:

	cDraw_Locomotive(double x, double y);
	void draw_locomotive();
	void add_wagon();
	void draw_passenger(char type);
	void change_position();
	void rotate(float angle);
	void set_color(double r, double g, double b);
	bool is_clicked(double openglX, double openglY);
	bool is_unclicked(double openglX, double openglY);
};
