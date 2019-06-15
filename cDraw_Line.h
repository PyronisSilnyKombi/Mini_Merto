#pragma once
#include <GL/freeglut.h>

class cDraw_Line {
	double x_p, y_p;
	double x_k, y_k;
	double color;
public:
	cDraw_Line(double xp, double yp, double xk, double yk);
	void draw_line();
	void set_color(double r, double g, double b);
	bool is_clicked(double openglX, double openglY);
	bool is_unclicked(double openglX, double openglY);
	void change_position();
	double get_x_p();
	double get_y_p();
	double get_x_k();
	double get_y_k();
	void set_x_y_p(double x, double y);
	void set_x_y_k(double x, double y);
};
