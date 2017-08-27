#pragma once

#include "renderable2d.h"

namespace shade {
	namespace graphics {
		class Sprite : public Renderable2D {
		private:

		public:
			Sprite(float x, float y, float width, float height, math::vec4& color);
		};
} }