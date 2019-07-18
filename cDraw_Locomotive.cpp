#include "cDraw_Locomotive.h"

cDraw_Locomotive::cDraw_Locomotive(double x, double y, double angle) : x_(x), y_(y), angle_(angle)
{

}
//void cDraw_Locomotive::draw_locomotive()
//{
//	glTranslated(x_/2, y_/2, 0.0);
//
//	this->draw_passengers();
//	{
//		glPushMatrix();
//		glTranslated(x_/2, y_/2, 0.0);
//		glRotated(0, 1.0, 0.0, 0.0);
//		glRotated(0, 0.0, 1.0, 0.0);
//		glRotated(angle_, 0.0, 0.0, 1.0);
//
//		double colors[3];
//		if (color_ == -1) { colors[0] = 0.5; colors[1] = 0.5; colors[2] = 0.5; } // Kolor dla kolejki która jeszcze nie zosta³a przypisana do linii.
//		if (color_ == 0) { colors[0] = 1.0; colors[1] = 0.0; colors[2] = 0.0; }
//		if (color_ == 1) { colors[0] = 0.0; colors[1] = 0.0; colors[2] = 1.0; }
//		if (color_ == 2) { colors[0] = 1.0; colors[1] = 1.0; colors[2] = 0.0; }
//		if (color_ == 3) { colors[0] = 0.0; colors[1] = 1.0; colors[2] = 0.0; }
//		if (color_ == 4) { colors[0] = 1.0; colors[1] = 0.65; colors[2] = 0.0; }
//		if (color_ == 5) { colors[0] = 0.72; colors[1] = 0.0; colors[2] = 1.0; }
//		if (color_ == 6) { colors[0] = 0.0; colors[1] = 1.0; colors[2] = 1.0; }
//		glColor3d(colors[0], colors[1], colors[2]);
//
//		glBegin(GL_POLYGON);
//		{
//			glVertex3d(-0.8, 0.35, 0);
//			glVertex3d(0.8, 0.35, 0);
//			glVertex3d(0.8, -0.35, 0);
//			glVertex3d(-0.8, -0.35, 0);
//		}
//		glEnd();
//		glPopMatrix();
//		//glTranslated(0.0, 0.0, 0.0);
//		//glPushMatrix();
//		//glPopMatrix();
//
//	}
//}
//void cDraw_Locomotive::draw_passengers()
//{
//
//	for (int i = 0; i < passengers_.size(); i++)
//	{
//		glPushMatrix();
//		glRotated(0, 1.0, 0.0, 0.0);
//		glRotated(0, 0.0, 1.0, 0.0);
//		glRotated(angle_, 0.0, 0.0, 1.0);
//
//		if (i == 0)
//		{
//			glTranslated(0.4, 0.15, 0.0);
//		}
//		if (i == 1)
//		{
//			glTranslated(0.4, -0.15, 0.0);
//		}
//		if (i == 2)
//		{
//			glTranslated(0.0, 0.15, 0.0);
//		}
//		if (i == 3)
//		{
//			glTranslated(0.0, -0.15, 0.0);
//		}
//		if (i == 4)
//		{
//			glTranslated(-0.4, 0.15, 0.0);
//		}
//		if (i == 5)
//		{
//			glTranslated(-0.4, -0.15, 0.0);
//		}
//
//
//		switch (passengers_[i])
//		{
//		case 1:
//		{
//			if (i == 0)
//			{
//				glTranslated(-0.2, -0.18, 0.0);
//			}
//			if (i == 1)
//			{
//				glTranslated(-0.2, 0.18, 0.0);
//			}
//			if (i == 2)
//			{
//				glTranslated(0.0, -0.18, 0.0);
//			}
//			if (i == 3)
//			{
//				glTranslated(0.0, 0.18, 0.0);
//			}
//			if (i == 4)
//			{
//				glTranslated(0.2, -0.18, 0.0);
//			}
//			if (i == 5)
//			{
//				glTranslated(0.2, 0.18, 0.0);
//			}
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//
//			double angle, vectorX, vectorY, vectorX1, vectorY1;
//			glBegin(GL_TRIANGLES);
//			vectorX1 = 0.35 / 2;
//			vectorY1 = 0.35 / 2;
//			int seg = 360;
//			for (int k = 0; k <= seg; k++)
//			{
//				angle = (M_PI / (180.0))*((float)k);
//				vectorX = 0.35 / 2 + (0.1*sin(angle));
//				vectorY = 0.35 / 2 + (0.1*cos(angle));
//				glVertex2f(0.35 / 2, 0.35 / 2);
//				glVertex2f(vectorX1, vectorY1);
//				glVertex2f(vectorX, vectorY);
//				vectorY1 = vectorY;
//				vectorX1 = vectorX;
//			}
//			glEnd();
//		}break;
//		case 2:
//		{
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//			glBegin(GL_POLYGON);
//			{
//				glVertex3d(-0.1, -0.1 / 3, 0);
//				glVertex3d(0.1, -0.1 / 3, 0);
//				glVertex3d(0.0, 0.2 / 3, 0);
//			}
//			glEnd();
//
//		}break;
//		case 3:
//		{
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//			glBegin(GL_POLYGON);
//			{
//				glVertex3d(-0.1, 0.1, 0);
//				glVertex3d(0.1, 0.1, 0);
//				glVertex3d(0.1, -0.1, 0);
//				glVertex3d(-0.1, -0.1, 0);
//			}
//			glEnd();
//		}break;
//		case 4:
//		{
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//			glBegin(GL_POLYGON);
//			{
//				glVertex3d(-0.15, 0, 0);
//				glVertex3d(0, 0.15, 0);
//				glVertex3d(0.15, 0, 0);
//				glVertex3d(0, -0.15, 0);
//			}
//			glEnd();
//
//		}break;
//		case 5:
//		{
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//			glBegin(GL_POLYGON);
//			{
//				glVertex3d(-1.62 / 12, 0.3 / 12, 0);
//				glVertex3d(0.0, 1.6 / 12, 0);
//				glVertex3d(1.62 / 12, 0.3 / 12, 0);
//				glVertex3d(1.0 / 12, -1.6 / 12, 0);
//				glVertex3d(-1.0 / 12, -1.6 / 12, 0);
//			}
//			glEnd();
//		}break;
//		case 6:
//		{
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//			glBegin(GL_POLYGON);
//			{
//				glVertex3d(0.5 / 12, 0.5 / 12, 0);
//				glVertex3d(2.0 / 12, 0.5 / 12, 0);
//				glVertex3d(1.0 / 12, -0.5 / 12, 0);
//				glVertex3d(1.5 / 12, -2.0 / 12, 0);
//				glVertex3d(0.0 / 12, -1.0 / 12, 0);
//				glVertex3d(-1.5 / 12, -2.0 / 12, 0);
//				glVertex3d(-1.0 / 12, -0.5 / 12, 0);
//				glVertex3d(-2.0 / 12, 0.5 / 12, 0);
//				glVertex3d(-0.5 / 12, 0.5 / 12, 0);
//				glVertex3d(0.0 / 12, 2.0 / 12, 0);
//			}
//			glEnd();
//		}break;
//		case 7:
//		{
//
//			double colors_p[3];
//			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
//			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
//			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
//			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
//			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
//			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
//			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
//			glColor3d(colors_p[0], colors_p[1], colors_p[2]);
//
//			glBegin(GL_POLYGON);
//			{
//				glVertex3d(0.5 / 12, 0.5 / 12, 0);
//				glVertex3d(2.0 / 12, 0.5 / 12, 0);
//				glVertex3d(2.0 / 12, -0.5 / 12, 0);
//				glVertex3d(0.5 / 12, -0.5 / 12, 0);
//				glVertex3d(0.5 / 12, -2.0 / 12, 0);
//				glVertex3d(-0.5 / 12, -2.0 / 12, 0);
//				glVertex3d(-0.5 / 12, -0.5 / 12, 0);
//				glVertex3d(-2.0 / 12, -0.5 / 12, 0);
//				glVertex3d(-2.0 / 12, 0.5 / 12, 0);
//				glVertex3d(-0.5 / 12, 0.5 / 12, 0);
//				glVertex3d(-0.5 / 12, 2.0 / 12, 0);
//				glVertex3d(0.5 / 12, 2.0 / 12, 0);
//			}
//			glEnd();
//		}break;
//
//
//		}
//		glPopMatrix();
//	}
//}
void cDraw_Locomotive::draw_locomotive()
{
	glPushMatrix();
	glTranslated(x_, y_, 0.0);


	//glPushMatrix();
	this->draw_passengers();
	//glPopMatrix();

	{


		//glPushMatrix();
		//glTranslated(x_, y_, 0.0);
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(angle_, 0.0, 0.0, 1.0);

		double colors[3];
		if (color_ == -1) { colors[0] = 0.5; colors[1] = 0.5; colors[2] = 0.5; } // Kolor dla kolejki która jeszcze nie zosta³a przypisana do linii.
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
			glVertex3d(-0.8, 0.35, 0);
			glVertex3d(0.8, 0.35, 0);
			glVertex3d(0.8, -0.35, 0);
			glVertex3d(-0.8, -0.35, 0);
		}
		glEnd();
		glTranslated(0.0, 0.0, 0.0);
		glPopMatrix();
		//glPopMatrix();

	}
}
void cDraw_Locomotive::draw_passengers()
{

	for (int i = 0; i < passengers_.size(); i++)
	{
		glPushMatrix();
		glRotated(0, 1.0, 0.0, 0.0);
		glRotated(0, 0.0, 1.0, 0.0);
		glRotated(angle_, 0.0, 0.0, 1.0);

		if (i == 0)
		{
			glTranslated(0.4, 0.15, 0.0);
		}
		if (i == 1)
		{
			glTranslated(0.4, -0.15, 0.0);
		}
		if (i == 2)
		{
			glTranslated(0.0, 0.15, 0.0);
		}
		if (i == 3)
		{
			glTranslated(0.0, -0.15, 0.0);
		}
		if (i == 4)
		{
			glTranslated(-0.4, 0.15, 0.0);
		}
		if (i == 5)
		{
			glTranslated(-0.4, -0.15, 0.0);
		}


		switch (passengers_[i])
		{
		case 1:
		{
			if (i == 0)
			{
				glTranslated(-0.2, -0.18, 0.0);
			}
			if (i == 1)
			{
				glTranslated(-0.2, 0.18, 0.0);
			}
			if (i == 2)
			{
				glTranslated(0.0, -0.18, 0.0);
			}
			if (i == 3)
			{
				glTranslated(0.0, 0.18, 0.0);
			}
			if (i == 4)
			{
				glTranslated(0.2, -0.18, 0.0);
			}
			if (i == 5)
			{
				glTranslated(0.2, 0.18, 0.0);
			}

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);


			double angle, vectorX, vectorY, vectorX1, vectorY1;
			glBegin(GL_TRIANGLES);
			vectorX1 = 0.35 / 2;
			vectorY1 = 0.35 / 2;
			int seg = 360;
			for (int k = 0; k <= seg; k++)
			{
				angle = (M_PI / (180.0))*((float)k);
				vectorX = 0.35 / 2 + (0.1*sin(angle));
				vectorY = 0.35 / 2 + (0.1*cos(angle));
				glVertex2f(0.35 / 2, 0.35 / 2);
				glVertex2f(vectorX1, vectorY1);
				glVertex2f(vectorX, vectorY);
				vectorY1 = vectorY;
				vectorX1 = vectorX;
			}
			glEnd();
		}break;
		case 2:
		{

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.1, -0.1 / 3, 0);
				glVertex3d(0.1, -0.1 / 3, 0);
				glVertex3d(0.0, 0.2 / 3, 0);
			}
			glEnd();

		}break;
		case 3:
		{

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.1, 0.1, 0);
				glVertex3d(0.1, 0.1, 0);
				glVertex3d(0.1, -0.1, 0);
				glVertex3d(-0.1, -0.1, 0);
			}
			glEnd();
		}break;
		case 4:
		{

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-0.15, 0, 0);
				glVertex3d(0, 0.15, 0);
				glVertex3d(0.15, 0, 0);
				glVertex3d(0, -0.15, 0);
			}
			glEnd();

		}break;
		case 5:
		{

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);

			glBegin(GL_POLYGON);
			{
				glVertex3d(-1.62 / 12, 0.3 / 12, 0);
				glVertex3d(0.0, 1.6 / 12, 0);
				glVertex3d(1.62 / 12, 0.3 / 12, 0);
				glVertex3d(1.0 / 12, -1.6 / 12, 0);
				glVertex3d(-1.0 / 12, -1.6 / 12, 0);
			}
			glEnd();
		}break;
		case 6:
		{

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);

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
		}break;
		case 7:
		{

			double colors_p[3];
			if (color_ == 0) { colors_p[0] = 1.0; colors_p[1] = 0.6; colors_p[2] = 0.6; }
			if (color_ == 1) { colors_p[0] = 0.6; colors_p[1] = 0.6; colors_p[2] = 1.0; }
			if (color_ == 2) { colors_p[0] = 1.0; colors_p[1] = 1.0; colors_p[2] = 0.8; }
			if (color_ == 3) { colors_p[0] = 0.6; colors_p[1] = 1.0; colors_p[2] = 0.6; }
			if (color_ == 4) { colors_p[0] = 1.0; colors_p[1] = 0.8; colors_p[2] = 0.8; }
			if (color_ == 5) { colors_p[0] = 0.86; colors_p[1] = 0.69; colors_p[2] = 0.94; }
			if (color_ == 6) { colors_p[0] = 0.75; colors_p[1] = 1.0; colors_p[2] = 1.0; }
			glColor3d(colors_p[0], colors_p[1], colors_p[2]);

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
		}break;


		}
		glPopMatrix();
	}
}
void cDraw_Locomotive::set_color_(int color)
{
	color_ = color;
}
void cDraw_Locomotive::set_x_y_(double x, double y)
{
	x_ = x;
	y_ = y;
}
double cDraw_Locomotive::get_x_()
{
	return x_;
}
double cDraw_Locomotive::get_y_()
{
	return y_;
}
void cDraw_Locomotive::set_angle_(double angle)
{
	angle_ = angle;
}