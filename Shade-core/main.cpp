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

#include <time.h>

#define BATCH_RENDERER 1

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
	std::vector<Renderable2D*> sprites;
	srand(time(NULL));

	for (float y = 0; y < 16.0f; y+=0.023f) {
		for (float x = 0; x < 16.0f; x+=0.023f) {
			sprites.push_back(new 
#if BATCH_RENDERER
				Sprite
#else
				StaticSprite
#endif
				(x, y, 0.015f, 0.015f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)
#if !BATCH_RENDERER
				, shader
#endif
			));
		}
	}

#if BATCH_RENDERER
	Sprite sprite1(0, 0, 4, 4, math::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 5, 4, math::vec4(0, 1, 1, 1));
	Sprite sprite3(1, 3, 4, 3, math::vec4(1, 1, 0, 1));
	BatchRenderer2D renderer;


#else 
	StaticSprite sprite1(0, 0, 4, 4, math::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 1, 5, 4, math::vec4(0, 1, 1, 1), shader);
	StaticSprite sprite3(1, 3, 4, 3, math::vec4(1, 1, 0, 1), shader);
	Simple2DRenderer renderer;

#endif

	shader.setUniform4f("col", vec4(0.0f, 0.8f, 0.2f, 1.0f));
	
	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	printf("Sprites: %d\n", sprites.size());


	while (!window.closed()) {
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));

#if BATCH_RENDERER
		renderer.begin();
#endif		
		for (int i = 0; i < sprites.size(); i++) {
			renderer.submit(sprites[i]);
		}
#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();
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