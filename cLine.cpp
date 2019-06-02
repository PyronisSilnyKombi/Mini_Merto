#include "cLine.h"

cLine::cLine(cStation &s, int color, bool loop) : color_(color), loop_(loop) {
	line_stations_.push_back(&s);
}

void cLine::erase_station(cStation& s) {
	for (auto el : line_stations_) {
		line_stations_.remove_if([&s](const auto &el) {
			return &s == el;
		});
	}
}

bool cLine::Loop() {
	if ((line_stations_.front() == line_stations_.back()) && line_stations_.size() >= 3) return true;
	else return false;
}

