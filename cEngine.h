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

	int poziom_mapy_; // poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko ko³a, to mo¿e wylosowaæ ko³o albo trójk¹t,
	// je¿eli zostanie wylosowane ko³o to funkcja zwraca 0 i poziom zostaje 0, je¿eli trójk¹t to zwraca 1 i poziom na mapie zmienia siê na 1,
	// a w nastêpnej turze losowania mo¿e wypaœæ kszta³t poziomu wy¿szego - kwadrat. ten mechanizm s³uzy nie spownowaniu siê pasa¿erów krórzy nie maj¹ jeszcze swoich stacji
	// losuje kszta³t stacji na podstawie czsu gry (na pocz¹tku pojawiaj¹ sie tylko kó³ka, trójk¹ty i kwadraty,
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