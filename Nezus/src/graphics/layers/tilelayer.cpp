#include "../batchrenderer2d.h"
#include "tilelayer.h"


namespace nezus { namespace graphics{
	TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D, shader, math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, 0, 1))
	{
	
	}

	TileLayer::~TileLayer()
	{
	

	}



} }