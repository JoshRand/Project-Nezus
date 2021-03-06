#pragma once
#include "renderable2d.h"
namespace nezus {
	namespace graphics {
		
		class Sprite : public Renderable2D
		{
		private:

		public:
			Sprite(float x, float y, float width, float height, const math::vec4& color);
			Sprite(float x, float y, float width, float height, Texture* texture);
			void setTexture(Texture* texture);
			void setSize(float width, float height);
			

		};

	}
}