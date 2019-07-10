#pragma once
#include <GL/freeglut.h>
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cmath>
#include "cStation.h"


class cDraw_Line {
	double x_p, y_p;
	double x_k, y_k;
	double x_sr, y_sr;
	int color_;
	double angle_;
	double length_;

	// Dane odnoœnie adresów stacji pocz¹tkowej i stacji do której zmierza lokomotywa
	//cStation* beginning_[7];
	//cStation* destination_[7];
public:
	cDraw_Line(double xp, double yp, double xk, double yk, double angle, int color);
	void draw_line();
	double get_x_p();
	double get_y_p();
	double get_x_k();
	double get_y_k();
	double get_angle_();
	double get_x_sr_();
	double get_y_sr_();
	int get_color_();
	cStation* get_beginning_(int color);
	cStation* get_destination_(int color);
	void set_x_y_p(double x, double y);
	void set_x_y_k(double x, double y);
	void set_angle_(double angle);
	void set_length_(double length);
	void set_x_y_sr(double x, double y);
	void set_beginning_and_destination(cStation* b, cStation* d, int color);
	void set_beginning(cStation* b, int color);
	void set_destination(cStation* d, int color);
	bool warunek_usuniecia_linii(double glX, double glY);
	bool warunek_dodania_kolejki(double glX, double glY);
};
