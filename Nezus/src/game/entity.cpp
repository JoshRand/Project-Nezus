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
	float Entity::Getx()
	{
		return  m_Position.x;
	}
	float Entity::Gety()
	{
		return  m_Position.y;
	}
	void Entity::Setx(double x)
	{
		m_Position.x = x;
	}
	void Entity::Sety(double y)
	{
		m_Position.y = y;
	}
}