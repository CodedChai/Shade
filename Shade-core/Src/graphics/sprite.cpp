#include "sprite.h"

namespace shade {
	namespace graphics {
		Sprite::Sprite(float x, float y, float width, float height, math::vec4& color) 
			: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), color)
		{

		}
} }