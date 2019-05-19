#pragma once
#include <GL/freeglut.h>
#include "cFizyka.h"
#include<vector>
#include<string>

// dziedziczy z cFizyki i cFigury
class cPassengerStore : public cFizyka {
protected:
	unsigned int max_capacity_;
	std::vector<char> passengers_;  // c - circle, t - triangle, s - square, r - rhombus, p - pentagon, s - star, m - cross;


public:
	cPassengerStore(double max_capacity = 6);
	std::vector<char> passengers(); // zwraca wektor pasa¿erów ¿eby mo¿na by³o ich narysowac w lokomotywie i na przystankach


	//czêœæ Kacpra
	virtual void draw() = 0;
	void move(double dx, double dy);
	void rotate_clockwise();
	virtual  void update() = 0;
	void speed_up_x(const float& val);
	void speed_up_y(const float& val);
	void slow_down_x(const float& val);
	void slow_down_y(const float& val);
	virtual bool isClicked(double openglX, double openglY) = 0;
	virtual bool isUnclicked(double openglX, double openglY) = 0;
	void follow (double dx, double dy);
	void set_color(double r, double g, double b);
};