#pragma once

#include "layer.h"
#include "..\batchrenderer2d.h"

namespace shade {
	namespace graphics {

		class TileLayer : public Layer
		{
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};

	}
}