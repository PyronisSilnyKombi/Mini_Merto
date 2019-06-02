#include "cLocomotive.h"

cLocomotive::cLocomotive(cLine &line, double x, double y, int capacity) :cPassengerStore(x, y, capacity) {
	line_ = &line;
	line_color_ = line_->color();
}

void cLocomotive::drop(cLine& l, cStation& s1,  cStation& s2) {
	line_color_ = l.color();
	previous_station_ = &s2;
	next_station_ = &s2;
}



int cLocomotive::unload(cStation& s) {
	int tmp_shape = s.shape();
	int points = 0;
	for (auto itr = passengers_.begin(); itr < passengers_.end(); itr++) {
		if (*itr == tmp_shape) {
			passengers_.erase(itr);
			itr--;
			points++;
		}
	}
	return points;
}

void cLocomotive::interchange(cStation& s) {
	for (auto itr = passengers_.begin(); itr < passengers_.end(); itr++) {
		if (this->change(*itr)) {
			s.add_passenger(*itr);
			passengers_.erase(itr);
			itr--;
		}
	}
}

bool cLocomotive::change(int& p) {
	for (auto el : line_->line_stations()) {
		if (el->shape() == p) {
			return false;
		}
	}
	return true;
}

int cLocomotive::load(cStation& s) {
	int acc = 0;
	for (auto itr = s.passengers().begin(); itr < s.passengers().end(); itr++) {
		if (!s.change(line_->line_stations(), *itr)) {
			if (passengers_.size() < max_capacity_) {
				this->passengers_.push_back(*itr);
				s.passengers().erase(itr);
				itr--;
				acc++;
			}
		}
		if (passengers_.size() == max_capacity_) break;
	}
	return acc;
}

void cLocomotive::add_passenger(const int& i) {
	passengers_.push_back(i);
}
