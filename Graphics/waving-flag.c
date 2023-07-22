
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "glut.h"
#include "waving-flag.h"

#define HEIGHT 600
#define WIDTH 600

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
			pixels[i][j][0] = 200; // 0 RED
			pixels[i][j][1] = 200; // 1 GREEN
			pixels[i][j][2] = 200; // 2 BLUE

			pixels[i][j][0] += 55 * sin(dist1 / 40.0 + offset);
			pixels[i][j][1] += 55 * sin(dist1 / 40.0 + offset);
			pixels[i][j][2] += 55 * sin(dist1 / 40.0 + offset);
			// first strip
			if (i >= HEIGHT / 6 && i <= HEIGHT / 6 * 2) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 150; // 2 BLUE
				pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
			}
			// second strip
			if (i >= HEIGHT / 6 * 4 && i <= HEIGHT / 6 * 5) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 150; // 2 BLUE
				pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
			}
		}
	}
	//Magen David
	int x = centerX; int y = centerY + 50;
	int yEnd = centerY - 50;
	// top triangle
	for (int i = y + 10, count = -1; i > y; i--, count++) {
		for (int j = x - count; j <= x + count; j++) {
			pixels[i][j][0] = 0; // 0 RED
			pixels[i][j][1] = 0; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
		}
	}
	int space = 0;
	int width = 10;
	// diagonals
	for (int i = y; i > yEnd; i--) {
			width = 10;
			for (int j = x - space; j > x - space - width; j--) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 150; // 2 BLUE
				dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
				pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
			}
			for (int j = x + space; j < x + space + width; j++) {
				pixels[i][j][0] = 0; // 0 RED
				pixels[i][j][1] = 0; // 1 GREEN
				pixels[i][j][2] = 150; // 2 BLUE
				dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
				pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
			}
		space++;
	}
	// horizontal
	for (int i = yEnd + 8; i > yEnd; i--) {
		for (int j = x - space; j < x + space; j++) {
			pixels[i][j][0] = 0; // 0 RED
			pixels[i][j][1] = 0; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
		}
	}

	x = centerX; y = centerY - 70;
	yEnd = centerY + 30;
	//for (int i = y; i > y - 10)
	for (int i = y - 10, count = -1; i < y; i++, count++) {
		for (int j = x - count; j <= x + count; j++) {
			pixels[i][j][0] = 0; // 0 RED
			pixels[i][j][1] = 0; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
		}
	}
	space = 0;
	width = 10;
	for (int i = y; i < yEnd; i++) {
		width = 10;
		for (int j = x - space; j > x - space - width; j--) {
			pixels[i][j][0] = 0; // 0 RED
			pixels[i][j][1] = 0; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
		}
		for (int j = x + space; j < x + space + width; j++) {
			pixels[i][j][0] = 0; // 0 RED
			pixels[i][j][1] = 0; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
		}
		space++;
	}
	for (int i = yEnd - 8; i < yEnd; i++) {
		for (int j = x - space; j < x + space; j++) {
			pixels[i][j][0] = 0; // 0 RED
			pixels[i][j][1] = 0; // 1 GREEN
			pixels[i][j][2] = 150; // 2 BLUE
			dist1 = distance(j, i, -WIDTH, HEIGHT / 2);
			pixels[i][j][2] += 60 * sin(dist1 / 40.0 + offset);
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
	offset -= 0.05;
	init();
	glutPostRedisplay();
}


void wavingFlag(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Waving Israel Flag");

	glutDisplayFunc(display);
	glutIdleFunc(idle);

	init();

	glutMainLoop();
}