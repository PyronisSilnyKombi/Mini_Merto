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

	//je¿eli wyst¹pi kolizja medzy stacja a kolejka;

	int unload(cStation& a);
	// wyladowoje wszystkich pasazerow ksztaltu stacji oraz przesiadajacych sie na inne linie,
	// zwraca ilosc pasa¿erów którzy wysiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku)
	int load(cStation& a); // pakuje wszystkich pasazerow na stacji oczekujacych na zaladunek,
	// zwraca ilosc pasa¿erów którzy wsiedli(ma to miec wplyw na czas oczekiwania kolejki na przystanku);

	// wysy³anie do nastêpnej stacji
	void send(const cStation& a, const cStation& b);
	// a - stacja aktualna, b stacja nastêpana, nadaje prêdkoœc i kierunek lokomotywie w kierunku nastêpnej stacji;
	// potem czekamy na kolizjê ze stacj¹
	// (chyba ¿e s¹ 3 stacje w jednej linii a ta œrodkowa nie nale¿y do lini to wtedy trzeba zrobiæ warunek który sprawdza czy ta stacja nale¿y do tego koloru)
	void set_poition(const cStation& a); 
	// ustawia pozycjê wagonika na wspó³rzênych stacji, aby wys³aæ go w linii prostej do nastêpnego przystanku i ¿eby trafi³ on napewno na kolizjê z tym obiektem;


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