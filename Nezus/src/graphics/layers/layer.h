#pragma once
#include "../renderable2d.h"
#include "../renderer2d.h"




namespace nezus { namespace graphics {
	
	class Layer
	{
	protected:
		Renderer2D* m_Renderer;
		std::vector<Renderable2D*> m_Renderables;
		Shader* m_Shader;
		//Usually has view matrix/cameras.
		math::mat4 m_ProjectionMatrix;
	protected:
		Layer(Renderer2D* renderer, Shader* shader, math::mat4 projectionMatrix);	
	public:
		virtual ~Layer();
		virtual std::vector<Renderable2D*> getRenderables() const;
		virtual void add(Renderable2D* renderable);
		virtual void render();
	};

} }