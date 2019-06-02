#include "cScene.h"
#include <iostream>
#include <chrono>

cMap::cMap()
{
	//cEngine silnik;
	//silnik_ = silnik;

	std::list<cStation*> stacje_tmp = silnik_.stations();
	for (auto&el : stacje_tmp)
	{
		double x = el->x();
		double y = el->y();
		stations_d.push_back(new cDraw_Station(x, y));
	}
}

void cMap::resize(int width, int height) {
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	//gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glOrtho(-10, 10, -10, 10, -1, 1);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//void cMap::timer() {
//
	////int current_time = getTickCount();
	////auto current_time = std::chrono::high_resolution_clock::now();

	///*std::cout<<current_time<<std::endl;*/
	////std::cout.flush();
	//if ((*(figures.begin() + 1))->kolizja(*pilka_)) {
	//	glutDestroyWindow(1);
	//}
	//for (auto itr = figures.begin() + 1; itr != figures.end(); ++itr) {
	//	if (pilka_->kolizja(*(*itr))) {
	//		if ((*itr)->kolizja(*pilka_)) {
	//			std::cout << "kolizja" << std::endl;
	//			(*itr)->kolizja(*pilka_);
	//			(*itr)->kolizja(*pilka_);
	//			(*itr)->kolizja(*pilka_);
	//			cBlok *klocek;
	//			klocek = dynamic_cast<cBlok*>(*itr);
	//			if (klocek != 0) {
	//				points_--;
	//				if (points_ == 0) glutDestroyWindow(1);
	//				figures.erase(itr);
	//				break;
	//			}
	//		}
	//	}

	//}
	//pilka_->aktualizuj(GetTickCount());
	//paletka_->aktualizuj(GetTickCount());


	//glutPostRedisplay();
	//glutTimerFunc(40, timer_binding, 0);
//}

void cMap::idle() {
	//std::list<cStation*> stacje_tmp = silnik_.stations();
	//if (stacje_tmp.size() != stations_d.size())
	//{
	//	stations_d.erase(stations_d.begin(), stations_d.end());
	//	for (auto&el : stacje_tmp)
	//	{
	//		double x = el->x();
	//		double y = el->y();
	//		stations_d.push_back(new cDraw_Station(x, y));
	//	}
	//	for (auto&el : stations_d)
	//	{
	//		el->draw_station();
	//	}
	//}

	glutPostRedisplay();
}

void cMap::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		std::list<cStation*> stacje_tmp = silnik_.stations();
		if (stacje_tmp.size() != stations_d.size())
		{
			stations_d.erase(stations_d.begin(), stations_d.end());
			for (auto&el : stacje_tmp)
			{
				double x = el->x();
				double y = el->y();
				stations_d.push_back(new cDraw_Station(x, y));
			}
		}
		for (auto&el : stations_d)
		{
			el->draw_station();
		}

	}
	glPopMatrix();
	glutSwapBuffers();
}

void cMap::set_callbacks() {
	glutDisplayFunc(display_binding);
	glutReshapeFunc(resize_binding);
	//glutMotionFunc(mouse_move_binding);
	glutKeyboardFunc(key_binding);
	//glutTimerFunc(40, timer_binding, 0);
	glutIdleFunc(idle_binding);
	//glutMouseFunc(mouse_binding);
	glutPassiveMotionFunc(mouse_move_binding);
}

void cMap::init(int argc, char **argv, const char *window_name) {

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	set_callbacks();

	glutMainLoop();
}

void cMap::key(unsigned char key, int x, int y) {
	/*switch (key) {
	case 'w':
		figures[active_id_]->move(0, 0.1);
		break;
	case 's':
		figures[active_id_]->move(0, -0.1);
		break;
	case 'a':
		figures[active_id_]->move(-0.1, 0.0);
		break;
	case 'd':
		figures[active_id_]->move(0.1, 0.0);
		break;
	case '+':
		if (figures.size() - 1 > active_id_) active_id_++;
		break;
	case '-':
		if (0 < active_id_) active_id_--;
		break;
	case 'o': {
		cPassengerStore *o = new cStation(0.5, 0, 0, 0, 0);
		figures.push_back(o);
		break;
	}
	case 'p': {
		cPassengerStore *k = new cLocomotive(2, 1, 0, 0, 0, 0, 0);
		figures.push_back(k);
		break;
	}
	case 'l': {
		glPushMatrix();
		figures[active_id_]->rotate_clockwise();
		glPopMatrix();
		break;
	}
	case 'm' :{
		figures[active_id_]->speed_up_x(0.001);
		break;
	}
	case 'n': {
		figures[active_id_]->speed_up_y(0.001);
		break;
	}
	case 'b': {
		figures[active_id_]->slow_down_x(0.001);
		break;
	}
	case 'v': {
		figures[active_id_]->slow_down_y(0.001);
		break;
	}
	case 'c': {
		auto p1 = dynamic_cast<cLocomotive*>(figures[active_id_]);
		if (p1) p1->extend(1);
		auto p2 = dynamic_cast<cStation*>(figures[active_id_]);
		if (p2) p2->extend(1);
		break;
	}
	case 'x': {
		auto p1 = dynamic_cast<cLocomotive*>(figures[active_id_]);
		if (p1) p1->reduce(1);
		auto p2 = dynamic_cast<cStation*>(figures[active_id_]);
		if (p2) p2->reduce(1);
		break;
	}
	}*/
}

cMap::~cMap() {
	/*for (auto &el : figures)
		delete el;*/
}

void cMap::mouse_move(int x, int y) {

	double openglX = ((double)x - 400) / 800 * 20;
	double openglY = (-(double)y + 300) / 600 * 20;
	/*paletka_->follow(openglX, openglY);*/
}
