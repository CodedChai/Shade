#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <GL\freeglut.h>
#include <iostream>

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");

	glutMainLoop();

	return 0;
}