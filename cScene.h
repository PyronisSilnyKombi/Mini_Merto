#pragma once
#include "cLocomotive.h"
#include "cStation.h"
#include "cPassengerStore.h"
#include "cLine.h"
#include <vector>

void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
//void mouse_binding(int button, int state, int x, int y);
void mouse_move_binding(int x, int y);
void timer_binding(int i);

class cMap {
	std::vector<cStation> stations;
	std::vector<cLine> lines;
	std::vector<cLocomotive> locomotives;
	//std::vector<cPassengerStore*> figures;

	unsigned int ilosc_przewiezionych_pasazerow;
	unsigned int ilosc_wolnych_lokomotyw;
	unsigned int ilosc_wolnych_linii;

	
	
public:
	cMap();
	~cMap();
	
	void wybierz_bonus(); // wyswietlane po uplywie tyg do wyboru dodatkowa linia lub lokomotywa



	void resize(int width, int height);
	void timer();
	void idle();
	void display();
	void init(int argc, char **argv, const char* window_name);
	void set_callbacks();
	void key(unsigned char key, int x, int y);
	//void mouse(int button, int state, int x, int y);
	void mouse_move(int x, int y);
};