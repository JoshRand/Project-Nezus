#include "entity.h"
namespace nezus
{
	Entity::Entity(std::string name, int posx, int posy)
		:m_Name(name), m_PositionX(posx), m_PositionY(posy)
	{

	}
	Entity::Entity()
	{

	}

	float Entity::getSpeed()
	{
		return m_Speed;
	}

	int& Entity::getX()
	{
		
		return  m_PositionX;
	}
	int& Entity::getY()
	{
		return  m_PositionY;
	}

	std::string& Entity::GetName()
	{
		return  m_Name;
	}

	void Entity::setX(int x)
	{
		m_PosPrevX = m_PositionX;
		m_PositionX = x;
		if ((int)m_PosPrevX != (int)m_PositionX)
		{
			m_PositionChange = true;
		}
		
	}
	void Entity::setY(int y)
	{
		m_PosPrevY = m_PositionY;
		m_PositionY = y;
		if ((int)m_PosPrevY != (int)m_PositionY)
		{
			m_PositionChange = true;
		}
	}

	bool Entity::isOccupied()
	{
		return m_Occupied;
	}

	void Entity::setOccupied()
	{
		m_Occupied = true;
	}

	void Entity::moveGroup(graphics::Group* m_group, int dx, int dy)
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