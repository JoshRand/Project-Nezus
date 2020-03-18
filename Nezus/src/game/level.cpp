#pragma once
#include "level.h"


namespace nezus {
	namespace graphics
	{
		Level::Level(std::vector<Entity*>* entities)
			
		{
			m_Entities = *entities;
		}
		Level::Level()
		{

		}
		void Level::updateEntities(std::vector<Entity*>* entities)
		{
			m_Entities = *entities;
		}
		//Places entities from game on board slot 0 at designated entity locations
		void Level::placeEntitiesOnLevel()
		{
			if (!m_Entities.empty())
			{
				for (int i = 0; i < m_Entities.size(); i++)
				{
					if (!m_EntityArray[m_Entities[i]->getX()][m_Entities[i]->getY()][0].isOccupied())
					{
						m_EntityArray[m_Entities[i]->getX()][m_Entities[i]->getY()][0] = *m_Entities[i];
						m_EntityArray[m_Entities[i]->getX()][m_Entities[i]->getY()][0].setOccupied();
					}
					
				}
			}
			
		}

		bool Level::peekRight(int curx, int cury)
		{
			if (!m_EntityArray[curx + 1][cury][0].isOccupied())
			{
				m_EntityArray[curx][cury][0] = Entity();
				return m_EntityArray[curx + 1][cury][0].isOccupied();
				//m_EntityArray[m_Entities[curx]->getX()][m_Entities[cury]->getY()][0] = *m_Entities[i];
				//m_EntityArray[m_Entities[curx]->getX()][m_Entities[cury]->getY()][0].setOccupied();
			}

		}

	//	bool Level::peekLeft(int curx, int cury)
	//	{
	//
	//	}
	//	
	//	bool Level::peekUp(int curx, int cury)
	//	{
	//
	//	}
	//
	//	bool Level::peekDown(int curx, int cury)
	//	{
	//
	//	}
		
		//void Level::DrawLevel()
		//{
		//	for (int i = 0; i < m_Entities.size(); i++)
		//	{
		//		m_Entities[i]->moveGroup(m_Entities[i].get, m_Entities[i]->getX(), m_Entities[i]->getY());
		//	}
		//
		//}

	}
}