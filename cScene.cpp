#include "cScene.h"
#include <iostream>
#include <chrono>

cMap::cMap()
{
	tmp_id = -1;
	warunek_wspolrzednych_ = false;
	was_clicked = false;
	used_color_ = 0;
	locomotive_active_ = false;

	//cEngine silnik;
	//silnik_ = silnik;

	//std::list<cStation*> stacje_tmp = silnik_.stations();
	//for (auto&el : stacje_tmp)
	//{
	//	double x = el->x();
	//	double y = el->y();
	//	std::vector <int> p = el->passengers();
	//	stations_d.push_back(new cDraw_Station(x, y, p));
	//}
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

void cMap::timer() {

	std::list<cStation*> stacje_tmp = silnik_.stations();
	if (stacje_tmp.size() != stations_d.size())
	{
		stations_d.erase(stations_d.begin(), stations_d.end());
		for (auto&el : stacje_tmp)
		{
			double x = el->x();
			double y = el->y();
			int shape = el->shape();
			std::vector <int> p = el->passengers();
			stations_d.push_back(new cDraw_Station(x, y, p, shape));
		}
	}


	int iloœæ_linii = 0;
	for (int i = 0; i < 7; i++)
	{
		if (line_stations_[i].size() != 0)
		{
			iloœæ_linii++;
		}	
	}

	for (int i = 0; i < silnik_.lines().size(); i++)
	{
		silnik_.erase_line(i);
	}
	
	for (int i = 0; i < iloœæ_linii; i++)
	{
		silnik_.push_back_line(new cLine(line_stations_[i], i, line_loop_[i]));

		// Wykomentowany kod jest do sprawdzenia czy dane s¹ poprawnie przekazane, ale trzeba wtedy upubliczniæ dane z poszczególnych klas.

		//for (auto & el : silnik_.lines_[i]->line_stations_)
		//{
		//	double x = el->x();
		//	double y = el->y();
		//	std::cout << x << "    " << y << std::endl;
		//}

	}


	glutPostRedisplay();
	glutTimerFunc(40, timer_binding, 0);
}

//void cMap::idle() {
//
//	std::list<cStation*> stacje_tmp = silnik_.stations();
//	if (stacje_tmp.size() != stations_d.size())
//	{
//		stations_d.erase(stations_d.begin(), stations_d.end());
//		for (auto&el : stacje_tmp)
//		{
//			double x = el->x();
//			double y = el->y();
//			std::vector <int> p = el->passengers();
//			stations_d.push_back(new cDraw_Station(x, y, p));
//		}
//	}
//
//	glutPostRedisplay();
//}

void cMap::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	{
		for (auto&el : stations_d)
		{
			el->draw_station();
		}
		for (int i = 0; i < 7; i++)
		{
			for (auto&el : lines_d[i])
			{
				el->draw_line();
			}
		}
		for (auto&el : locomotives_d)
		{
			el->draw_locomotive();
		}
	}
	glPopMatrix();
	glutSwapBuffers();
}

void cMap::set_callbacks() {
	glutDisplayFunc(display_binding);
	glutReshapeFunc(resize_binding);
	glutKeyboardFunc(key_binding);
	glutTimerFunc(40, timer_binding, 0);
	//glutIdleFunc(idle_binding);
	//glutMouseFunc(mouse_binding);
	glutPassiveMotionFunc(Passive_Mouse_Func_binding);
	glutMouseFunc(onMouseButton_binding);
	glutMotionFunc(mouse_move_binding);
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
	switch (key) {
	/*case 'w':
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
	}*/
	case '1':
	{
		this->set_used_color_(0);
	}break;
	case '2':
	{
		this->set_used_color_(1);
	}break;
	case '3':
	{
		this->set_used_color_(2);
	}break;
	case '4':
	{
		this->set_used_color_(3);
	}break;
	case '5':
	{
		this->set_used_color_(4);
	}break;
	case '6':
	{
		this->set_used_color_(5);
	}break;
	case '7':
	{
		this->set_used_color_(6);
	}break;
	case 'l':
	{
		locomotive_active_ = true;
		locomotives_d.push_back(new cDraw_Locomotive(0, 0, 0));
		locomotives_d.back()->set_color_(-1);

	}break;
	}
}
void cMap::set_used_color_(int c)
{
	used_color_ = c;
}

