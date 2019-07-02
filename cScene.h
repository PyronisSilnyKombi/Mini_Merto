#pragma once
#include "cLocomotive.h"
#include "cStation.h"
#include "cPassengerStore.h"
#include "cLine.h"
#include "cEngine.h"
#include "cDraw_Station.h"
#include "cDraw_Locomotive.h"
#include "cDraw_Line.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>




void resize_binding(int width, int height);
//void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
void onMouseButton_binding(int button, int state, int x, int y);
//void mouse_binding(int button, int state, int x, int y);
void mouse_move_binding(int x, int y);
void timer_binding(int i);


class cMap {
public:
	cEngine silnik_;
protected:
	std::list<cDraw_Station*> stations_d;

	bool warunek_klikniecia_;
	bool warunek_wspolrzednych_;
	int tmp_id;
	double x_p_, y_p_; // Pozycja stacji z której chcemy poprowadziæ liniê. Jest potrzebna do dok³adnego narysowania linii ³¹cz¹cej dwie stacje.

	std::vector<cDraw_Line*> lines_d;

	bool was_clicked;
	cDraw_Line* adres_linii;
	//std::vector<cDraw_Locomotive*> locomotives_d;

public:
	cMap();
	~cMap();


	void resize(int width, int height);
	void timer();
//	void idle();
	void display();
	void init(int argc, char **argv, const char* window_name);
	void set_callbacks();
	void key(unsigned char key, int x, int y);
	//void mouse(int button, int state, int x, int y);
	void mouse_move(int x, int y);
	void onMouseButton(int button, int state, int x, int y);
};