#include "Src/graphics/window.h"

int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;

	Window window("Shade!", 800, 600);
	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	while (!window.closed()) {
		//glClear(GL_COLOR_BUFFER_BIT);
		window.update();
	}

	return 0;
}