
/*
Assignment 2-1: Build an OpenGL program that displays a colored triangle in the center of the screen. 
It is created with using three vertexes. Each vertex is defined withe different color attribute (red, green and blue).
*/

#include <GL/freeglut.h>


void DrawTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); //red
	glVertex2f(0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);//green
	glVertex2f(1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f); //blue
	glVertex2f(0.0f, 1.0f);
	glEnd();
}

void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //black
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix(); //push modelview matrix
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 0.0f);
	DrawTriangle();
	glPopMatrix(); //pop modelview matrix
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.5f, 1.5f, 1.0f, 1.5f, 1.5f, -0.5f, 0.0f, 1.0f, 0.0f);
}

void init()
{
	//Gouraud Shading
	glShadeModel(GL_SMOOTH);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Display mode.
	glutInitWindowPosition(100, 100); // Top-left display-window position.
	glutInitWindowSize(400, 400); // Display-window width and height.
	glutCreateWindow("Assignment2-1"); // Create display window.
	init(); // Initialization procedure.
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop(); // Display everything and wait.
}
