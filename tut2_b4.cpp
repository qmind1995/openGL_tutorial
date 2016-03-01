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

void CreateSphere(int nStacks, int nSlices, float R){
	glColor3f(0, 0, 0.5);
	glLineWidth(1);
	//glBegin(GL_QUAD_STRIP);
	for (float i = 0; i < nSlices; i++){
		glBegin(GL_QUAD_STRIP);
		for (float j = 0; j < nStacks; j++){
			float u = 2 * PI*i / nSlices;
			float v = 2*PI*j / nStacks;

			float x = R*sin(v)*cos(u);
			float y = R*sin(u);
			float z = R*cos(v)*cos(u);
			glVertex3f(x, y, z);
			x = R*sin(v)*cos(u + PI / nSlices);
			z = R*cos(v)*cos(u + PI / nSlices);
			y = R*sin(u + PI / nSlices);
			glVertex3f(x, y, z);

		}
		glEnd();

	}
}

void myDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();
	glOrtho(-20, 20, -20, 20, -20, 20);
	glViewport(-150, -150, 600, 600);
	gluLookAt(
		-1, //eyeX
		-1, //eyeY
		-1, //eyeZ
		-0.1, //reference point X
		-0.1, //reference point Y
		-0.1, //reference point Z
		0.0, //up vector X
		0.0, //up vector Y
		1.0 //up vector Z
		);
	CreateSphere(24, 16, 10);
	glFlush();
	glutSwapBuffers();
}

void main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	//glutInitWindowSize(600, 600);
	glutCreateWindow("sphere");
	//myinit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
