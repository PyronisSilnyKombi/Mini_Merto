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

void timer_binding(int msec) {
	scene.timer();
}

void display_binding() {
	scene.display();
}

void mouse_move_binding(int x, int y) {
	scene.mouse_move(x, y);
}
void Passive_Mouse_Func_binding(int x, int y)
{
	scene.Passive_Mouse_Func(x, y);
}

int main(int argc, char *argv[])
{


	scene.init(argc, argv, "Mini Metro");
	system("pause");
	return 0;
}