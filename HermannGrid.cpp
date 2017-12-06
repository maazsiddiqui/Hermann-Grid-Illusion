#include "stdafx.h"
#include <gl/glut.h>

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	
	int countRow = 0, countCol = 0;
	int x = 100, y = 100;
	
	while (countRow < 5) {
		
		while (countCol < 5) {
			glVertex2i(x, y);
			glVertex2i(x + 55, y);
			glVertex2i(x + 55, y + 55);
			glVertex2i(x, y + 55);
			x += 70;
			countCol++;
		}

		x = 100;
		y += 70;
		countRow++;
		countCol = 0;
	}

	glEnd();
	glFlush();
}


void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Hermann Grid Illusion");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glutDisplayFunc(display);
	glutMainLoop();
}