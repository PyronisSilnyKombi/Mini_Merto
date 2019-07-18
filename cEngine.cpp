#include "cEngine.h"
#include <iostream>
#include <chrono>

cEngine::cEngine(int ilosc_wolnych_lokomotyw, int ilosc_wolnych_linii) : ilosc_wolnych_lokomotyw_(ilosc_wolnych_lokomotyw), ilosc_wolnych_linii_(ilosc_wolnych_linii){
	poziom_mapy_ = 1;
	ilosc_przewiezionych_pasazerow_ = 0;
	int tmp_lvl;
	ilosc_stacji_ = 0;
	srand(time(NULL));

	//dodanie stacji
	for (int i = 0; i < 6; i++) {
		cStation *s = new cStation(stations_, 2, 18, 18, poziom_mapy_, tmp_lvl, ilosc_stacji_);
		stations_.push_back(s);
		poziom_mapy_ = tmp_lvl;
	}

	//dodanie pasa¿erów
	for (auto el : stations_) {
		for (int i = 0; i < 10; i++)
		el->spawn_passenger(poziom_mapy_);
	}

	//dodanie lini
	this->add_line(*stations_.front());
	for (auto el : stations_) {
		if( el->number() != 1)
		lines_.front()->push_back(*el);
	}

}

// DODAWANIE I USUWANIE OBIEKTOW

void cEngine::add_station(const float &r, const float &x, const float &y) {
	srand(time(NULL));
	int tmp_lvl;
	cStation *s = new cStation(stations_, r, x, y, poziom_mapy_, tmp_lvl, ilosc_stacji_);
	stations_.push_back(s);
	poziom_mapy_ = tmp_lvl;
}

void cEngine::add_line(cStation &s) {
	cLine *l = new cLine(s, lines_.size());
	lines_.push_back(l);
	ilosc_wolnych_linii_--;
}

void cEngine::erase_line(const int& ktora) {
	lines_.erase(lines_.begin() + ktora);
	this->ustaw_kolory();
	ilosc_wolnych_linii_++;
}

void cEngine::erase_line(cLine& l) {
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
		lines_.erase(itr);
	}
	this->ustaw_kolory();
	ilosc_wolnych_linii_++;
}


void cEngine::add_loco(const float& x, const float& y) {
	cLocomotive* loco = new cLocomotive(x, y);
	locomotives_.push_back(loco);
	ilosc_wolnych_lokomotyw_--;
}

void cEngine::erase_loco(const int& ktora_l, cLocomotive& loco) {
	for (auto el : lines_) {
		if (el->color() == ktora_l)
			lines_[ktora_l]->loco_erase(loco);
	}

	for (auto itr = locomotives_.begin(); itr == locomotives_.end(); itr++) {
		if (&loco == *itr) {
			locomotives_.erase(itr);
			itr--;
			break;
		}
	}
	ilosc_wolnych_lokomotyw_++;
}

void cEngine::erase_loco(cLine& l, cLocomotive& loco) {
	l.loco_erase(loco);
	for (auto itr = locomotives_.begin(); itr == locomotives_.end(); itr++) {
		if (&loco == *itr) {
			locomotives_.erase(itr);
			itr--;
			break;
		}
	}
	ilosc_wolnych_lokomotyw_++;
}

// LINIE

void cEngine::push_back(const int& ktora_l, const int& ktora_s) {
	for (auto el : stations_) {
		if (el->number() == ktora_s)
			lines_[ktora_l]->push_back(*el);
	}
}

void cEngine::push_back(cLine& l, cStation& s) {
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
			l.push_back(s);
	}
}
void cEngine::push_back(cLocomotive* loco)
{
	locomotives_.push_back(loco);
}
void cEngine::push_back_line(cLine* line)
{
	lines_.push_back(line);
}

void cEngine::push_front(const int& ktora_l, const int& ktora_s) {
	for (auto el : stations_) {
		if (el->number() == ktora_s)
			lines_[ktora_l]->push_front(*el);
	}
}

void cEngine::push_front(cLine& l, cStation& s) {
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
			l.push_back(s);
	}
}

void cEngine::pop_back(const int& ktora_l) {
	lines_[ktora_l]->pop_back();
}

void cEngine::pop_back(cLine & l){
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
			l.pop_back();
	}
}

void cEngine::pop_front(const int& ktora_l) {
	lines_[ktora_l]->pop_front();
}

void cEngine::pop_front(cLine & l) {
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
			l.pop_front();
	}
}

void cEngine::insert(const int& ktora_l, const int& ktora_s, const int& miejsce) {
	for (auto el : stations_) {
		if (el->number() == ktora_s)
			lines_[ktora_l]->insert(miejsce, *el);
	}
}

void cEngine::insert(cLine & l, cStation & s, const int & miejsce) {
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
			l.insert(miejsce, s);
	}
}

void cEngine::erase(const int& ktora_l, const int& ktora_s) {
	lines_[ktora_l]->erase(ktora_s);
}

void cEngine::erase(cLine & l, cStation & s) {
	for (auto itr = lines_.begin(); itr == lines_.end(); itr++) {
		if (&l == *itr)
			l.erase(s);
	}
}

void cEngine::ustaw_kolory() {
	int acc = 0;
	for (auto el : lines_) {
		el->set_color(acc);
		acc++;
	}
}

// LOKOMOTYWY

void cEngine::aktualizuj_lokomotywy(const int& time) {
	for (auto el : locomotives_) {
		el->aktualizuj(time);
		if (el->points() != 0) {
			this->points_ += el->points();
			el->set_points(0);
		}
	}
	
}

void cEngine::drop(cLine& l, cStation &s1, cStation &s2, cLocomotive& loco) {
	if (&s1 == &s2) return;
	//l.loco_push_back(loco);  Wykomentowalem ten fragment bo w loco.drop kolejka jest push backowana ponownie, przez co przy dodaniu jednej
	//						   kolejki, w wektorze znajduja sie dwie.
	loco.drop(l, s1, s2);
}

void cEngine::take(const int& x, const int& y, cLocomotive& loco) {
	loco.take();
	loco.set_x(x);
	loco.set_y(y);
}

// DESTRUKTOR

cEngine::~cEngine() {

}