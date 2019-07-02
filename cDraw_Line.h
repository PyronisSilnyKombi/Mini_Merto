#pragma once
#include <GL/freeglut.h>
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cmath>


class cDraw_Line {
	double x_p, y_p;
	double x_k, y_k;
	double x_sr, y_sr;
	double color_;
	double angle_;
	double length_;
public:
	cDraw_Line(double xp, double yp, double xk, double yk, double angle);
	void draw_line();
	void set_color(double r, double g, double b);
	double get_x_p();
	double get_y_p();
	double get_x_k();
	double get_y_k();
	double get_angle_();
	double get_x_sr_();
	double get_y_sr_();
	void set_x_y_p(double x, double y);
	void set_x_y_k(double x, double y);
	void set_angle_(double angle);
	void set_length_(double length);
	void set_x_y_sr(double x, double y);
	bool warunek_usuniecia_linii(double glX, double glY);
};
