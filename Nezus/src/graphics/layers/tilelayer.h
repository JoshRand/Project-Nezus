#pragma once
#include "layer.h"
namespace nezus { namespace graphics {

	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};


} }