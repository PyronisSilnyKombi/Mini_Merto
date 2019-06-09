#pragma once
#define _USE_MATH_DEFINES
#include <GL/freeglut.h>
#include <cmath>
#include"cPassengerStore.h"
#include"cStation.h"
#include"cLine.h"

class cLocomotive : public cPassengerStore {
	cStation *previous_station_, *next_station_, *present_station_;
	int line_color_; //0 - red, 1 - blue, 2 - yellow, 3 - green, 4 - orange, 5 - purple, 6 - light blue;
	cLine *line_;

	int czas_; // czas ostatniej aktualizacji
	int czas_postoju_; // w mili sekundach

	float v_;
	float alpha_v_;
	bool moving_forward_;
	bool stop_;

	int points_; // przyznawane s� za przewizionych pasa�er�w

	void set_loco_drop(cStation& s1, cStation& s2);
	void set_moving_forward();
	void angle();
	bool reach();
	void reach_station();

	//***********************************************
	bool change(int& p); // gdy krzy�uja si� dwie linie kt�re nie przechodz� przez stacj� kszta�tu danego pasa�era w�wczas zostaje on do�ywotnio na tej stacji
	//***********************************************
	
	int unload();
	// wyladowoje wszystkich pasazerow ksztaltu stacji oraz przesiadajacych sie na inne linie,
	// zwraca ilosc pasa�er�w kt�rzy wysiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku oraz naliczon� punktacj�)
	int interchange(); // przesiadka
	int load(); // pakuje wszystkich pasazerow na stacji oczekujacych na zaladunek,
	// zwraca ilosc pasa�er�w kt�rzy wsiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku);
	void add_passenger(const int& i);
	void stopped(); // liczy jak d�ugo b�dzie trwa� post�j i zajmuje si� za�adunkiem i roz�adunkiem
public:
	cLocomotive(double x = 0, double y = 0, int capacity = 6);
	void aktualizuj(int czas_aktualny); // powoduje ruch albo czeka przez okre�lony czas na stacji;
	
	//getery
	int line_color() { return line_color_; }
	cStation* previous_station() { if ( previous_station_ != NULL ) return previous_station_; }
	cStation* present_station() { if (present_station_ != NULL) return present_station_; }
	cStation* next_station() { if (next_station_ != NULL) return next_station_; }
	cLine* line() { if (line_ != NULL) return line_; }
	float v() { return v_; }
	float alpha_v() { return alpha_v_; }
	bool stop() { return stop_; }
	bool moving_forvard() { return moving_forward_; }
	int points() { return points_; }

	//setery
	void drop(cLine& l, cStation& s1, cStation& s2); // jedzie w kierunku bli�szej stacji
	// dodaje kolejke z wektora kolejek dostepnych w silniku na okreslonym odcinku lini jadaca w kierunku blizszej stacjii nadaje jej predkosc
	void take();
	void take(const int& x, const int& y);
	void set_points(const int& x) { points_ = x; }
};