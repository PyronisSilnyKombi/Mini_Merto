#pragma once
#include "cScene.h"
#include <GL/freeglut.h>

class cDraw_Line {

public:

	void draw_line();
	void set_color(double r, double g, double b);
	bool is_clicked(double openglX, double openglY);
	bool is_unclicked(double openglX, double openglY);
	void change_position();
	friend class cLine;
};
