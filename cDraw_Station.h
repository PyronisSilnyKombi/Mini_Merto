#pragma once
#include <GL/freeglut.h>

class cDraw_Station {
	double x_, y_;	//wspolrzedne potrzebne do rysowania obiektow
public:

	void draw_station();
	void draw_passenger(char type);
	void draw_overcrowd_timer(double angle);
	void set_color(double r, double g, double b);
	//bool is_clicked(double openglX, double openglY);
	//bool is_unclicked(double openglX, double openglY);
	void set_x_y_(double x, double y)
	{
		x_ = x;
		y_ = y;
	}
};
