#include "stdafx.h"
#include <glut.h>
#include <math.h>

void drawMandelbrotSet(){
    double maxStep = 700;
    double maxIterations = 512;
    double maxRadius = 2;
    
    double startX = 0;
    double startY = 0;
    double R = 2;
    double epsilon = 2 * R / maxStep;

    glBegin(GL_POINTS);
    for (double x = startX - R; x <= startX + R; x += epsilon){
        for (double y = startY - R; y <= startY + R; y += epsilon){
            double iterations = 0;
            double cReal = x;
            double cImg = y;

            double zReal = 0;
            double zImg = 0;
            double Temp = 0;

            while (sqrt(zReal * zReal + zImg * zImg) <= maxRadius && iterations < maxIterations){
                Temp = zReal * zReal - zImg * zImg + cReal;
                zImg = zReal * zImg * 2 + cImg;
                zReal = Temp;
                iterations++;
            }

            double magnitude = sqrt(zReal * zReal + zImg * zImg);
            double colorIte = iterations + 1 - log(log(magnitude)) / maxRadius;
            double color = colorIte / maxIterations;

            if ((sqrt(zReal * zReal + zImg * zImg) <= maxRadius && iterations >= maxIterations)){
                glColor3f(color, 1, 0.5);
                glVertex2f((x - startX + R) * 4 / (2 * R) - 2, (y - startY + R) * 4 / (2 * R) - 2);
            }
            else{
                glColor3f(0, color, 0);
                glVertex2f((x - startX + R) * 4 / (2 * R) - 2, (y - startY + R) * 4 / (2 * R) - 2);
            }
        }
    }

    glEnd();
}

void	myDisplay() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-2, 2, -2, 2, -2, 2);

    glClearColor(0.5, 0.5, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    drawMandelbrotSet();

    glFlush();
}



int main(int argc, char** argv[]){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Tut 2");
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}