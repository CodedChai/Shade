#pragma once

#include <GL\glew.h>
#include <vector>
#include <iostream>
#include "..\utils\fileutils.h"

namespace shade {
	namespace graphics {
		class Shader {
		private:
			GLuint m_ShaderID;
			const char* m_VertPath;
			const char* m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;

		private:
			GLuint load();
		};
} }