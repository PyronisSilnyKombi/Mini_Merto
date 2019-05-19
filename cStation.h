#pragma once
#include <GL/freeglut.h>
#include <cmath>
#include<vector>
#include"cPassengerStore.h"



class cStation : public cPassengerStore {
	unsigned char shape_; // c - circle, t - triangle, s - square, r - rhombus, p - pentagon, s - star, m - cross;
	unsigned int state_; // 0 - save, 1 - dangerous(the number of passengers is close to the maximum value of the capacity), 2 - overcrovded;
	std::vector<unsigned char> colors_; //r - red, b - blue, y - yellow, g - green, o - orange, p - purple, l - light blue;
	
public:
	cStation(char shape = 'c', int state = 0, double x = 0, double y = 0);
	


	// nie wiem czy nie b�dzie wygodniej jak b�dzie to zwyk�a funkcja, zwracaj�ca obiekt klasy cRectangle albo cCircle kt�ry jest klas� potomn� cStation;
	int spawn(const std::vector<cStation> &stations, const float &r, const float &x, const float &y, const int& poziom_mapy);
	// spawns a station on the map (w okreslonej {nie mniejszej od wartosci r} odleg�o�ci od innych stacji z wektora stations, w obrembie mapy o szerokosci x i wysoko�ci y)
	// ustawia wsp�rz�dne x i y stacji ;
	// poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko ko�a, to mo�e wylosowa� ko�o albo tr�jk�t,
	// je�eli zostanie wylosowane ko�o to funkcja zwraca 0 i poziom zostaje 0, je�eli tr�jk�t to zwraca 1 i poziom na mapie zmienia si� na 1,
	// a w nast�pnej turze losowania mo�e wypa�� kszta�t poziomu wy�szego - kwadrat. ten mechanizm s�uzy nie spownowaniu si� pasa�er�w kr�rzy nie maj� jeszcze swoich stacji
	// losuje kszta�t stacji na podstawie czsu gry (na pocz�tku pojawiaj� sie tylko k�ka, tr�jk�ty i kwadraty,
	// po pewnym czasie jest szansa na wylosowanie innych bardziej skomplikowanych figur);



	void spawn_passenger(const int& poziom);
	// spawns a psssneger, losuje jego kszta�t i dodaje go wektora pasa�er�w stacji, (poziom okre�la jakie figury moga sie pojawic,
	// 0 - tylko ko�a, 1 - ko�a i tr�jkaty, 2 - ko�a tr�jkaty i kwadraty itd)
	void erase_passengers(); // usuwa za�adowanych do pociagu pasa�er�w ze stacji 

	bool overcrowd(); // zwraca prawd� je�eli przystanek jest przeludniony;


	//cz�� Kacpra
	void draw();
	void update();
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
};
