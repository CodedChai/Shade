#pragma once

#include <vector>
#include <GL\glew.h>
#include "../math/math.h"

namespace shade {
	namespace graphics {
		class Renderable2D;
		class Renderer2D {
		protected:
			std::vector<math::mat4> m_TransformationStack;
			const math::mat4* m_TransformationBack;
		protected:
			Renderer2D() {
				m_TransformationStack.push_back(math::mat4::identity());
				m_TransformationBack = &m_TransformationStack.back();
			}
		public:
			void push(const math::mat4& matrix, bool override = false)
			{
				if (override) {
					m_TransformationStack.push_back(matrix);
				}
				else {
					m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
				}
				m_TransformationBack = &m_TransformationStack.back();

			}

			void pop()
			{
				// TODO: Add to log!
				if(m_TransformationStack.size() > 1)
					m_TransformationStack.pop_back();

				m_TransformationBack = &m_TransformationStack.back();
			}

			virtual void begin() {}
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void end() {}
			virtual void flush() = 0;
		};

} }