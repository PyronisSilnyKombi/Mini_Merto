#pragma once
#include <GL/freeglut.h>
#include <cmath>
#include <time.h>
#include <ctime>
#include <vector>
#include <list>
#include <iostream>
#include"cPassengerStore.h"
//#include "cLocomotive.h"

class cLocomotive;

class cStation : public cPassengerStore {
	int shape_; // 1 - circle, 2 - triangle, 3 - square, 4 - rhombus, 5 - pentagon, 6 - star, 7 - cross;
	int state_; // 0 - save, 1 - dangerous(the number of passengers is close to the maximum value of the capacity), 2 - overcrovded;
	std::vector<char> colors_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue; kolory lini do kr�rych nale�y ta stacja
	std::vector<cLocomotive*> lokomotywy; // wszka�niki do wszystkich lokomotyw nale��cych do lini przechodz�cych przez t� stacj�
	
public:
	cStation(int shape = 1, double x = 0, double y = 0, int capacity = 20, int state = 0);
	

	cStation spawn(std::list<cStation*> &stations, const float &r, const float &x, const float &y, const int &poziom_mapy, int& tmp_lvl);
	// spawns a station on the map (w okreslonej {nie mniejszej od wartosci r} odleg�o�ci od innych stacji z wektora stations, w obrembie mapy o szerokosci x i wysoko�ci y)
	// ustawia wsp�rz�dne x i y stacji ;
	// poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko ko�a, to mo�e wylosowa� ko�o albo tr�jk�t,
	// je�eli zostanie wylosowane ko�o to funkcja zwraca 0 i poziom zostaje 0, je�eli tr�jk�t to zwraca 1 i poziom na mapie zmienia si� na 1,
	// a w nast�pnej turze losowania mo�e wypa�� kszta�t poziomu wy�szego - kwadrat. ten mechanizm s�uzy nie spownowaniu si� pasa�er�w kr�rzy nie maj� jeszcze swoich stacji
	// losuje kszta�t stacji na podstawie czsu gry (na pocz�tku pojawiaj� sie tylko k�ka, tr�jk�ty i kwadraty,
	// po pewnym czasie jest szansa na wylosowanie innych bardziej skomplikowanych figur);
	// zwraca -1 gdy nie ma miejsca na mapie



	void spawn_passenger(const int& poziom);
	// spawns a psssneger, losuje jego kszta�t i dodaje go wektora pasa�er�w stacji, (poziom okre�la jakie figury moga sie pojawic,
	// 0 - tylko ko�a, 1 - ko�a i tr�jkaty, 2 - ko�a tr�jkaty i kwadraty itd)
	// nie spownujemy pasa�era ko�o na przystanku ko�o to bez sensu

	void erase_passengers(cLocomotive& loco); // usuwa za�adowanych do pociagu pasa�er�w ze stacji 


	int overcrowd(); //bada stan i zwraca stan_


	//getery
	int shape() { return shape_; }
	int state() { return state_; }


	void show_passengers() {
		for (auto el : passengers_){
			std::cout << el << ", ";
		}
	}

};
