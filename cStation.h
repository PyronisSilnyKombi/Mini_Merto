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
	


	// nie wiem czy nie bêdzie wygodniej jak bêdzie to zwyk³a funkcja, zwracaj¹ca obiekt klasy cRectangle albo cCircle który jest klas¹ potomn¹ cStation;
	int spawn(const std::vector<cStation> &stations, const float &r, const float &x, const float &y, const int& poziom_mapy);
	// spawns a station on the map (w okreslonej {nie mniejszej od wartosci r} odleg³oœci od innych stacji z wektora stations, w obrembie mapy o szerokosci x i wysokoœci y)
	// ustawia wspó³rzêdne x i y stacji ;
	// poziom mapy okresla na jakie figury moze pojawic sie szansa wylosowania, jezeli poziom mapy to 0 - na mapie aktualnie sa tylko ko³a, to mo¿e wylosowaæ ko³o albo trójk¹t,
	// je¿eli zostanie wylosowane ko³o to funkcja zwraca 0 i poziom zostaje 0, je¿eli trójk¹t to zwraca 1 i poziom na mapie zmienia siê na 1,
	// a w nastêpnej turze losowania mo¿e wypaœæ kszta³t poziomu wy¿szego - kwadrat. ten mechanizm s³uzy nie spownowaniu siê pasa¿erów krórzy nie maj¹ jeszcze swoich stacji
	// losuje kszta³t stacji na podstawie czsu gry (na pocz¹tku pojawiaj¹ sie tylko kó³ka, trójk¹ty i kwadraty,
	// po pewnym czasie jest szansa na wylosowanie innych bardziej skomplikowanych figur);



	void spawn_passenger(const int& poziom);
	// spawns a psssneger, losuje jego kszta³t i dodaje go wektora pasa¿erów stacji, (poziom okreœla jakie figury moga sie pojawic,
	// 0 - tylko ko³a, 1 - ko³a i trójkaty, 2 - ko³a trójkaty i kwadraty itd)
	void erase_passengers(); // usuwa za³adowanych do pociagu pasa¿erów ze stacji 

	bool overcrowd(); // zwraca prawdê je¿eli przystanek jest przeludniony;


	//czêœæ Kacpra
	void draw();
	void update();
	bool isClicked(double openglX, double openglY);
	bool isUnclicked(double openglX, double openglY);
};
