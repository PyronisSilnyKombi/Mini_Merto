#pragma once
#include "cScene.h"
#include <GL/freeglut.h>

class cDraw_Locomotive {
	double x_, y_;
	double angle_;
	int color_;
	std::vector <int> passengers_;

public:

	cDraw_Locomotive(double x, double y, double angle);
	void draw_locomotive();
	void draw_passengers();

	void change_position();
	void rotate(float angle);
	void set_color(double r, double g, double b);
	//bool is_clicked(double openglX, double openglY);
	//bool is_unclicked(double openglX, double openglY);
};
