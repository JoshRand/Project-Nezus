#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"

#include "renderer2d.h"

#include "../math/math.h"
#include "shader.h"

namespace nezus {
	namespace graphics {

		struct VertexData
		{
			math::vec3 vertex;
			math::vec2 uv;
			unsigned int color;
		};

		class Renderable2D
		{
		protected:
			math::vec3 m_Position;
			math::vec2 m_Size;
			math::vec4 m_Color;
			std::vector<math::vec2> m_UV;
		protected:
			Renderable2D() 
			{setUVDefaults();}
		public:
			Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color)
				: m_Position(position), m_Size(size), m_Color(color)
			{ setUVDefaults();}

			virtual ~Renderable2D() { }

			virtual void submit(Renderer2D* renderer) const
			{
				renderer->submit(this);
			}

			inline const math::vec3& getPosition() const { return m_Position; }
			inline const math::vec2& getSize() const { return m_Size; }
			inline const math::vec4& getColor() const { return m_Color; }
			inline const std::vector<math::vec2>& getUV() const { return m_UV; }
		private:
			void setUVDefaults()
			{
				m_UV.push_back(math::vec2(0, 0));
				m_UV.push_back(math::vec2(0, 1));
				m_UV.push_back(math::vec2(1, 1));
				m_UV.push_back(math::vec2(1, 0));
			}
		};

	}
}