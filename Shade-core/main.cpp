#include "Src/graphics/window.h"

int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;

	Window window("Shade!", 1280, 720);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	std::cout << glGetString(GL_VERSION) << std::endl;
	
	while (!window.closed()) {
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-.5f, -.5f);
		glVertex2f(.0f, .5f);
		glVertex2f(.5f, -.5f);
		glEnd();
		window.update();
	}

	return 0;
}