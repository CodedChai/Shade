#include "Src\graphics\window.h"
#include "Src\math\math.h"
int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;
	using namespace math;

	Window window("Shade!", 1280, 720);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 1.0f);
	vector.add(vec2(2, 2)).add(vec2(3,3));

	vec2 a(1.0f, 2.0f);
	vec2 b(1.0f, 2.1f);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();
	
	while (!window.closed()) {
		window.clear();

		std::cout << (a != b) << std::endl;
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