#include "cEngine.h"
#include <iostream>
#include <chrono>

cEngine::cEngine(int ilosc_wolnych_lokomotyw, int ilosc_wolnych_linii) : ilosc_wolnych_lokomotyw_(ilosc_wolnych_lokomotyw), ilosc_wolnych_linii_(ilosc_wolnych_linii){
	poziom_mapy_ = 1;
	ilosc_przewiezionych_pasazerow_ = 0;
	int tmp_lvl;
	srand(time(NULL));

	for (int i = 0; i < 3; i++) {
		cStation *s = new cStation(stations_, 2, 20, 20, poziom_mapy_, tmp_lvl);
		stations_.push_back(s);
		poziom_mapy_ = tmp_lvl;
	}

	for (auto el : stations_) {
		for (int i = 0; i < 10; i++)
		el->spawn_passenger(poziom_mapy_);
	}

}

void cEngine::add_station(const float &r, const float &x, const float &y) {
	srand(time(NULL));
	int tmp_lvl;
	cStation *s = new cStation(stations_, r, x, y, poziom_mapy_, tmp_lvl);
	stations_.push_back(s);
	poziom_mapy_ = tmp_lvl;
}

void cEngine::add_line(cStation &s) {
	cLine *l = new cLine(s, lines_.size());
	lines_.push_back(l);
}

void cEngine::erase_line(int& ktory) {
	lines_.erase(lines_.begin() + ktory);
	this->ustaw_kolory();
}

void cEngine::ustaw_kolory() {
	int acc = 0;
	for (auto el : lines_) {
		el->set_color(acc);
		acc++;
	}
}

cEngine::~cEngine() {
	/*for (auto &el : figures)
		delete el;*/
}