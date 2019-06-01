#pragma once
#include "cLocomotive.h"
#include "cStation.h"
#include "cPassengerStore.h"
#include "cLine.h"
#include <vector>
#include <list>

class cEngine {
	std::list<cStation*> stations_;
	std::vector<cLine*> lines_;
	std::vector<cLocomotive*> locomotives_;

	int ilosc_przewiezionych_pasazerow_;
	int ilosc_wolnych_lokomotyw_;
	int ilosc_wolnych_linii_;

	int poziom_mapy_; // poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko koła, to może wylosować koło albo trójkąt,
	// jeżeli zostanie wylosowane koło to funkcja zwraca 0 i poziom zostaje 0, jeżeli trójkąt to zwraca 1 i poziom na mapie zmienia się na 1,
	// a w następnej turze losowania może wypaść kształt poziomu wyższego - kwadrat. ten mechanizm słuzy nie spownowaniu się pasażerów krórzy nie mają jeszcze swoich stacji
	// losuje kształt stacji na podstawie czsu gry (na początku pojawiają sie tylko kółka, trójkąty i kwadraty,
	// po pewnym czasie jest szansa na wylosowanie innych bardziej skomplikowanych figur);

	void ustaw_kolory();
	
	
public:
	cEngine(int ilosc_wolnych_lokomotyw = 3, int ilosc_wolnych_linii = 3);
	~cEngine();
	
	void wybierz_bonus(); // wyswietlane po uplywie tyg do wyboru dodatkowa linia lub lokomotywa
	void add_station(const float &r, const float &x, const float &y);

	void add_line(cStation &s);
	void erase_line(int& ktory);// ktory z kolei 0,1,2,3 odpowiada kolorom 0 - red, 1 - blue, 2 - yellow, 3 - green, 4 - orange, 5 - purple, 6 - light blue;

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
