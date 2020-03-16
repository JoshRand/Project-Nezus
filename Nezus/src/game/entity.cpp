#include "entity.h"
namespace nezus
{
	Entity::Entity(std::string name, math::vec3 position)
		:m_Name(name), m_Position(position)
	{

	}
	Entity::Entity() 
	{
		m_Position = math::vec3(0.0f, 0.0f,0.0f);
	}

	float Entity::getSpeed()
	{
		return m_Speed;
	}

	float& Entity::getX()
	{
		
		return  m_Position.x;
	}
	float& Entity::getY()
	{
		return  m_Position.y;
	}

	std::string& Entity::GetName()
	{
		return  m_Name;
	}

	void Entity::setX(double x)
	{
		m_PosPrevX = m_Position.x;
		m_Position.x = x;
		if ((int)m_PosPrevX != (int)m_Position.x)
		{
			m_PositionChange = true;
		}
		
	}
	void Entity::setY(double y)
	{
		m_PosPrevY = m_Position.y;
		m_Position.y = y;
		if ((int)m_PosPrevY != (int)m_Position.y)
		{
			m_PositionChange = true;
		}
	}

	void Entity::moveGroup(graphics::Group* m_group, float dx, float dy)
	{
		std::vector < graphics::Renderable2D* > groupmembers = m_group->getRenderables();
		groupmembers[0]->setPosition(dx, dy);
		groupmembers[1]->setPosition(dx - 0.5f, dy + 2.2f);
	}


	bool Entity::PositionChange()
	{
		return m_PositionChange;
	}
}