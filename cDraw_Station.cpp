#include "cDraw_Station.h"

cDraw_Station::cDraw_Station(double x, double y) : x_(x), y_(y){

}
//cDraw_Station::cDraw_Station() {
//
//}

void cDraw_Station::draw_station() 
{
glPushMatrix();
	glTranslated(x_/2, y_/2, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);


	double angle, vectorX, vectorY, vectorX1, vectorY1;
	glBegin(GL_TRIANGLES);
	vectorX1 = x_ / 2;
	vectorY1 = y_ / 2;
	int seg = 360;
	for (int i = 0; i <= seg; i++)
	{
		angle = (M_PI / (180.0))*((float)i);
		vectorX = x_ / 2 + (0.3*sin(angle));
		vectorY = y_ / 2 + (0.3*cos(angle));
		glVertex2f(x_ / 2, y_ / 2);
		glVertex2f(vectorX1, vectorY1);
		glVertex2f(vectorX, vectorY);
		vectorY1 = vectorY;
		vectorX1 = vectorX;
	}
	glEnd();
glPopMatrix();
}
void cDraw_Station::set_x_y(double x, double y)
{
	x_ = x;
	y_ = y;
}