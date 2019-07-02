#include "cDraw_Station.h"

cDraw_Station::cDraw_Station(double x, double y, std::vector <int> passengers, int shape) : x_(x), y_(y), passengers_(passengers), shape_(shape)
{
	for (int i = 0; i < 7; i++)
		czy_nalezy_do_linii.push_back(false);
}


//void cDraw_Station::draw_station() 
//{
//glPushMatrix();
//	glTranslated(x_/2, y_/2, 0.0);
//	glRotated(0, 1.0, 0.0, 0.0);
//	glRotated(0, 0.0, 1.0, 0.0);
//	glRotated(0, 0.0, 0.0, 1.0);
//
//	glColor3d(1.0, 0.0, 0.0);
//
//
//	double angle, vectorX, vectorY, vectorX1, vectorY1;
//	glBegin(GL_TRIANGLES);
//	vectorX1 = x_ / 2;
//	vectorY1 = y_ / 2;
//	int seg = 360;
//	for (int i = 0; i <= seg; i++)
//	{
//		angle = (M_PI / (180.0))*((float)i);
//		vectorX = x_ / 2 + (0.3*sin(angle));
//		vectorY = y_ / 2 + (0.3*cos(angle));
//		glVertex2f(x_ / 2, y_ / 2);
//		glVertex2f(vectorX1, vectorY1);
//		glVertex2f(vectorX, vectorY);
//		vectorY1 = vectorY;
//		vectorX1 = vectorX;
//	}
//	glEnd();
//	glPopMatrix();
//	glPushMatrix();
//	glTranslated(x_, y_, 0.0);
//
//		this->draw_passengers();
//
//	glPopMatrix();
//}
void cDraw_Station::draw_station()
{
	switch (shape_)
	{
	case 1:
	{
		glPushMatrix();
		glTranslated(x_ / 2, y_ / 2, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);


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
		{
			glPushMatrix();

			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);


			double angle, vectorX, vectorY, vectorX1, vectorY1;
			glBegin(GL_TRIANGLES);
			vectorX1 = x_ / 2;
			vectorY1 = y_ / 2;
			int seg = 360;
			for (int i = 0; i <= seg; i++)
			{
				angle = (M_PI / (180.0))*((float)i);
				vectorX = x_ / 2 + (0.4*sin(angle));
				vectorY = y_ / 2 + (0.4*cos(angle));
				glVertex2f(x_ / 2, y_ / 2);
				glVertex2f(vectorX1, vectorY1);
				glVertex2f(vectorX, vectorY);
				vectorY1 = vectorY;
				vectorX1 = vectorX;
			}
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}break;
	case 2:
	{
		glPushMatrix();
		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-0.35, -0.35 / 3, 0);
			glVertex3d(0.35, -0.35 / 3, 0);
			glVertex3d(0, 1.05 / 3, 0);

		}
		glEnd();
		{
			glPushMatrix();
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.5, -0.5 / 3, 0);
				glVertex3d(0.5, -0.5 / 3, 0);
				glVertex3d(0, 1.5 / 3, 0);
			}
			glEnd();

			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}break;
	case 3:
	{
		glPushMatrix();
		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-0.3, 0.3, 0);
			glVertex3d(0.3, 0.3, 0);
			glVertex3d(0.3, -0.3, 0);
			glVertex3d(-0.3, -0.3, 0);

		}
		glEnd();
		{
			glPushMatrix();
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.4, 0.4, 0);
				glVertex3d(0.4, 0.4, 0);
				glVertex3d(0.4, -0.4, 0);
				glVertex3d(-0.4, -0.4, 0);
			}
			glEnd();

			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}break;
	case 4:
	{
		glPushMatrix();
		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-0.3, 0, 0);
			glVertex3d(0, 0.3, 0);
			glVertex3d(0.3, 0, 0);
			glVertex3d(0, -0.3, 0);

		}
		glEnd();
		{
			glPushMatrix();
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.4, 0, 0);
				glVertex3d(0, 0.4, 0);
				glVertex3d(0.4, 0, 0);
				glVertex3d(0, -0.4, 0);
			}
			glEnd();

			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}break;
	case 5:
	{
		glPushMatrix();
		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_POLYGON);
		{
			glVertex3d(-1.62 / 5, 0.3 / 5, 0);
			glVertex3d(0.0, 1.6 / 5, 0);
			glVertex3d(1.62 / 5, 0.3 / 5, 0);
			glVertex3d(1.0 / 5, -1.6 / 5, 0);
			glVertex3d(-1.0 / 5, -1.6 / 5, 0);


		}
		glEnd();
		{
			glPushMatrix();
			glTranslated(x_, y_, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{

				glVertex3d(-1.62 / 4, 0.3 / 4, 0);
				glVertex3d(0.0, 1.6 / 4, 0);
				glVertex3d(1.62 / 4, 0.3 / 4, 0);
				glVertex3d(1.0 / 4, -1.6 / 4, 0);
				glVertex3d(-1.0 / 4, -1.6 / 4, 0);

			}
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}break;
	case 6:
	{
		glPushMatrix();
		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_POLYGON);
		{

			glVertex3d(0.5 / 6, 0.5 / 6, 0);
			glVertex3d(2.0 / 6, 0.5 / 6, 0);
			glVertex3d(1.0 / 6, -0.5 / 6, 0);
			glVertex3d(1.5 / 6, -2.0 / 6, 0);
			glVertex3d(0.0 / 6, -1.0 / 6, 0);
			glVertex3d(-1.5 / 6, -2.0 / 6, 0);
			glVertex3d(-1.0 / 6, -0.5 / 6, 0);
			glVertex3d(-2.0 / 6, 0.5 / 6, 0);
			glVertex3d(-0.5 / 6, 0.5 / 6, 0);
			glVertex3d(0.0 / 6, 2.0 / 6, 0);


		}
		glEnd();
		{
			glPushMatrix();
			glTranslated(x_, y_, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(0.5 / 4, 0.5 / 4, 0);
				glVertex3d(2.0 / 4, 0.5 / 4, 0);
				glVertex3d(1.0 / 4, -0.5 / 4, 0);
				glVertex3d(1.5 / 4, -2.0 / 4, 0);
				glVertex3d(0.0 / 4, -1.0 / 4, 0);
				glVertex3d(-1.5 / 4, -2.0 / 4, 0);
				glVertex3d(-1.0 / 4, -0.5 / 4, 0);
				glVertex3d(-2.0 / 4, 0.5 / 4, 0);
				glVertex3d(-0.5 / 4, 0.5 / 4, 0);
				glVertex3d(0.0 / 4, 2.0 / 4, 0);

			}
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}break;
	case 7:
	{

		glPushMatrix();
		glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(0, 0.0, 0.0, 1.0);

		glColor3d(1.0, 1.0, 1.0);

		glBegin(GL_POLYGON);
		{

			glVertex3d(0.5 / 6, 0.5 / 6, 0);
			glVertex3d(2.0 / 4.5, 0.5 / 6, 0);
			glVertex3d(2.0 / 4.5, -0.5 / 6, 0);
			glVertex3d(0.5 / 6, -0.5 / 6, 0);
			glVertex3d(0.5 / 6, -2.0 / 4.5, 0);
			glVertex3d(-0.5 / 6, -2.0 / 4.5, 0);
			glVertex3d(-0.5 / 6, -0.5 / 6, 0);
			glVertex3d(-2.0 / 4.5, -0.5 / 6, 0);
			glVertex3d(-2.0 / 4.5, 0.5 / 6, 0);
			glVertex3d(-0.5 / 6, 0.5 / 6, 0);
			glVertex3d(-0.5 / 6, 2.0 / 4.5, 0);
			glVertex3d(0.5 / 6, 2.0 / 4.5, 0);

		}
		glEnd();

		{

			glPushMatrix();
			glTranslated(x_, y_, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{

				glVertex3d(0.5 / 4, 0.5 / 4, 0);
				glVertex3d(2.0 / 4, 0.5 / 4, 0);
				glVertex3d(2.0 / 4, -0.5 / 4, 0);
				glVertex3d(0.5 / 4, -0.5 / 4, 0);
				glVertex3d(0.5 / 4, -2.0 / 4, 0);
				glVertex3d(-0.5 / 4, -2.0 / 4, 0);
				glVertex3d(-0.5 / 4, -0.5 / 4, 0);
				glVertex3d(-2.0 / 4, -0.5 / 4, 0);
				glVertex3d(-2.0 / 4, 0.5 / 4, 0);
				glVertex3d(-0.5 / 4, 0.5 / 4, 0);
				glVertex3d(-0.5 / 4, 2.0 / 4, 0);
				glVertex3d(0.5 / 4, 2.0 / 4, 0);

			}
			glEnd();
			glPopMatrix();
		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(x_, y_, 0.0);

		this->draw_passengers();

		glPopMatrix();
	}
	}
}
void cDraw_Station::set_x_y(double x, double y)
{
	x_ = x;
	y_ = y;
}
double cDraw_Station::get_x()
{
	return x_;
}
double cDraw_Station::get_y()
{
	return y_;
}
void cDraw_Station::draw_passengers()
{
	glTranslated(0.4, 0.6, 0.0);
	for (int i = 0; i < passengers_.size(); i++)
	{
		switch (passengers_[i])
		{
		case 1:
		{
			glTranslated(0.35, 0.0, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);


			double angle, vectorX, vectorY, vectorX1, vectorY1;
			glBegin(GL_TRIANGLES);
			vectorX1 = 0.35/2;
			vectorY1 = 0.35/2;
			int seg = 360;
			for (int i = 0; i <= seg; i++)
			{
				angle = (M_PI / (180.0))*((float)i);
				vectorX = 0.35/2 + (0.1*sin(angle));
				vectorY = 0.35/2 + (0.1*cos(angle));
				glVertex2f(0.35/2, 0.35/2);
				glVertex2f(vectorX1, vectorY1);
				glVertex2f(vectorX, vectorY);
				vectorY1 = vectorY;
				vectorX1 = vectorX;
			}
			glEnd();
		}break;
		case 2:
		{
			glTranslated(0.5, 0.1, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.1, -0.1 / 3, 0);
				glVertex3d(0.1, -0.1 / 3, 0);
				glVertex3d(0.0, 0.2 / 3, 0);
			}
			glEnd();
			glTranslated(-0.1, -0.1, 0.0);

		}break;
		case 3:
		{
			glTranslated(0.5, 0.1, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.1, 0.1, 0);
				glVertex3d(0.1, 0.1, 0);
				glVertex3d(0.1, -0.1, 0);
				glVertex3d(-0.1, -0.1, 0);
			}
			glEnd();
			glTranslated(-0.1, -0.1, 0.0);
		}break;
		case 4:
		{
			glTranslated(0.5, 0.1, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.15, 0, 0);
				glVertex3d(0, 0.15, 0);
				glVertex3d(0.15, 0, 0);
				glVertex3d(0, -0.15, 0);
			}
			glEnd();
			glTranslated(-0.1, -0.1, 0.0);

		}break;
		case 5:
		{
			glTranslated(0.5, 0.1, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-1.62 / 12, 0.3 / 12, 0);
				glVertex3d(0.0, 1.6 / 12, 0);
				glVertex3d(1.62 / 12, 0.3 / 12, 0);
				glVertex3d(1.0 / 12, -1.6 / 12, 0);
				glVertex3d(-1.0 / 12, -1.6 / 12, 0);
			}
			glEnd();
			glTranslated(-0.1, -0.1, 0.0);
		}break;
		case 6:
		{
			glTranslated(0.5, 0.1, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(0.5 / 12, 0.5 / 12, 0);
				glVertex3d(2.0 / 12, 0.5 / 12, 0);
				glVertex3d(1.0 / 12, -0.5 / 12, 0);
				glVertex3d(1.5 / 12, -2.0 / 12, 0);
				glVertex3d(0.0 / 12, -1.0 / 12, 0);
				glVertex3d(-1.5 / 12, -2.0 / 12, 0);
				glVertex3d(-1.0 / 12, -0.5 / 12, 0);
				glVertex3d(-2.0 / 12, 0.5 / 12, 0);
				glVertex3d(-0.5 / 12, 0.5 / 12, 0);
				glVertex3d(0.0 / 12, 2.0 / 12, 0);
			}
			glEnd();
			glTranslated(-0.1, -0.1, 0.0);
		}break;
		case 7:
		{
			glTranslated(0.5, 0.1, 0.0);
			glRotated(0, 1.0, 0.0, 0.0);
			glRotated(0, 0.0, 1.0, 0.0);
			glRotated(0, 0.0, 0.0, 1.0);

			glColor3d(0.0, 0.0, 0.0);

			glBegin(GL_POLYGON);
			{
				glVertex3d(0.5 / 12, 0.5 / 12, 0);
				glVertex3d(2.0 / 12, 0.5 / 12, 0);
				glVertex3d(2.0 / 12, -0.5 / 12, 0);
				glVertex3d(0.5 / 12, -0.5 / 12, 0);
				glVertex3d(0.5 / 12, -2.0 / 12, 0);
				glVertex3d(-0.5 / 12, -2.0 / 12, 0);
				glVertex3d(-0.5 / 12, -0.5 / 12, 0);
				glVertex3d(-2.0 / 12, -0.5 / 12, 0);
				glVertex3d(-2.0 / 12, 0.5 / 12, 0);
				glVertex3d(-0.5 / 12, 0.5 / 12, 0);
				glVertex3d(-0.5 / 12, 2.0 / 12, 0);
				glVertex3d(0.5 / 12, 2.0 / 12, 0);
			}
			glEnd();
			glTranslated(-0.1, -0.1, 0.0);
		}break;
		}
	}
}
bool cDraw_Station::warunek_klikniecia(double glX, double glY)
{
	bool war = false;
	if (glX <= (x_ + 0.3) && glX >= (x_ - 0.3) && glY <= (y_ + 0.3) && glY >= (y_ - 0.3))
	{
		war = true;
	}
	return war;
}
