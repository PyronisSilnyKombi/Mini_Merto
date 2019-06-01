#include "cEngine.h"
#include <iostream>
#include <chrono>

cEngine::cEngine(){
	poziom_mapy_ = 1;
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

cEngine::~cEngine() {
	/*for (auto &el : figures)
		delete el;*/
}
