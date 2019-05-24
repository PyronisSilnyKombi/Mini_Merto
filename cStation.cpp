#include "cStation.h"
#include <iostream>

cStation::cStation(int shape, double x, double y, int capacity, int state) : cPassengerStore(x, y, capacity), shape_(shape), state_(state) {

}

cStation cStation::spawn(std::list<cStation*> &stations, const float &r, const float &x, const float &y, const int& poziom_mapy, int& tmp_lvl) {
	
	int figure; // 1 - circle, 2 - triangle, 3 - square, 4 - rhombus, 5 - pentagon, 6 - star, 7 - cross;
	
	do {
		if (stations.size() == 0) figure = 1;
		if (stations.size() == 1) figure = 2;
		if (stations.size() == 2) figure = 3;
		if (stations.size() > 2){
			int val = std::rand() % 100;
			if (val <= 50) figure = 1;
			if (val > 50 && val <= 75) figure = 2;
			if (val > 75 && val <= 85) figure = 3;
			if (val > 85 && val <= 96) figure = 4;
			if (val == 97 || val == 100 || val == 0) figure = 5;
			if (val == 98) figure = 6;
			if (val == 99) figure = 7;
		}
	} while (figure > poziom_mapy + 1);

	bool good;
	float tmp_x;
	float tmp_y;
	int acc = 0;
	do {
		good = true;
		tmp_x = (rand() % ((int)x * 100 / 2)) / 100.0f;
		tmp_y = (rand() % ((int)y * 100 / 2)) / 100.0f;
		if (rand() % 2) tmp_x = tmp_x * (-1);
		if (rand() % 2) tmp_y = tmp_y * (-1);

		for (auto el : stations) {
			if (sqrt(pow(el->x() - tmp_x, 2) + pow(el->y() - tmp_y, 2)) < r) good = 0;
		}
		acc++;
		if (acc > 50) break;
	} while (!good);

	cStation s(figure,tmp_x,tmp_y);
	if (!good) tmp_lvl = -1;
	else {
		if (figure == poziom_mapy + 1) tmp_lvl = figure;
		else tmp_lvl = poziom_mapy;
	}
	/*std::cout << s.x() << "  " << s.y() << "  " << s.shape() << "   " << s.state() << std::endl;*/

	return s;
}

void cStation::spawn_passenger(const int& poziom) {
	int figure; // 1 - circle, 2 - triangle, 3 - square, 4 - rhombus, 5 - pentagon, 6 - star, 7 - cross;
	int acc = 0;
	do {
		int val = std::rand() % 100;
		if (val <= 50) figure = 1;
		if (val > 50 && val <= 75) figure = 2;
		if (val > 75 && val <= 85) figure = 3;
		if (val > 85 && val <= 96) figure = 4;
		if (val == 97 || val == 100 || val == 0) figure = 5;
		if (val == 98) figure = 6;
		if (val == 99) figure = 7;

		acc++;
		if (acc > 50) return;
	} while (figure > poziom);
	if (figure != shape_)
	passengers_.push_back(figure);
}

int cStation::overcrowd() {
	state_ = 0;
	if (passengers_.size() >= 10) state_ = 1;
	if (passengers_.size() >= 20) state_ = 2;
	return state_;
}

void cStation::erase_passengers(cLocomotive& loco) {

}