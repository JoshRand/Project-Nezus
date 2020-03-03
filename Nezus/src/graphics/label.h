#pragma once

#include "renderable2d.h"


namespace nezus {namespace graphics {

	class Label : public Renderable2D
	{

	public:
		std::string text;
		float x, y;
		math::vec3& position;
		//math::vec4 m_Color;
	public:
		Label(std::string text, float x, float y, math::vec4 color);
		void submit(Renderer2D* renderer) const override;
	


	};


} }