cMap::~cMap() {
	/*for (auto &el : figures)
		delete el;*/
}

void cMap::mouse_move(int x, int y) 
{
	if (locomotive_active_ == false)
	{
		int itr = 0;

		for (auto &elem : stations_d)
		{
			double openglX = ((double)x - 400) / 800 * 20;
			double openglY = ((-1)*(double)y + 300) / 600 * 20;
			bool warunek = elem->warunek_klikniecia(openglX, openglY);
			int iloœæ_po³¹czeñ = elem->get_iloœæ_po³¹czeñ_dla_stacji_(used_color_);
			bool czy_nale¿y_do_linii_ = elem->get_czy_nalezy_do_linii_(used_color_);
			if (warunek_wspolrzednych_ == false && iloœæ_po³¹czeñ < 2 && (line_stations_[used_color_].size() == 0 || czy_nale¿y_do_linii_ == true))
			{
				if (warunek == true)
				{
					double tmpy = elem->get_y();
					double tmpx = elem->get_x();
					x_p_ = tmpx;
					y_p_ = tmpy;
					double kat = atan2(openglY - tmpy, openglX - tmpx);
					double tmpkat;
					if (kat > 0)
						tmpkat = kat * 180 / M_PI;
					else
						tmpkat = 180 + (180 + kat * 180 / M_PI);
					double dlugosc = sqrt(pow(openglX - tmpx, 2) + pow(openglY - tmpy, 2));
					lines_d[used_color_].back()->set_angle_(tmpkat);
					lines_d[used_color_].back()->set_length_(dlugosc);
					tmp_id = itr;
					warunek_wspolrzednych_ = true;
				}
			}
			else
			{
				if (itr == tmp_id && iloœæ_po³¹czeñ < 2 && (line_stations_[used_color_].size() == 0 || czy_nale¿y_do_linii_ == true))
				{
					double tmpy = elem->get_y();
					double tmpx = elem->get_x();
					double kat = atan2(openglY - tmpy, openglX - tmpx);
					double tmpkat;
					if (kat > 0)
						tmpkat = kat * 180 / M_PI;
					else
						tmpkat = 180 + (180 + kat * 180 / M_PI);
					double dlugosc = sqrt(pow(openglX - tmpx, 2) + pow(openglY - tmpy, 2));
					lines_d[used_color_].back()->set_angle_(tmpkat);
					lines_d[used_color_].back()->set_length_(dlugosc);
				}
			}
			itr++;
		}
	}

}
void cMap::Passive_Mouse_Func(int x, int y)
{
	if (locomotive_active_ == true)
	{
		double openglX = ((double)x - 400) / 800 * 20;
		double openglY = ((-1)*(double)y + 300) / 600 * 20;
		locomotives_d.back()->set_x_y_(openglX, openglY);

		// Wystepuje bug przy dodaniu drugiego elementu
	}
}
void cMap::onMouseButton(int button, int state, int x, int y)
{
	if (locomotive_active_ == false)
	{
		bool linia_dodana = false;
		// Rysowanie nowych linii
		for (auto&el : stations_d)
		{
			double openglX = ((double)x - 400) / 800 * 20;
			double openglY = ((-1)*(double)y + 300) / 600 * 20;
			bool warunek = el->warunek_klikniecia(openglX, openglY);
			int iloœæ_po³¹czeñ = el->get_iloœæ_po³¹czeñ_dla_stacji_(used_color_);
			bool czy_nale¿y_do_linii_ = el->get_czy_nalezy_do_linii_(used_color_);
			if (iloœæ_po³¹czeñ < 2 && (line_stations_[used_color_].size() == 0 || czy_nale¿y_do_linii_ == true))
			{
				if (warunek == true)
				{
					if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
					{
						warunek_klikniecia_ = true;
						double tmpx = el->get_x();
						double tmpy = el->get_y();
						lines_d[used_color_].push_back(new cDraw_Line(tmpx, tmpy, openglX, openglY, 0, used_color_));
						was_clicked = true;
					}
				}

			}
			if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
			{
				double x_k;
				double y_k;
				bool czy_nalezy = false;
				for (auto&el2 : stations_d)
				{
					czy_nalezy = el2->warunek_klikniecia(openglX, openglY);
					if (czy_nalezy == true)
					{
						x_k = el2->get_x();
						y_k = el2->get_y();

						lines_d[used_color_].back()->set_x_y_k(x_k, y_k);
						double kat = atan2(y_k - y_p_, x_k - x_p_);
						double tmpkat;
						if (kat > 0)
							tmpkat = kat * 180 / M_PI;
						else
							tmpkat = 180 + (180 + kat * 180 / M_PI);
						double dlugosc = sqrt(pow(x_k - x_p_, 2) + pow(y_k - y_p_, 2));
						lines_d[used_color_].back()->set_angle_(tmpkat);
						lines_d[used_color_].back()->set_length_(dlugosc);
						for (auto&el3 : stations_d)
						{
							double tmpx = el3->get_x();
							double tmpy = el3->get_y();
							if (tmpx == x_p_ && tmpy == y_p_)
							{
								el3->zwiêksz_iloœæ_po³¹czeñ_dla_stacji_(used_color_);
								int iloœæ_po³¹czeñ = el3->get_iloœæ_po³¹czeñ_dla_stacji_(used_color_);
								std::cout << iloœæ_po³¹czeñ << std::endl;
								el3->set_czy_nalezy_do_linii_(true, used_color_);
							}
						}
						el2->zwiêksz_iloœæ_po³¹czeñ_dla_stacji_(used_color_);
						el2->set_czy_nalezy_do_linii_(true, used_color_);
						linia_dodana = true;

						break; break;
					}
				}
				if (czy_nalezy == false && lines_d[used_color_].size() != 0 && was_clicked == true)
				{
					lines_d[used_color_].erase(lines_d[used_color_].end() - 1);
					break; break; break;
				}
				warunek_klikniecia_ = false;
				warunek_wspolrzednych_ = false;
				was_clicked = false;
				std::cout << lines_d[used_color_].size() << std::endl;
				break; break;

			}
		}

		// Usuwanie dzialajacych linii

		if (linia_dodana == false)
		{
			for (int i = 0; i < 7; i++)
			{
				int iter = 0;
				for (auto&el3 : lines_d[i])
				{
					if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && was_clicked == false)
					{
						double openglX = ((double)x - 400) / 800 * 20;
						double openglY = ((-1)*(double)y + 300) / 600 * 20;

						// Wyznazanie œrodka linii

						double tmp_x_p = el3->get_x_p();
						double tmp_y_p = el3->get_y_p();
						double tmp_x_k = el3->get_x_k();
						double tmp_y_k = el3->get_y_k();
						int color = el3->get_color_();

						double x_sr = (tmp_x_p + tmp_x_k) / 2;
						double y_sr = (tmp_y_p + tmp_y_k) / 2;

						el3->set_x_y_sr(x_sr, y_sr);
						bool czy_usunac = el3->warunek_usuniecia_linii(openglX, openglY);
						if (czy_usunac == true)
						{
							lines_d[i].erase(lines_d[i].begin() + iter);
							for (auto&el : stations_d)
							{
								double tmpx = el->get_x();
								double tmpy = el->get_y();
								if (tmpx == tmp_x_p && tmpy == tmp_y_p)
								{
									el->zmniejsz_iloœæ_po³¹czeñ_dla_stacji_(color);
									int iloœæ_po³¹czeñ = el->get_iloœæ_po³¹czeñ_dla_stacji_(color);
									if (iloœæ_po³¹czeñ == 0)
									{
										el->set_czy_nalezy_do_linii_(false, color);
										//Usuwanie adresów z listy
										std::list<cStation*>::iterator it1 = line_stations_[i].begin();
										for (auto &itr : line_stations_[i])
										{
											double x_itr = itr->x();
											double y_itr = itr->y();
											if (x_itr == tmpx && y_itr == tmpy)
											{
												line_stations_[i].erase(it1);
												if (lines_d[i].size() != 0)
												{
													x_koñca_linii_ = line_stations_[i].back()->x();
													y_koñca_linii_ = line_stations_[i].back()->y();

													x_pocz¹tku_linii_ = line_stations_[i].front()->x();
													y_pocz¹tku_linii_ = line_stations_[i].front()->y();
												}
												break; break;
											}
											else
											{
												it1++;
											}
										}
									}
								}
								if (tmpx == tmp_x_k && tmpy == tmp_y_k)
								{
									el->zmniejsz_iloœæ_po³¹czeñ_dla_stacji_(color);
									int iloœæ_po³¹czeñ = el->get_iloœæ_po³¹czeñ_dla_stacji_(color);
									if (iloœæ_po³¹czeñ == 0)
									{
										el->set_czy_nalezy_do_linii_(false, color);
										//Usuwanie adresów z listy
										std::list<cStation*>::iterator it1 = line_stations_[i].begin();
										for (auto &itr : line_stations_[i])
										{
											double x_itr = itr->x();
											double y_itr = itr->y();
											if (x_itr == tmpx && y_itr == tmpy)
											{
												line_stations_[i].erase(it1);
												if (lines_d[i].size() != 0)
												{
													x_koñca_linii_ = line_stations_[i].back()->x();
													y_koñca_linii_ = line_stations_[i].back()->y();

													x_pocz¹tku_linii_ = line_stations_[i].front()->x();
													y_pocz¹tku_linii_ = line_stations_[i].front()->y();
												}
												break; break;
											}
											else
											{
												it1++;
											}
										}
									}
								}
							}
							iter--;
						}
						iter++;
					}
				}
			}
		}
		//	 Wyznaczanie adresow stacji poczatkowej i koncowej linii danego koloru

		if (linia_dodana == true)
		{
			for (int i = 0; i < 7; i++)
			{
				for (auto&el1 : lines_d[i])
				{
					double tmp_x_p = el1->get_x_p();
					double tmp_y_p = el1->get_y_p();
					double tmp_x_k = el1->get_x_k();
					double tmp_y_k = el1->get_y_k();

					if (line_stations_[i].size() == 0)
					{
						for (auto&el : stations_d)
						{
							double tmp_x, tmp_y;
							tmp_x = el->get_x();
							tmp_y = el->get_y();
							int shape;
							shape = el->get_shape_();
							std::vector<int> pasa¿erowie = el->get_passengers_();
							if (tmp_x == tmp_x_p && tmp_y == tmp_y_p)
							{
								cStation* tmp_station = new cStation;
								tmp_station->set_passengers(pasa¿erowie);
								tmp_station->set_x(tmp_x);
								tmp_station->set_y(tmp_y);
								tmp_station->set_shape_(shape);
								line_stations_[i].push_front(tmp_station);
								x_pocz¹tku_linii_ = tmp_x_p;
								y_pocz¹tku_linii_ = tmp_y_p;
							}
							if (tmp_x == tmp_x_k && tmp_y == tmp_y_k)
							{
								cStation* tmp_station = new cStation;
								tmp_station->set_passengers(pasa¿erowie);
								tmp_station->set_x(tmp_x);
								tmp_station->set_y(tmp_y);
								tmp_station->set_shape_(shape);
								line_stations_[i].push_back(tmp_station);
								x_koñca_linii_ = tmp_x_k;
								y_koñca_linii_ = tmp_y_k;
							}
						}
					}
					else
					{
						if (i == used_color_ && el1 == lines_d[i].back())
						{
							for (auto& ele : stations_d)
							{
								double x_stacji = ele->get_x();
								double y_stacji = ele->get_y();
								double x_pocz¹tkowe_nowej_linii = lines_d[i].back()->get_x_k();
								double y_pocz¹tkowe_nowej_linii = lines_d[i].back()->get_y_k();
								if (x_stacji == x_pocz¹tkowe_nowej_linii && y_stacji == y_pocz¹tkowe_nowej_linii)
								{
									double tmp_x, tmp_y;
									tmp_x = ele->get_x();
									tmp_y = ele->get_y();
									int shape;
									shape = ele->get_shape_();
									std::vector<int> pasa¿erowie = ele->get_passengers_();

									cStation* tmp_station = new cStation;
									tmp_station->set_passengers(pasa¿erowie);
									tmp_station->set_x(tmp_x);
									tmp_station->set_y(tmp_y);
									tmp_station->set_shape_(shape);

									bool powtarzanie = false;
									for (auto& elem : line_stations_[i])
									{
										double x_czy_sie_powtarza = elem->x();
										double y_czy_sie_powtarza = elem->y();
										if (tmp_x == x_czy_sie_powtarza && tmp_y == y_czy_sie_powtarza)
										{
											powtarzanie = true;
										}
									}
									if (powtarzanie == false)
									{
										if (x_koñca_linii_ == tmp_x_p && y_koñca_linii_ == tmp_y_p)
										{
											line_stations_[i].push_back(tmp_station);
											x_koñca_linii_ = tmp_x_k;
											y_koñca_linii_ = tmp_y_k;
										}
										else if (x_pocz¹tku_linii_ == tmp_x_p && y_pocz¹tku_linii_ == tmp_y_p)
										{
											line_stations_[i].push_front(tmp_station);
											x_pocz¹tku_linii_ = tmp_x_k;
											y_pocz¹tku_linii_ = tmp_y_k;
										}
									}
								}
							}
						}
					}
				}

				//	cStation* tmp;
				//	for (auto&ele : line_stations_[i])
				//	{
				//		//tmp = ele->get_destination_(i);
				//	//	line_stations_[i].push_back(tmp);		//zmienic w pewnych przypadkach na push_front lub insert aby nie bylo bugow
				//		std::cout << ele->x() << " " << ele->y() << std::endl;


				//	//	std::cout << tmp->x() << "    " << tmp->y() << std::endl;
				//		//if (ele == lines_d[i].back())
				//		//{
				//		//	tmp = ele->get_destination_(i);
				//		//	line_stations_[i].push_back(tmp);
				//		//	std::cout << tmp->x() << "    " << tmp->y() << std::endl; // Jeœli istnieje pêtla, pierwszy i ostatni adres s¹ takie same
				//		//}
				//	}
				//	//std::cout << std::endl;
				//}
				//std::cout << std::endl << x_pocz¹tku_linii_ << "   " << y_pocz¹tku_linii_ << std::endl;
				//std::cout << x_koñca_linii_ << "   " << y_koñca_linii_ << std::endl<<std::endl;

			}

			// Wyznaczenie czy linia jest zapêtlona

			for (int i = 0; i < 7; i++)
			{
				line_loop_[i] = true;
				for (auto &itr : stations_d)
				{
					int ilosc = itr->get_iloœæ_po³¹czeñ_dla_stacji_(i);
					if (ilosc != 2)
					{
						line_loop_[i] = false;
					}
				}
			}

		}
	}
	else
	{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		double openglX = ((double)x - 400) / 800 * 20;
		double openglY = ((-1)*(double)y + 300) / 600 * 20;
		for (int i = 0; i < 7; i++)
		{
			for (auto &el : lines_d[i])
			{
				double tmp_x_p = el->get_x_p();
				double tmp_y_p = el->get_y_p();
				double tmp_x_k = el->get_x_k();
				double tmp_y_k = el->get_y_k();
				int color = el->get_color_();

				double x_sr = (tmp_x_p + tmp_x_k) / 2;
				double y_sr = (tmp_y_p + tmp_y_k) / 2;

				el->set_x_y_sr(x_sr, y_sr);


				double x_locomotive = locomotives_d.back()->get_x_();
				double y_locomotive = locomotives_d.back()->get_y_();
				bool war = el->warunek_dodania_kolejki(openglX, openglY);
				if (war == true)
				{
					int clr = el->get_color_();
					locomotives_d.back()->set_color_(clr);
					double angl = el->get_angle_();
					locomotives_d.back()->set_angle_(angl);
					locomotive_active_ = false;
				}
			}
		}
		if (locomotive_active_ == true)
		{
			locomotives_d.pop_back();
			locomotive_active_ = false;
		}
	}
	}
}