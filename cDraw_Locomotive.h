#pragma once
#include <GL/freeglut.h>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>

class cDraw_Locomotive {
	double x_, y_;
	double angle_;
	int color_;
	std::vector <int> passengers_;

public:

	cDraw_Locomotive(double x, double y, double angle);
	void draw_locomotive();
	void draw_passengers();

	void rotate(float angle);
	void set_color_(int color);
	void set_x_y_(double x, double y);
	void set_angle_(double angle);
	void set_passengers_(std::vector <int> passengers);
	double get_x_();
	double get_y_();

};
