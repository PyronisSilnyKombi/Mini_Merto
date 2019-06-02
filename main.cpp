#include <iostream>

#define NDEBUG
#include <GL/freeglut.h>
#include "cEngine.h"
#include "cScene.h"
cMap scene;
cEngine silnik;

void resize_binding(int width, int height) {
	scene.resize(width, height);
}

void key_binding(unsigned char key, int x, int y) {
	scene.key(key, x, y);
}

void idle_binding() {
	scene.idle();
}

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

int main(int argc, char *argv[])
{
	std::cout << "Hello openGL world!" << std::endl;

	std::cout << "x:  y:  shape:  state: " << std::endl << "passengers: " << std::endl << std::endl;
	for (auto el : silnik.stations()) {
		std::cout << el->x() << "  " << el->y() << "  " << el->shape() << "   " << el->state() << std::endl;
		for (int i = 0; i < 10; i++)
			el->spawn_passenger(silnik.poziom_mapy());
		el->show_passengers();
		std::cout << std::endl << std::endl;
	}
	std::cout << "Poziom mapy: " << silnik.poziom_mapy() << std::endl;
	
	scene.init(argc, argv, "Mini Metro");
	system("pause");
	return 0;
}