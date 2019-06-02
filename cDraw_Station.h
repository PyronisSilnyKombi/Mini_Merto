#pragma once
#include <GL/freeglut.h>
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>

class cDraw_Station {
	double x_, y_;
	double color;
public:
	cDraw_Station(double x, double y);
	void draw_station();
	void draw_passenger(char type);
	void draw_overcrowd_timer(double angle);
	void set_color(double r, double g, double b);
	void set_x_y(double x, double y);
	//bool is_clicked(double openglX, double openglY);
	//bool is_unclicked(double openglX, double openglY);
};
