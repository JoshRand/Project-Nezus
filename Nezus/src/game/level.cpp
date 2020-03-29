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
			if (curx + 1 > m_GridDimX -1)
			{
				return true;
			}
			else if (!m_EntityArray[curx + 1][cury][0].isOccupied())
			{
				m_EntityArray[curx][cury][0] = Entity();
				return m_EntityArray[curx + 1][cury][0].isOccupied();
			}

		}

		bool Level::peekLeft(int curx, int cury)
		{
			if (curx - 1 < 0)
			{
				return true;
			} 
			else if (!m_EntityArray[curx - 1][cury][0].isOccupied())
			{
				m_EntityArray[curx][cury][0] = Entity();
				return m_EntityArray[curx - 1][cury][0].isOccupied();
			}

		}
		
		bool Level::peekUp(int curx, int cury)
		{
			if (cury + 1 > m_GridDimY -1)
			{
				return true;
			}
			else if (!m_EntityArray[curx][cury + 1][0].isOccupied())
			{
				m_EntityArray[curx][cury][0] = Entity();
				return m_EntityArray[curx][cury + 1][0].isOccupied();
				
			}
		}
	
	 	bool Level::peekDown(int curx, int cury)
	 	{
			if (cury - 1 < 0)
			{
				return true;
			}
			else if (!m_EntityArray[curx - 1][cury][0].isOccupied())
			{
				m_EntityArray[curx][cury][0] = Entity();
				return m_EntityArray[curx - 1][cury][0].isOccupied();
				
			}
	 	}
		

	}
}