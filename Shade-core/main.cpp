#include "Src\graphics\window.h"
#include "Src\math\math.h"
#include "Src\graphics\shader.h"

int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;
	using namespace math;

	Window window("Shade!", 1280, 720);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	

	GLfloat vertices[] = 
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("Src/shaders/basic.vert", "Src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	// To make the light in the center you must subtract translation as well
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("col", vec4(0.0f, 0.8f, 0.2f, 1.0f));

	while (!window.closed()) {
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}

	return 0;
}