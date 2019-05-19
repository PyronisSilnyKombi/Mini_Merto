#pragma once
#include <GL/freeglut.h>
#include"cPassengerStore.h"
#include"cStation.h"
#include"cLine.h"

class cLocomotive : public cPassengerStore {
	cStation previous_station_, next_station_;
	char line_color_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue;

	
	
public:
	cLocomotive(double a, double b, double x, double y, double v_x, double v_y, double angle);

	//je�eli wyst�pi kolizja medzy stacja a kolejka;

	int unload(cStation& a);
	// wyladowoje wszystkich pasazerow ksztaltu stacji oraz przesiadajacych sie na inne linie,
	// zwraca ilosc pasa�er�w kt�rzy wysiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku)
	int load(cStation& a); // pakuje wszystkich pasazerow na stacji oczekujacych na zaladunek,
	// zwraca ilosc pasa�er�w kt�rzy wsiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku);

	// wysy�anie do nast�pnej stacji
	void send(const cStation& a, const cStation& b);
	// a - stacja aktualna, b stacja nast�pana, nadaje pr�dko�c i kierunek lokomotywie w kierunku nast�pnej stacji;
	// potem czekamy na kolizj� ze stacj�
	// (chyba �e s� 3 stacje w jednej linii a ta �rodkowa nie nale�y do lini to wtedy trzeba zrobi� warunek kt�ry sprawdza czy ta stacja nale�y do tego koloru)
	void set_poition(const cStation& a); 
	// ustawia pozycj� wagonika na wsp�rz�nych stacji, aby wys�a� go w linii prostej do nast�pnego przystanku i �eby trafi� on napewno na kolizj� z tym obiektem;


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