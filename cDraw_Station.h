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
	bool czy_nalezy_do_linii_[7];

	int iloœæ_po³¹czeñ_dla_stacji_[7];
public:
	cDraw_Station(double x, double y,std::vector <int> passengers, int shape);
	void draw_station();
	void draw_passengers();
	void draw_overcrowd_timer(double angle);
	void set_color(double r, double g, double b);
	void set_x_y(double x, double y);
	double get_x();
	double get_y();
	int get_shape_();
	std::vector <int> get_passengers_();
	bool warunek_klikniecia(double glX, double glY);
	int get_iloœæ_po³¹czeñ_dla_stacji_(int color);
	void set_iloœæ_po³¹czeñ_dla_stacji_(int number, int color);
	void zwiêksz_iloœæ_po³¹czeñ_dla_stacji_(int color);
	void zmniejsz_iloœæ_po³¹czeñ_dla_stacji_(int color);
	bool get_czy_nalezy_do_linii_(int c);
	void set_czy_nalezy_do_linii_(bool tmp, int c);
	//bool is_clicked(double openglX, double openglY);
	//bool is_unclicked(double openglX, double openglY);
};
