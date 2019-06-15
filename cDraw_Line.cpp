#include "cDraw_Line.h"

cDraw_Line::cDraw_Line(double xp, double yp, double xk, double yk) : x_p(xp), y_p(yp), x_k(xk), y_k(yk)
{

}
void cDraw_Line::draw_line()
{
	glPushMatrix();
	glTranslated(0.0, 0.0, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(x_p - 0.1, y_p + 0.1, 0);
		glVertex3d(x_p + 0.1, y_p - 0.1, 0);
		glVertex3d(x_k - -0.1, y_k  + 0.1, 0);
		glVertex3d(x_k + 0.1, y_k - 0.1, 0);
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