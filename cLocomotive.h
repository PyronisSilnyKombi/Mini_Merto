#pragma once
#include <GL/freeglut.h>
#include"cPassengerStore.h"
#include"cStation.h"
#include"cLine.h"

class cLocomotive : public cPassengerStore {
	cStation previous_station_, next_station_;
	char line_color_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue;

	
	
public:
	cLocomotive(double x = 0, double y = 0, char line_color = 'r', int capacity = 6);

	int unload(cStation a);
	// wyladowoje wszystkich pasazerow ksztaltu stacji oraz przesiadajacych sie na inne linie,
	// zwraca ilosc pasa�er�w kt�rzy wysiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku)
	int load(cStation& a); // pakuje wszystkich pasazerow na stacji oczekujacych na zaladunek,
	// zwraca ilosc pasa�er�w kt�rzy wsiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku);

	// wysy�anie do nast�pnej stacji
	void send(const cStation& a, const cStation& b); // s = v * t
	
	void set_poition(const cStation& a); 
	// ustawia pozycj� wagonika na wsp�rz�nych stacji;

	//getery
	char line_color(); // zwraca kolor
	cStation previous_station() { return previous_station_; }
	cStation next_station() { return next_station_; }


	void upusc_na_linie(const cLine& line); // dodaje kolejke z wektora kolejek dostepnych w scenie na okreslonym odcinku lini jadaca w kierunku blizszej stacjii nadaje jej predkosc


	// czesc Kacpra
	void draw();
	void update();
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
};