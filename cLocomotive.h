#pragma once
#include <GL/freeglut.h>
#include"cPassengerStore.h"
#include"cStation.h"
#include"cLine.h"

class cLocomotive : public cPassengerStore {
	cStation *previous_station_, *next_station_;
	int line_color_; //0 - red, 1 - blue, 2 - yellow, 3 - green, 4 - orange, 5 - purple, 6 - light blue;
	cLine *line_;
	
	bool change(int& p);
public:
	cLocomotive(cLine &line, double x = 0, double y = 0, int capacity = 6);

	//***************************************
	void drop(cLine& l, cStation& s1, cStation& s2); // jedzie w kierunku stacji s2
	// dodaje kolejke z wektora kolejek dostepnych w scenie na okreslonym odcinku lini jadaca w kierunku blizszej stacjii nadaje jej predkosc
	void send(const cStation& a, const cStation& b); // s = v * t
	// wysy³anie do nastêpnej stacji
	void set_poition(const cStation& a);
	// ustawia pozycjê wagonika na wspó³rzênych stacji;
	//***************************************


	int unload(cStation& s);
	// wyladowoje wszystkich pasazerow ksztaltu stacji oraz przesiadajacych sie na inne linie,
	// zwraca ilosc pasa¿erów którzy wysiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku oraz naliczon¹ punktacjê)
	void interchange(cStation& s); // przesiadka
	

	int load(cStation& s); // pakuje wszystkich pasazerow na stacji oczekujacych na zaladunek,
	// zwraca ilosc pasa¿erów którzy wsiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku);
	void add_passenger(const int& i);
	
	

	//getery
	int line_color() { return line_color_; }
	cStation previous_station() { return *previous_station_; }
	cStation next_station() { return *next_station_; }

	//setery
};