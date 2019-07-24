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

	int ilosc_stacji_;
	int ilosc_przewiezionych_pasazerow_;
	int ilosc_wolnych_lokomotyw_;
	int ilosc_wolnych_linii_;
	int ilosc_kolorow_;

	int points_;
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
	void add_station(const float &r, const float &x, const float &y); // losuje stację na obszarze o wysokości i szerokości x, y w odległosci nie mniejszej od innych stacji niż dane r 

	void add_line(cStation &s); // dodaje linie zaczynajaca się w podanej stacji
	void erase_line(const int& ktora); // ktora z kolei 0,1,2,3 odpowiada kolorom 0 - red, 1 - blue, 2 - yellow, 3 - green, 4 - orange, 5 - purple, 6 - light blue;
	void erase_line(cLine& l); // usuwa linię i ustala prawidlowe kolory pozostałych
	void erase_all_locomotives();
	void set_ilosc_wolnych_lokomotyw_(int k);

	// zaspół funkcji odpowiedzialnych za utawienie listy przystanków w poszczególnych liniach
	// linie numerujemy od 0 (nr lini inaczej kolor), a stacje od 1;
	// funkcje te są przystosowane również dla przekazywania argumentow w postaci obiektów;
	void push_back(const int& ktora_l, const int& ktora_s);
	void push_back(cLocomotive* loco);
	void push_back(cLine& l, cStation& s);
	void push_back_passenger(int p, int licznik);
	void push_back_line(cLine* line);
	void push_front(const int& ktora_l, const int& ktora_s);
	void push_front(cLine& l, cStation& s);
	void pop_back(const int& ktora_l);
	void pop_back(cLine& l);
	void pop_front(const int& ktora_l);
	void pop_front(cLine& l);
	void insert(const int& ktora_l, const int& ktora_s, const int& miejsce); // zmienna miejsce mówi po ktorym z kolei el ma być wstawiona stacja 
	void insert(cLine& l, cStation& s, const int& miejsce);
	void erase(const int& ktora_l, const int& ktora_s);
	void erase(cLine& l, cStation& s);

	// linie numerujemy od 0 (nr lini inaczej kolor), a stacje od 1
	void add_loco(const float& x, const float& y); // dodaje lokomotywę nie pryzpisaną do niczego (szarą),
	// x i y to powinny byc współrzędne myszki przy podnoszeniu szaej kolejki z paska menu, dopiero po upuszczeniu funkcja "drop()" wagonik jest przypisywany do lini i ma kolor
	void erase_loco(const int& ktora_l, cLocomotive& loco ); // usuwa lokomotywę gdy upuścimy ją na ziemią zamiast na linię
	void erase_loco(cLine& l, cLocomotive& loco ); // -,,- tylko z obiektami
	void aktualizuj_lokomotywy(const int& time); //funkcja aktualizująca wszystkie lokomotywy (nie ważne czy stoja na przystanku czy jadą)
	void drop(cLine& l, cStation &s1, cStation &s2, cLocomotive& loco); // upuszcza lokomotywę na linie i nadaje jej kolor i prekość
	void take(const int& x, const int& y, cLocomotive& loco); //zabiera lokomoytywę z lini (robi się wtedy szara, kolor wskazuje na NULL), można ją upuscić na ziemię i wtedy powinna byc wywolana funkcja erase_loco(),
	// lub moze zostac odłożona na inną linię, x i y to współrzędne myszki;


	//getery
	int poziom_mapy() { return poziom_mapy_; }
	int ilosc_przewiezionych_pasazerow() { return ilosc_przewiezionych_pasazerow_; }
	int ilosc_wolnych_lokomotyw() { return ilosc_wolnych_lokomotyw_; }
	int ilosc_wolnych_linii() { return ilosc_wolnych_linii_; }
	std::list<cStation*> stations() { return stations_; }
	std::vector<cLine*> lines() { return lines_; }
	std::vector<cLocomotive*> locomotives() { return locomotives_; }
	int get_ilosc_kolorow() { return ilosc_kolorow_; }
	
	void set_ilosc_kolorow(int kolory);


	//przyjaciele
	friend cStation;
};
