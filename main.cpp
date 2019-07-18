#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include "cEngine.h"
#include "cScene.h"
cMap scene;
//cEngine silnik;

void resize_binding(int width, int height) {
	scene.resize(width, height);
}

void key_binding(unsigned char key, int x, int y) {
	scene.key(key, x, y);
}
void onMouseButton_binding(int button, int state, int x, int y)
{
	scene.onMouseButton(button, state, x, y);
}
//void idle_binding() {
//	scene.idle();
//}

void timer_binding(int msec) {
	scene.timer();
}

void display_binding() {
	scene.display();
}

//void mouse_binding(int button, int state, int x, int y)
//{
//	scena.mouse(button, state, x, y);
//}

void mouse_move_binding(int x, int y) {
	scene.mouse_move(x, y);
}
void Passive_Mouse_Func_binding(int x, int y)
{
	scene.Passive_Mouse_Func(x, y);
}

int main(int argc, char *argv[])
{
	std::cout << "Hello openGL world!" << std::endl << std::endl;

	std::cout << "PRZYSTANKI" << std::endl;
	std::cout << "x:  y:  shape:  state:  nr: " << std::endl << "passengers: " << std::endl << std::endl;
	for (auto el : scene.silnik_.stations()) {
		std::cout << el->x() << "  " << el->y() << "  " << el->shape() << "   " << el->state() << "   " << el->number() << std::endl;

		for (int i = 0; i < 10; i++)
			el->spawn_passenger(scene.silnik_.poziom_mapy());
		el->show_passengers();
		std::cout << std::endl << std::endl;
	}
	std::cout << "Poziom mapy: " << scene.silnik_.poziom_mapy() << std::endl;
	std::cout << std::endl;

	//ustawianie stacji w lini nr 0;
	//jest zainplementowane rozwiazanie z przekazywaniem wskazników do tych funkcji;
	scene.silnik_.push_back(0, 3);
	scene.silnik_.pop_front(0);
	scene.silnik_.erase(0, 4);
	scene.silnik_.insert(0, 1, 3);
	scene.silnik_.pop_back(0);
	//scene.silnik_.push_front(0, 6); // wtedy jest petla
	
	std::cout << "LINIA" << std::endl;
	std::cout << "nr:  x:  y: " << std::endl;
	for (auto el : scene.silnik_.lines().front()->line_stations()) {
		std::cout << el->number() << "  " << el->x() << "  " << el->y() << std::endl;
	}
	std::cout << "Kolor lini 0: " << scene.silnik_.lines().front()->color() << std::endl;
	std::cout << "Czy linia 0 jest petla? : " << scene.silnik_.lines().front()->loop() << std::endl;
	std::cout << std::endl;

	// ustawienie koleji
	//scene.silnik_.add_loco(0, 0);
	//scene.silnik_.locomotives().front()->drop(*scene.silnik_.lines().front(), *scene.silnik_.stations().front(), *scene.silnik_.stations().back());

	//std::cout << "KOLEJKA" << std::endl;
	//std::cout << "Kolor lini kolejki: " << scene.silnik_.locomotives().front()->line_color() << std::endl;
	//std::cout << "x nastepnej stacji: " << scene.silnik_.locomotives().front()->next_station()->x() << std::endl;
	//std::cout << "y nastepnej stacji: " << scene.silnik_.locomotives().front()->next_station()->y() << std::endl;
	//std::cout << "x poprzedniej stacji: " << scene.silnik_.locomotives().front()->previous_station()->x() << std::endl;
	//std::cout << "y poprzedniej stacji: " << scene.silnik_.locomotives().front()->previous_station()->y() << std::endl;
	//std::cout << "alpha_v: " << scene.silnik_.locomotives().front()->alpha_v() << std::endl;
	//std::cout << "v: " << scene.silnik_.locomotives().front()->v() << std::endl;
	//std::cout << std::endl;


	//std::cout << "Po podniesieniu, przed upuszczeniem" << std::endl;
	//scene.silnik_.locomotives().front()->take(0, 0);
	//std::cout << "Kolor lini kolejki: " << scene.silnik_.locomotives().front()->line_color() << std::endl;
	//std::cout << "x nastepnej stacji: " << scene.silnik_.locomotives().front()->next_station()->x() << std::endl;
	//std::cout << "y nastepnej stacji: " << scene.silnik_.locomotives().front()->next_station()->y() << std::endl;
	//std::cout << "x poprzedniej stacji: " << scene.silnik_.locomotives().front()->previous_station()->x() << std::endl;
	//std::cout << "y poprzedniej stacji: " << scene.silnik_.locomotives().front()->previous_station()->y() << std::endl;
	//std::cout << "alpha_v: " << scene.silnik_.locomotives().front()->alpha_v() << std::endl;
	//std::cout << "v: " << scene.silnik_.locomotives().front()->v() << std::endl;



	
	scene.init(argc, argv, "Mini Metro");
	system("pause");
	return 0;
}