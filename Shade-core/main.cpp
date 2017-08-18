#include "Src/graphics/window.h"

int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;

	Window window("Shade!", 1280, 720);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	while (!window.closed()) {
		window.clear();
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) {
			std::cout << "PRESSED" << std::endl;
		}

		double x, y;
		window.getMousePosition(x, y);
		std::cout << x << y << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-.5f, -.5f);
		glVertex2f(-.5f, .5f);
		glVertex2f(.5f, .5f);
		glVertex2f(.5f, -.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}