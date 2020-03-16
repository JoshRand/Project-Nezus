#include "group.h"

namespace nezus {
	namespace graphics {
		Group::Group(const math::mat4& transform)
			: m_TransformationMatrix(transform)
		{
			
		}

		Group::~Group()
		{
			for (int i = 0; i < m_Renderables.size(); i++)
			{
				delete m_Renderables[i];
			}
		}

		std::vector<Renderable2D*> Group::getRenderables() const
		{
			return  m_Renderables;
		}

		void Group::submit(Renderer2D* renderer) const
		{
			renderer->push(m_TransformationMatrix);
			for (const Renderable2D* renderable : m_Renderables)
				renderable->submit(renderer);


			renderer->pop();
		}

		void Group::add(Renderable2D* renderable)
		{
			m_Renderables.push_back(renderable);
		}

} }