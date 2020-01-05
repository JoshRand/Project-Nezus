#pragma once
#include <GL/glew.h>
#include "../math/math.h"
#include "renderable2d.h"


namespace nezus { namespace graphics {

	class Renderer2D
	{
	protected:
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;

	};

}}