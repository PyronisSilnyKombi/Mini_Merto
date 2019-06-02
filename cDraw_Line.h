#pragma once
#include <GL/freeglut.h>

class cDraw_line {
	double x_, y_;	//wspolrzedne potrzebne do rysowania obiektow
public:

	void draw_line();
	void set_color(double r, double g, double b);
	bool is_clicked(double openglX, double openglY);
	bool is_unclicked(double openglX, double openglY);
	void change_position();
	void set_x_y_(double x, double y)
	{
		x_ = x;
		y_ = y;
	}
};
