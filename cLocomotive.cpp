#include "cLocomotive.h"

cLocomotive::cLocomotive(double x, double y, int capacity) :cPassengerStore(x, y, capacity) {
	previous_station_ = NULL;
	present_station_ = NULL;
	next_station_ = NULL;
	line_ = NULL;
	line_color_ = NULL;
	v_ = 0;
	alpha_v_ = 0;
	czas_ = 0;
	czas_postoju_ = 0;
	moving_forward_ = true;
	stop_ = true;
}

void cLocomotive::drop(cLine& l, cStation& s1,  cStation& s2) {
	line_ = &l;
	line_->loco_push_back(*this);
	line_color_ = l.color();
	set_loco_drop(s2, s1); // ustawia prêdkoœæ i kierunek w stronê bli¿szej stacji
}

void cLocomotive::set_loco_drop(cStation& s1, cStation& s2) {
	if (sqrt(pow(s1.x() - x_, 2) + pow(s1.y() - y_, 2)) < sqrt(pow(s2.x() - x_, 2) + pow(s2.y() - y_, 2))) {
		next_station_ = &s1;
		previous_station_ = &s2;
	} else {
		next_station_ = &s2;
		previous_station_ = &s1;	
	}
	angle();
	set_moving_forward();
	stop_ = false;
	v_ = 100e-4;

}

void cLocomotive::set_moving_forward() {
	for (auto el : line_->line_stations()) {
		if (el == next_station_) {
			moving_forward_ = false;
			break;
		}
		if (el == previous_station_) {
			moving_forward_ = true;
			break;
		}
	}
}

void cLocomotive::take() {
	line_->loco_erase(*this);
	passengers_.clear();

	previous_station_ = NULL;
	present_station_ = NULL;
	next_station_ = NULL;
	line_ = NULL;
	line_color_ = NULL;
	v_ = 0;
	alpha_v_ = 0;
	czas_ = 0;
	czas_postoju_ = 0;
	moving_forward_ = true;
	stop_ = true;
}

void cLocomotive::take(const int & x, const int & y) {
	set_x(x);
	set_y(y);

	line_->loco_erase(*this);
	passengers_.clear();

	previous_station_ = NULL;
	present_station_ = NULL;
	next_station_ = NULL;
	line_ = NULL;
	line_color_ = NULL;
	v_ = 0;
	alpha_v_ = 0;
	czas_ = 0;
	czas_postoju_ = 0;
	moving_forward_ = true;
	stop_ = true;
}

void cLocomotive::aktualizuj(int czas_aktualny) {
	if (!stop_) {
		float delta_t = czas_aktualny - czas_, v_x, v_y;
		if (delta_t > 1000) delta_t = 100;//dla przerwy dluzszej niz 1s nie przeprowadzana jest aktualizacja
		v_x = v_ * cos(alpha_v_ / 180.0*M_PI);
		v_y = v_ * sin(alpha_v_ / 180.0*M_PI);
		x_ = x_ + v_x * delta_t;
		y_ = y_ + v_y * delta_t;
		reach_station();
		czas_ += delta_t;
	}
	else {
		if (czas_aktualny - czas_ > czas_postoju_) {
			stop_ = false;
			present_station_ = NULL;
			czas_postoju_ = 0;
			v_ = 100e-4;
		}
	}
}

void cLocomotive::reach_station() {
	if (this->reach()) {
		stop_ = true;
		v_ = 0;
		x_ = next_station_->x();
		y_ = next_station_->y();
		present_station_ = next_station_;

		bool found = false;

		// dla jadacego w przod 
		if (moving_forward_) { // 
			for (auto el : line_->line_stations()) {
				if (found == true) { // normalnie ( w srodku lini )
					previous_station_ = next_station_;
					next_station_ = el;
				}
				if (next_station_ == el) {
					found = true;
					if (el == line_->line_stations().back() && !line_->loop()) { // gdy jest ostatni przystanek - linia
						moving_forward_ = false;
						auto tmp = previous_station_;
						previous_station_ = next_station_;
						next_station_ = tmp;
					}
					if (el == line_->line_stations().back() && line_->loop()) { // gdy jest ostatni przystanek - petla
						previous_station_ = line_->line_stations().front();
						next_station_ = line_->line_stations().front()++;
					}
				}
			}
		}

		// dla jadacego w ty³ 
		if (!moving_forward_) {
			for (auto itr = line_->line_stations().rbegin(); itr != line_->line_stations().rend(); ++itr) {
				if (found == true) { //normalnie ( w srodku lini )
					previous_station_ = next_station_;
					next_station_ = *itr;
				}
				if (next_station_ == *itr) {
					found = true;
					if (*itr == line_->line_stations().front() && !line_->loop()) { // gdy jest ostatni przystanek - linia
						moving_forward_ = false;
						auto tmp = previous_station_;
						previous_station_ = next_station_;
						next_station_ = tmp;
					}
					if (*itr == line_->line_stations().front() && line_->loop()) { // gdy jest ostatni przystanek - petla
						previous_station_ = line_->line_stations().front();
						next_station_ = line_->line_stations().front()++;
					}
				}
			}
		}
		angle();
		stopped();
	}
}

bool cLocomotive::reach() {
	if (sqrt(pow(next_station_->x() - x_, 2) + pow(next_station_->y() - y_, 2)) <= 0.6) {
		return true;
	}
	return false;
}

void cLocomotive::stopped() {
	int time = 0;
	time += unload();
	time += interchange();
	time += load();

	czas_postoju_ = time*500;
}

void cLocomotive::angle() {
	float angle = atan2(next_station_->y() - previous_station_->y(), next_station_->x() - previous_station_->x());
	if (angle > 0)
		alpha_v_ = angle * 180 / M_PI;
	else
		alpha_v_ = 180 + (180 + angle * 180 / M_PI);
}

int cLocomotive::unload() {
	int tmp_shape = present_station_->shape();
	int points = 0;
	for (auto itr = passengers_.begin(); itr < passengers_.end(); itr++) {
		if (*itr == tmp_shape) {
			passengers_.erase(itr);
			itr--;
			points++;
		}
	}
	points_ = points;
	return points;
}

int cLocomotive::interchange() {
	int acc = 0;
	for (auto itr = passengers_.begin(); itr < passengers_.end(); itr++) {
		if (this->change(*itr) && present_station_->colors().size() >=2) {
			present_station_->add_passenger(*itr);
			passengers_.erase(itr);
			itr--;
			acc++;
		}
	}
	return acc;
}

bool cLocomotive::change(int& p) {
	for (auto el : line_->line_stations()) {
		if (el->shape() == p) {
			return false;
		}
	}
	return true;
}

int cLocomotive::load() {
	int acc = 0;
	for (auto itr = present_station_->passengers().begin(); itr < present_station_->passengers().end(); itr++) {
		if (!present_station_->change(line_->line_stations(), *itr)) {
			if (passengers_.size() < max_capacity_) {
				this->passengers_.push_back(*itr);
				present_station_->passengers().erase(itr);
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
