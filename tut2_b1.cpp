#include "stdafx.h"
#include <windows.h>
#include <gl.h>
#include <glut.h>
#include<math.h>
int WIDTH = 600;
int HEIGHT = 600;
float E = 1024;

void drawFigure(){
	int Radius = 1;
	int Delta = 5;
	float PI = 3.141592654;
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);

	for (int i = 0; i <= 180; i += Delta){
		glVertex2f(Radius * cos(i * PI / 180) + 1, Radius * sin(i * PI / 180));
	}
	for (int i = 0; i >= -180; i -= Delta){
		glVertex2f(Radius * cos(i * PI / 180) - 1, Radius * sin(i * PI / 180));
	}
	glEnd();
	
}

void setCameraVolume(float l, float r, float b, float t){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D((GLdouble)l, (GLdouble)r, (GLdouble)b, (GLdouble)t);
}
void setViewport(int l, int r, int b, int t){
	glViewport(l, b, r - l, t - b);
}

void draw_3(float r){// ve~ cac duong tron tiep xuc nhau, chung' co' tam nam tren 1 duong thang
	if (r >= E) return;
	else if (r == 1){ // ve~ duong tron to o ngoa`i cung`
		setCameraVolume(0, 2, -1, 1);
		drawFigure();
		setCameraVolume(0, 2, 1, -1);
		drawFigure();
	}
	else{
		setCameraVolume(-r, r, -r, r);
		drawFigure();
		setCameraVolume(-r, r, r, -r);
		drawFigure();
	}
	draw_3(r * 2);
}

void draw_4(float r){ // ve~ cac duong tron tiep xuc nhau + thang hang+ r2=r1/2.
	if (r >= E) return;
	else if (r==1){
		setCameraVolume(0, 2, -1, 1);
		drawFigure();
		setCameraVolume(0, 2, 1, -1);
		drawFigure();
	}
	else{
		for (int i = 1; 2*i <= r; i++){
			setViewport(600*(2*i-1)/r-300, 600*(2*i-1)/r +300, 0, HEIGHT); // qy luat
			setCameraVolume(-r, r, -r, r);
			drawFigure();
			setCameraVolume(-r, r, r, -r);
			drawFigure();
		}
	}
	draw_4(r * 2);
}

void myDisplay(){
	setViewport(0, WIDTH, 0, HEIGHT);
	glColor3f(1, 1, 1);
	draw_3(1);
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