#include "cLine.h"


cLine::cLine(cStation &s, int color, bool loop) : color_(color), loop_(loop) {
	line_stations_.push_back(&s);
}

cLine::cLine(std::list<cStation*> s, int color, bool loop) : color_(color), loop_(loop), line_stations_(s) {

}

void cLine::push_back(cStation& s) {
	line_stations_.push_back(&s);
	Loop();
}

void cLine::push_front(cStation& s) {
	line_stations_.push_front(&s);
	Loop();
}

void cLine::pop_back() {
	line_stations_.pop_back();
	Loop();
}

void cLine::pop_front() {
	line_stations_.pop_front(); 
	Loop();
}

void cLine::insert(const int& miejsce, cStation& s) {
	auto it = line_stations_.begin();
	for (int i = 1; i < miejsce; i++)
		it++;
	line_stations_.insert(it, &s);
	Loop();
}

void cLine::erase(const int& ktora) {
	for (auto el : line_stations_) {
		line_stations_.remove_if([ktora](const auto &el) {
			return ktora == el->number();
		});
	}
	Loop();
}

void cLine::erase(cStation& s) {
	for (auto itr = line_stations_.begin(); itr == line_stations_.end(); itr++) {
		if (&s == *itr)
			line_stations_.erase(itr);
	}
}

void cLine::loco_push_back(cLocomotive& loco) {
	line_loco_.push_back(&loco);
}

void cLine::loco_erase(cLocomotive& loco) {
	for (auto itr = line_loco_.begin(); itr == line_loco_.end(); itr++) {
		if (&loco == *itr) {
			line_loco_.erase(itr);
			itr--;
			break;
		}
	}
}

void cLine::Loop() {
	if ((line_stations_.front() == line_stations_.back()) && line_stations_.size() >= 3) loop_ = true;
	else loop_ = false;
}

