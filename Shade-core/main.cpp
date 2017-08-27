#include "Src\graphics\window.h"
#include "Src\math\math.h"
#include "Src\graphics\shader.h"

#include "Src\graphics\buffers\buffer.h"
#include "Src\graphics\buffers\indexbuffer.h"
#include "Src\graphics\buffers\vertexarray.h"

#include "Src\graphics\renderer2d.h"
#include "Src\graphics\simple2drenderer.h"
#include "Src\graphics\batchrenderer2d.h"

#include "Src\graphics\static_sprite.h"
#include "Src\graphics\sprite.h"
#include "Src\utils\timer.h"

#include "Src\graphics\layers\tilelayer.h"

#include <time.h>

int main(int argc, char **argv) {
	using namespace shade;
	using namespace graphics;
	using namespace math;

	Window window("Shade!", 1280, 720);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* s2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new Sprite(x, y, 0.09f, 0.09f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, vec4(1, 0, 1, 1)));


	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);

		shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));
		shader2.enable();
		shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));

		layer.render();
		layer2.render();

		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0) {
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}