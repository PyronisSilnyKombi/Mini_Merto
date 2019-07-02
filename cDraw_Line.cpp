#include "cDraw_Line.h"

cDraw_Line::cDraw_Line(double xp, double yp, double xk, double yk, double angle) : x_p(xp), y_p(yp), x_k(xk), y_k(yk), angle_(angle)
{

}
void cDraw_Line::draw_line()
{
	glPushMatrix();
	glTranslated(x_p, y_p, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(angle_, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

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

	// Sprawdzanie warunku, do warto�ci x_p, x_k dodane/odjete zostanie 0.4 po to, aby warunek usuwania linii nie uruchamia� si� po klikni�ciu na
	// fragment linii pokrywaj�cy si� ze stacj�.
	if (glX >= x_p - 0.1 && glX <= x_k + 0.1 && glY >= a * glX + b2 -0.1 && glY <= a * glX + b1 + 0.1)
	{
		zmienna = true;
	}
	if (glX >= x_k - 0.1 && glX <= x_p + 0.1 && glY <= a * glX + b2 + 0.1 && glY >= a * glX + b1 - 0.1)
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