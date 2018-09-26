
/*
Assignment 1:  OpenGL program that shows two intersecting lines.
*/


#include <GL/freeglut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // Display-window color to white.
	glMatrixMode(GL_PROJECTION); // Projection parameters.
	gluOrtho2D(0.0, 200.0, 0.0, 150.0); //Sets up a two-dimensional orthographic viewing region.

}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f(1.0, 0.0, 0.0); // Line segment color to red.
	glBegin(GL_LINES);
	glVertex2i(180, 15); // Line-segment geometry.
	glVertex2i(10, 145);
	glColor3f(0.0, 1.0, 0.0); // Line segment color to green.
	glVertex2i(10, 15); // Line-segment geometry.
	glVertex2i(180, 145);
	glEnd();
	glFlush(); // Process all OpenGL routines.
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Display mode.
	glutInitWindowPosition(50, 100); // Top-left display-window position.
	glutInitWindowSize(400, 300); // Display-window width and height.
	glutCreateWindow("Assignment 1"); // Create display window.
	init(); // Initialization procedure.
	glutDisplayFunc(lineSegment); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.

}
