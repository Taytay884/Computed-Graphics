
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include "smiley.h"

#define HEIGHT 600
#define WIDTH 600

unsigned char pixels[HEIGHT][WIDTH][3];

static void init()
{
	int i, j;
	//                 R     G    B
	glClearColor(0.5, 0.0, 0.0, 0);// color of window background
	glOrtho(-1, 1, -1, 1, -1, 1); // set the coordinates system

	int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;

	int rightEyeX = centerX + centerX / 5;
	int rightEyeY = centerY + centerY / 5;
	int leftEyeX = centerX - centerX / 5;
	int leftEyeY = centerY + centerY / 5;

	double radius = 200;
	double eyeRadius = radius / 8;
	int smileDist = 120;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			double dist = distance(centerX, centerY, j, i);
			if (dist <= radius) {
				pixels[i][j][0] = 255; // 0 RED
				pixels[i][j][1] = 255; // 1 GREEN
				pixels[i][j][2] = 0; // 2 BLUE
			}
			else {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 100; // 1 GREEN
				pixels[i][j][2] = 0; // 2 BLUE
			}

			if (i < (centerY - centerY/10) && dist >= (smileDist - 20) && dist <= smileDist) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 0; // 2 BLUE
			}

			double rightEyeDist = distance(rightEyeX, rightEyeY, j, i);
			if (rightEyeDist <= eyeRadius) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 0; // 2 BLUE
			}

			double leftEyeDist = distance(leftEyeX, leftEyeY, j, i);
			if (leftEyeDist <= eyeRadius) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 0; // 2 BLUE
			}
		}
	}
}

static double distance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// put all the drawings here
static void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer
	glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glutSwapBuffers();
}

static void idle()
{
	glutPostRedisplay();
}


static void smiley(int argc, char* argv[])
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