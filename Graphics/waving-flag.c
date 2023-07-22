
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include "waving-flag.h"

#define HEIGHT 600
#define WIDTH 600

double x = 0;
double offset = 0;

unsigned char pixels[HEIGHT][WIDTH][3];

void init()
{
	int i, j;
	//                 R     G    B
	glClearColor(0.5, 0.0, 0.0, 0);// color of window background
	glOrtho(-1, 1, -1, 1, -1, 1); // set the coordinates system

	int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;
	double dist1, dist2;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][0] = 150; // 0 RED
			pixels[i][j][1] = 150; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE

			pixels[i][j][0] += 50 * sin(dist1 / 40.0 + offset);
			pixels[i][j][1] += 50 * sin(dist1 / 40.0 + offset);
			pixels[i][j][2] += 50 * sin(dist1 / 40.0 + offset);
			// first strip
			if (i >= HEIGHT / 6 && i <= HEIGHT / 6 * 2) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 150; // 2 BLUE
				pixels[i][j][2] += 50 * sin(dist1 / 40.0 + offset);
			}
			if (i >= HEIGHT / 6 * 4 && i <= HEIGHT / 6 * 5) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 150; // 2 BLUE
				pixels[i][j][2] += 50 * sin(dist1 / 40.0 + offset);
			}
			dist1 = distance(j, i, -WIDTH, HEIGHT/2);
			//if (dist 0)
		}
	}
}

double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// put all the drawings here
void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer
	glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glutSwapBuffers();
}

void idle()
{
	x++;
	offset -= 0.03;
	init();
	glutPostRedisplay();
}


void wavingFlag(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("First Example");

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	init();

	glutMainLoop();
}