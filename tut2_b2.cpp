#include "stdafx.h"
#include <windows.h>
#include <gl.h>
#include <glut.h>
#include<math.h>
#include<cstdlib>

int WIDTH = 600;
int HEIGHT = 600;
float E = 1024;
float PI = 3.141592654;


void setCameraVolume(float l, float r, float b, float t){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
}
void setViewport(int l, int r, int b, int t){
	glViewport(l, b, r - l, t - b);
}

void drawArcs(){
	glColor3f(1, 1, 1);
	glLineWidth(1);
	float R = 0.5;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 90; i++){
		float x = R*cos(i*PI / 180.0);
		float y = R*sin(i*PI / 180.0);
		glVertex2f(x, y);
	}
	
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i <= 270; i++){
		float x = R*cos(i*PI / 180.0) +1;
		float y = R*sin(i*PI / 180.0) +1;
		glVertex2f(x, y);
	}
	glEnd();
}

void draw_Latnen(float r) {

	int		motifWidth, motifHeight;
	motifWidth = WIDTH / r;
	motifHeight = HEIGHT / r;
	for (int i = 0; i< r; i++)
		for (int j = 0; j<r; j++)
		{
			int x = rand() % 2;
			if (x == 0)

				setCameraVolume(0, 1, 1, 0);
			else
				setCameraVolume(0, 1, 0, 1);
			setViewport(i*WIDTH / r, (i + 1)*WIDTH / r, j*HEIGHT / r, (j + 1)*HEIGHT / r);
			drawArcs();
		}
}


void myDisplay(){
	setViewport(0, WIDTH, 0, HEIGHT);
	draw_Latnen(8);
	glFlush();
}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, (char**)argv); //initialize the tool kit
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set the display mode
	glutInitWindowSize(600, 600); //set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("The Big Dipper");//open the screen window

	glutDisplayFunc(myDisplay);
//	myInit();
	glutMainLoop();
	return 0;
}


