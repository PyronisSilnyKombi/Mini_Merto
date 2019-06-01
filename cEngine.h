#pragma once
#include "cLocomotive.h"
#include "cStation.h"
#include "cPassengerStore.h"
#include "cLine.h"
#include <vector>
#include <list>

void resize_binding(int width, int height);
void idle_binding();
void display_binding();
void key_binding(unsigned char key, int x, int y);
//void mouse_binding(int button, int state, int x, int y);
void mouse_move_binding(int x, int y);
void timer_binding(int i);

class cEngine {
	std::list<cStation*> stations_;
	std::vector<cLine*> lines_;
	std::vector<cLocomotive*> locomotives_;
	//std::vector<cPassengerStore*> figures;

	int ilosc_przewiezionych_pasazerow_;
	int ilosc_wolnych_lokomotyw_;
	int ilosc_wolnych_linii_;

	int poziom_mapy_; // poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko ko�a, to mo�e wylosowa� ko�o albo tr�jk�t,
	// je�eli zostanie wylosowane ko�o to funkcja zwraca 0 i poziom zostaje 0, je�eli tr�jk�t to zwraca 1 i poziom na mapie zmienia si� na 1,
	// a w nast�pnej turze losowania mo�e wypa�� kszta�t poziomu wy�szego - kwadrat. ten mechanizm s�uzy nie spownowaniu si� pasa�er�w kr�rzy nie maj� jeszcze swoich stacji
	// losuje kszta�t stacji na podstawie czsu gry (na pocz�tku pojawiaj� sie tylko k�ka, tr�jk�ty i kwadraty,
	// po pewnym czasie jest szansa na wylosowanie innych bardziej skomplikowanych figur);

	
	
public:
	cEngine();
	~cEngine();
	
	void wybierz_bonus(); // wyswietlane po uplywie tyg do wyboru dodatkowa linia lub lokomotywa

	void add_station(const float &r, const float &x, const float &y);
	

	//getery
	int poziom_mapy() { return poziom_mapy_; }
	int ilosc_przewiezionych_pasazerow() { return ilosc_przewiezionych_pasazerow_; }
	int ilosc_wolnych_lokomotyw() { return ilosc_wolnych_lokomotyw_; }
	int ilosc_wolnych_linii() { return ilosc_wolnych_linii_; }
	std::list<cStation*> stations() { return stations_; }
	std::vector<cLine*> lines() { return lines_; }
	std::vector<cLocomotive*> locomotives() { return locomotives_; }


	//przyjaciele
	friend cStation;
};