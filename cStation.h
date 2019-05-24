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
	std::vector<char> colors_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue; kolory lini do krórych nale¿y ta stacja
	std::vector<cLocomotive*> lokomotywy; // wszka¿niki do wszystkich lokomotyw nale¿¹cych do lini przechodz¹cych przez t¹ stacjê
	
public:
	cStation(int shape = 1, double x = 0, double y = 0, int capacity = 20, int state = 0);
	

	cStation spawn(std::list<cStation*> &stations, const float &r, const float &x, const float &y, const int &poziom_mapy, int& tmp_lvl);
	// spawns a station on the map (w okreslonej {nie mniejszej od wartosci r} odleg³oœci od innych stacji z wektora stations, w obrembie mapy o szerokosci x i wysokoœci y)
	// ustawia wspó³rzêdne x i y stacji ;
	// poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko ko³a, to mo¿e wylosowaæ ko³o albo trójk¹t,
	// je¿eli zostanie wylosowane ko³o to funkcja zwraca 0 i poziom zostaje 0, je¿eli trójk¹t to zwraca 1 i poziom na mapie zmienia siê na 1,
	// a w nastêpnej turze losowania mo¿e wypaœæ kszta³t poziomu wy¿szego - kwadrat. ten mechanizm s³uzy nie spownowaniu siê pasa¿erów krórzy nie maj¹ jeszcze swoich stacji
	// losuje kszta³t stacji na podstawie czsu gry (na pocz¹tku pojawiaj¹ sie tylko kó³ka, trójk¹ty i kwadraty,
	// po pewnym czasie jest szansa na wylosowanie innych bardziej skomplikowanych figur);
	// zwraca -1 gdy nie ma miejsca na mapie



	void spawn_passenger(const int& poziom);
	// spawns a psssneger, losuje jego kszta³t i dodaje go wektora pasa¿erów stacji, (poziom okreœla jakie figury moga sie pojawic,
	// 0 - tylko ko³a, 1 - ko³a i trójkaty, 2 - ko³a trójkaty i kwadraty itd)
	// nie spownujemy pasa¿era ko³o na przystanku ko³o to bez sensu

	void erase_passengers(cLocomotive& loco); // usuwa za³adowanych do pociagu pasa¿erów ze stacji 


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
