#include "layer.h"


namespace nezus { namespace graphics {
		
	Layer::Layer(Renderer2D* renderer, Shader* shader, math::mat4 projectionMatrix)
		: m_Renderer(renderer), m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
	{
		m_Shader->enable();
		m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix );
		m_Shader->disable();
	}

	Layer::~Layer()
	{
		delete m_Shader;
		delete m_Renderer;

		for (int i = 0; i < m_Renderables.size(); i++)
		{
			delete m_Renderables[i];
		}

	}

	std::vector<Renderable2D*> Layer::getRenderables() const
	{
		return  m_Renderables;
	}

	void Layer::add(Renderable2D* renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Layer::render()
	{

		m_Shader->enable();
		m_Renderer->begin();
		int i = 0;
		for (const Renderable2D* renderable : m_Renderables)
			renderable->submit(m_Renderer);
		
		//m_Renderer->drawString("Hello!", math::vec3(0, 0, 0), math::vec4(0, 0, 0, 1));
		m_Renderer->end();
		//m_Renderer->pop();
		m_Renderer->flush();
		//if disabled shader - OpenGL error 1282  (invalid operator?)
		//m_Shader->disable();
	}
} }