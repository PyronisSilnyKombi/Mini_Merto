#pragma once
#include <GL/freeglut.h>
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

class cDraw_Station {
	double x_, y_;
	//double color;
	int shape_;
	std::vector <int> passengers_;
	std::vector<bool> czy_nalezy_do_linii;
public:
	cDraw_Station(double x, double y,std::vector <int> passengers, int shape);
	void draw_station();
	void draw_passengers();
	void draw_overcrowd_timer(double angle);
	void set_color(double r, double g, double b);
	void set_x_y(double x, double y);
	double get_x();
	double get_y();
	bool warunek_klikniecia(double glX, double glY);
	//bool is_clicked(double openglX, double openglY);
	//bool is_unclicked(double openglX, double openglY);
};
