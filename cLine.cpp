#include "cLine.h"

cLine::cLine(cStation &s, char color, bool loop) : color_(color), loop_(loop) {
	line_stations_.push_back(&s);
}

void cLine::erase_station(cStation& s) {
	for (auto el : line_stations_) {
		line_stations_.remove_if([&s](const auto &el) {
			return &s == el;
		});
	}
}

void cLine::add_station(cStation& s) {
	line_stations_.push_back(&s);
}

bool cLine::Loop() {
	if (line_stations_.front() == line_stations_.back()) return true;
	else return false;
}

