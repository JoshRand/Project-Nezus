#include "entity.h"
namespace nezus
{
	Entity::Entity(std::string name, math::vec2 position)
		:m_Name(name), m_Position(position)
	{

	}
	Entity::Entity() 
	{
		m_Position = math::vec2(0.0f, 0.0f);
	}
	float& Entity::Getx()
	{
		return  m_Position.x;
	}
	float& Entity::Gety()
	{
		return  m_Position.y;
	}
	void Entity::Setx(double x)
	{
		m_PosPrevX = m_Position.x;
		m_Position.x = x;
		if ((int)m_PosPrevX != (int)m_Position.x)
		{
			m_PositionChange = true;
		}
		
	}
	void Entity::Sety(double y)
	{
		m_PosPrevY = m_Position.y;
		m_Position.y = y;
		if ((int)m_PosPrevY != (int)m_Position.y)
		{
			m_PositionChange = true;
		}
	}
	bool Entity::PositionChange()
	{
		return m_PositionChange;
	}
}