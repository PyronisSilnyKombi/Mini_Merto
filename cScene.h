#pragma once
#include "cLocomotive.h"
#include "cStation.h"
#include "cPassengerStore.h"
#include "cLine.h"
#include "cEngine.h"
#include "cDraw_Station.h"
#include "cDraw_Locomotive.h"
#include "cDraw_Line.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <chrono>




void resize_binding(int width, int height);
void display_binding();
void key_binding(unsigned char key, int x, int y);
void onMouseButton_binding(int button, int state, int x, int y);
void mouse_move_binding(int x, int y);
void Passive_Mouse_Func_binding(int x, int y);
void timer_binding(int i);


class cMap {
public:
	cEngine silnik_;
protected:
	int time_;
	int licznik_;

	std::list<cDraw_Station*> stations_d;

	bool warunek_klikniecia_;
	bool warunek_wspolrzednych_;
	int tmp_id;
	double x_p_, y_p_; // Pozycja stacji z kt�rej chcemy poprowadzi� lini�. Jest potrzebna do dok�adnego narysowania linii ��cz�cej dwie stacje.

	std::vector<cDraw_Line*> lines_d[7]; 
	double x_pocz�tku_linii_, y_pocz�tku_linii_; // Wsp�rz�dne pierwszej stacji w linii
	double x_ko�ca_linii_, y_ko�ca_linii_;		// Wsp�rz�dne ostatniej stacji w linii
												// S� potrzebne do zachowania porz�dku adres�w, tzn aby dodawane by�y w tych miejscach i w takiej
	std::vector<cLine*> tmp_vector_;			// Wektor z kt�rego przekazywane s� dane do cLine
												// kolejno�ci jak dodawane s� kolejne linie.

	std::list<cStation*> line_stations_[7];		// Lista adres�w stacji w linii przekazywana do silnika.
	bool line_loop_[7];
										
	bool was_clicked;
	int used_color_;
	cDraw_Line* adres_linii;
	std::vector<cDraw_Locomotive*> locomotives_d;
	double mouse_x, mouse_y; // Aktualne polozenie myszki
	bool locomotive_active_; // Jesli true, w miejscu kursora jest lokomotywa kt�r� mo�na po�o�y� na jednej z linii aby mog�a zacz�� si� porusza�.

public:
	cMap();
	~cMap();


	void resize(int width, int height);
	void timer();
//	void idle();
	void display();
	void init(int argc, char **argv, const char* window_name);
	void set_callbacks();
	void key(unsigned char key, int x, int y);
	//void mouse(int button, int state, int x, int y);
	void mouse_move(int x, int y);
	void Passive_Mouse_Func(int x, int y);
	void onMouseButton(int button, int state, int x, int y);
	void set_used_color_(int c);

	//Refaktoryzacja

	//Timer
	void aktualizacja_stacji();
	void aktualizacja_linii();
	void aktualizacja_kolei();
	void przekazanie_kolejek_do_cEngine();

	void spawnowanie_pasa�er�w();
	void spawnowanie_stacji();

	void udostepnianie_kolorow();
	void udostepnianie_kolejek();

	void warunek_konca_gry();

	//Mouse function

	//void linia_przycisk_aktywny(int button, int state, double openglX, double openglY, bool warunek, int ilo��_po��cze�, bool czy_nale�y_do_linii_, cDraw_Station * el);
	//void linia_przycisk_nieaktywny(int button, int state, double openglX, double openglY, bool & linia_dodana);
	void tworzenie_nowych_linii(int button, int state, double x, double y, bool & linia_dodana);
	void usuwanie_linii(bool linia_dodana, int button, int state, int x, int y);

	void wyznaczanie_adresow();
	void czy_jest_petla();
	
	void dodawanie_kolei(int x, int y);
};