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
//bool cDraw_Line::warunek_usuniecia_linii(double glX, double glY)
//{
//	bool zmienna = false;
//	glPushMatrix();
//	glTranslated(x_p, y_p, 0.0);
//	glRotated(angle_, 0.0, 0.0, 1.0);
//	if (glX >= 0.4 && glX <= length_ - 0.4 && glY >= -0.1 && glY <= 0.1)
//	{
//		zmienna = true;
//	}
//	glPopMatrix();
//	return zmienna;
//}
bool cDraw_Line::warunek_usuniecia_linii(double glX, double glY)
{
	bool zmienna = false;
	if (glX >= x_sr - 0.1*length_ && glX <= x_sr + 0.1*length_ && glY >= y_sr - 0.1*length_ && glY <= y_sr + 0.1*length_)
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
