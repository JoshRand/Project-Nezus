#pragma once
#include <deque>
#include "renderer2d.h"
#include "static_sprite.h"

namespace nezus { namespace graphics {

		class Simple2DRenderer : public Renderer2D
		{
		private:
			std::deque<const StaticSprite*> m_RenderQueue;
		public:
			void submit(const Renderable2D* renderable) override; //overrid?
			void flush() override;

		};

}}