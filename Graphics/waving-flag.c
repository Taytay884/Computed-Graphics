
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"

double x = -0.2, y = 0.9;

void init()
{
	int i;
	//                 R     G    B
	glClearColor(0.5, 0.0, 0.0, 0);// color of window background
	glOrtho(-1, 1, -1, 1, -1, 1); // set the coordinates system

}

// put all the drawings here
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer

	glPointSize(3);
	glLineWidth(3);
	// starts points definition
	glBegin(GL_POLYGON);// GL_LINE_LOOP);//GL_LINE_STRIP);//GL_LINES);//GL_POINTS); 
	glColor3d(1, 1, 0); // yellow
	glVertex2d(-0.8, -0.5);
	glColor3d(0, 0.6, 1); // blue
	glVertex2d(0.2, -0.1);
	glColor3d(fabs(x), fabs(y), 1); // white
	glVertex2d(x, y);
	glColor3d(0, 1, 0); // green
	glVertex2d(-0.9, 0.6);
	glEnd(); // ends points definition

	glutSwapBuffers(); // show all
}

void idle()
{
	x += 0.001;
	y -= 0.002;
	glutPostRedisplay();
}


void wavingFlag(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("First Example");

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	init();

	glutMainLoop();
}