#include "Src\graphics\window.h"
#include "Src\math\math.h"
#include "Src\graphics\shader.h"

#include "Src\graphics\buffers\buffer.h"
#include "Src\graphics\buffers\indexbuffer.h"
#include "Src\graphics\buffers\vertexarray.h"

#include "Src\graphics\renderer2d.h"
#include "Src\graphics\simple2drenderer.h"


int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;
	using namespace math;

	Window window("Shade!", 1280, 720);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader shader("Src/shaders/basic.vert", "Src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translate(vec3(4, 3, 0)));

	Renderable2D sprite1(math::vec3(5, 5, 0), math::vec2(4, 4), math::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite2(math::vec3(7, 1, 0), math::vec2(4, 4), math::vec4(0, 1, 1, 1), shader);
	Renderable2D sprite3(math::vec3(1, 3, 0), math::vec2(4, 4), math::vec4(1, 1, 0, 1), shader);
	Simple2DRenderer renderer;

	shader.setUniform4f("col", vec4(0.0f, 0.8f, 0.2f, 1.0f));

	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));
		renderer.submit(&sprite1);
		renderer.submit(&sprite2);
		renderer.submit(&sprite3);
		renderer.flush();
		window.update();
	}

	return 0;
}