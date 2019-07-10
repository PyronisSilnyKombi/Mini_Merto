#include "cDraw_Line.h"

cDraw_Line::cDraw_Line(double xp, double yp, double xk, double yk, double angle, int color) : x_p(xp), y_p(yp), x_k(xk), y_k(yk), angle_(angle), color_(color)
{

}
void cDraw_Line::draw_line()
{
	glPushMatrix();
	glTranslated(x_p, y_p, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(angle_, 0.0, 0.0, 1.0);
	double colors[3];
	if (color_ == 0) { colors[0] = 1.0; colors[1] = 0.0; colors[2] = 0.0; }
	if (color_ == 1) { colors[0] = 0.0; colors[1] = 0.0; colors[2] = 1.0; }
	if (color_ == 2) { colors[0] = 1.0; colors[1] = 1.0; colors[2] = 0.0; }
	if (color_ == 3) { colors[0] = 0.0; colors[1] = 1.0; colors[2] = 0.0; }
	if (color_ == 4) { colors[0] = 1.0; colors[1] = 0.65; colors[2] = 0.0; }
	if (color_ == 5) { colors[0] = 0.72; colors[1] = 0.0; colors[2] = 1.0; }
	if (color_ == 6) { colors[0] = 0.0; colors[1] = 1.0; colors[2] = 1.0; }
	glColor3d(colors[0], colors[1], colors[2]);

	glBegin(GL_POLYGON);
	{
			glVertex3d(0.0, 0.1, 0);
			glVertex3d(0.0, -0.1, 0);
			glVertex3d(length_, - 0.1, 0);
			glVertex3d(length_,0.1, 0);
			
			glTranslated(0.0, 0.0, 0.0);
	}
	glEnd();
	glPopMatrix();
}
double cDraw_Line::get_x_p()
{
	return x_p;
}
double cDraw_Line::get_y_p()
{
	return y_p;
}
double cDraw_Line::get_x_k()
{
	return x_k;
}
double cDraw_Line::get_y_k()
{
	return y_k;
}
void cDraw_Line::set_x_y_p(double x, double y)
{
	x_p = x;
	y_p = y;
}
void cDraw_Line::set_x_y_k(double x, double y)
{
	x_k = x;
	y_k = y;
}
void cDraw_Line::set_angle_(double angle)
{
	angle_ = angle;
}
void cDraw_Line::set_length_(double length)
{
	length_ = length;
}
bool cDraw_Line::warunek_usuniecia_linii(double glX, double glY)
{
	bool zmienna = false;
	// Wyznaczanie r�wna� liniowych b�d�cych warto�ciami granicznymi dla wsp�rz�dnej y
	double a, k�t, b1, b2, x_�rednie, y_�rednie; // x i y �rednie pos�u�� do wyznaczenia b. b jest jedynym elementem kt�ry r�ni si� w obu r�wnaniach,
												 // dlatego oddzielnie wyznaczane s� tylko b1 i b2.
	k�t = this->get_angle_();
	a = tan((k�t*M_PI)/180);
	x_�rednie = this->get_x_sr_();
	y_�rednie = this->get_y_sr_();
	double y1_�rednie, y2_�rednie, d; // d to odleglosc miedzy wartosciami y1 i y2. Aby otrzymac wartosci y1 i y2 kt�re s� potrzebne do wyliczenia b,
									  // do y_�redniego trzeba kolejno dla y1 doda� d/2 i dla y2 odj�� d/2.
	d = 0.2 / (sin(M_PI / 2 - k�t * (M_PI / 180)));
	y1_�rednie = y_�rednie + d / 2;
	y2_�rednie = y_�rednie - d / 2;

	b1 = y1_�rednie - a * x_�rednie;
	b2 = y2_�rednie - a * x_�rednie;
	// r�wnania granic to: y = a*x + b1 i y = a*x + b2

	// Sprawdzanie warunku, do warto�ci x_p, x_k dodane/odjete zostanie 0.1 po to, aby warunek usuwania linii uruchamia� si� �atwiej, tj. nie by�o
	// problemu z klikni�ciem w cienki fragment linii pokrywaj�cy si� ze stacj�.
	if (glX >= x_p && glX <= x_k && glY >= a * glX + b2 && glY <= a * glX + b1)
	{
		zmienna = true;
	}
	if (glX >= x_k && glX <= x_p && glY <= a * glX + b2 && glY >= a * glX + b1)
	{
		zmienna = true;
	}
	return zmienna;
}
void cDraw_Line::set_x_y_sr(double x, double y)
{
	x_sr = x;
	y_sr = y;
}
double cDraw_Line::get_angle_()
{
	return angle_;
}
double cDraw_Line::get_x_sr_()
{
	return x_sr;
}
double cDraw_Line::get_y_sr_()
{
	return y_sr;
}
//void cDraw_Line::set_beginning_and_destination(cStation* b, cStation* d, int color) 
//{
//	beginning_[0] = b;
//	destination_[0] = d; // W wersji ko�cowej zamiast 0 b�dzie wyst�powa� 'color'
//}
//cStation* cDraw_Line::get_beginning_(int color)
//{
//	return beginning_[0]; // Podobnie jak wy�ej
//}
//cStation* cDraw_Line::get_destination_(int color)
//{
//	return destination_[0];
//}
//void cDraw_Line::set_beginning(cStation* b, int color)
//{
//	beginning_[0] = b;
//}
//void cDraw_Line::set_destination(cStation* d, int color)
//{
//	destination_[0] = d;
//}
int cDraw_Line::get_color_()
{
	return color_;
}
bool cDraw_Line::warunek_dodania_kolejki(double glX, double glY)
{
	bool zmienna = false;
	// Wyznaczanie r�wna� liniowych b�d�cych warto�ciami granicznymi dla wsp�rz�dnej y
	double a, k�t, b1, b2, x_�rednie, y_�rednie; // x i y �rednie pos�u�� do wyznaczenia b. b jest jedynym elementem kt�ry r�ni si� w obu r�wnaniach,
												 // dlatego oddzielnie wyznaczane s� tylko b1 i b2.
	k�t = this->get_angle_();
	a = tan((k�t*M_PI) / 180);
	x_�rednie = this->get_x_sr_();
	y_�rednie = this->get_y_sr_();
	double y1_�rednie, y2_�rednie, d; // d to odleglosc miedzy wartosciami y1 i y2. Aby otrzymac wartosci y1 i y2 kt�re s� potrzebne do wyliczenia b,
									  // do y_�redniego trzeba kolejno dla y1 doda� d/2 i dla y2 odj�� d/2.
	d = 0.2 / (sin(M_PI / 2 - k�t * (M_PI / 180)));
	y1_�rednie = y_�rednie + d / 2;
	y2_�rednie = y_�rednie - d / 2;

	b1 = y1_�rednie - a * x_�rednie;
	b2 = y2_�rednie - a * x_�rednie;
	// r�wnania granic to: y = a*x + b1 i y = a*x + b2

	// Sprawdzanie warunku, do warto�ci x_p, x_k dodane/odjete zostanie 0.1 po to, aby warunek usuwania linii uruchamia� si� �atwiej, tj. nie by�o
	// problemu z klikni�ciem w cienki fragment linii pokrywaj�cy si� ze stacj�.
	if (glX >= x_p && glX <= x_k && glY >= a * glX + b2 && glY <= a * glX + b1)
	{
		zmienna = true;
	}
	if (glX >= x_k && glX <= x_p && glY <= a * glX + b2 && glY >= a * glX + b1)
	{
		zmienna = true;
	}
	return zmienna;
}