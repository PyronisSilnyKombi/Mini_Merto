#pragma once
#include <GL/freeglut.h>
#include<vector>
#include <list>
#include<string>

// dziedziczy z cFizyki i cFigury
class cPassengerStore{
protected:
	double x_, y_;
	int max_capacity_;
	std::vector<int> passengers_;  // 1 - circle, 2 - triangle, 3 - square, 4 - rhombus, 5 - pentagon, 6 - star, 7 - cross;


public:
	cPassengerStore(double x = 0, double y = 0, double max_capacity = 6);

	//getery
	std::vector<int> passengers() { return passengers_; } // zwraca wektor pasa¿erów ¿eby mo¿na by³o ich narysowac w lokomotywie i na przystankach
	double x() { return x_; };
	double y() { return y_; };
	int max_capacity() { return max_capacity_; };

	//setery
	void set_passengers(const std::vector<int> &passengers) { passengers_ = passengers; };
	void set_x(const double& x) { x_ = x; }
	void set_y(const double& y) { y_ = y; }
	
};