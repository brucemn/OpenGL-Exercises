/*
Tetrahedron: A colored tetrahedron object is builded in the center of the screen. The object consists of four sides using 
four trinagular objects. It uses GL_TRIANGLE_FAN OpenGL primitive.
*/


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

int angledirection = 0;

void display() {
	
	// Rotate 2 degree * angledirection around "y "
	glRotatef(2.0*angledirection, 0, 1, 0);
	
	// Clear frame buffer
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Draw a white grid "floor" for the tetrahedron to sit on.
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	for (GLfloat i = -2.5; i <= 2.5; i += 0.25) {
		glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
		glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
	}
	glEnd();
	
	// Draw the tetrahedron. It repeats the last vertice and uses five vertices.
	glBegin(GL_TRIANGLE_FAN); 
	glColor3f(1, 1, 1); glVertex3f(0, 2, 0);   //white
	glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);  //red
	glColor3f(0, 1, 0); glVertex3f(1, 0, 1);   //green
	glColor3f(0, 0, 1); glVertex3f(0, 0, -1);  //blue
	glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);  //red

	glEnd();
	glFlush();
}

void init() {

	// Set the current clear color to sky blue and the current drawing color to
	// white.
	glClearColor(0.1, 0.39, 0.88, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	// Tell the rendering engine not to draw backfaces. 
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Set the camera lens so that we have a perspective viewing volume whose
	// horizontal bounds at the near clipping plane are -2..2 and vertical
	// bounds are -1.5..1.5. The near clipping plane is 1 unit from the camera
	// and the far clipping plane is 40 units away.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2, 2, -1.5, 1.5, 1, 40);

	// Rotate 45 degrees around x to "drop" the top of the pyramid
	// Move the object back 3 units "into the screen".
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);
	glRotatef(45, 1, 0, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '+': angledirection = 1.0; break;
	case '-': angledirection -= 1.0; break;
	}
	glutPostRedisplay();
}
// Initializes GLUT, the display mode, and main window; registers callbacks;
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Tetrahedron");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
}
