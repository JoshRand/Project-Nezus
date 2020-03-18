#pragma once
#include "entity.h"
#include <list>
#include <array>

namespace nezus { namespace graphics 
{
	
	class Level //: public Grid
	{
	private:
		static const int m_GridDimX = 50;
		static const int m_GridDimY = 50;
		static const int m_Depth = 50;
		int m_CellWidth = 1;
		int m_CellHeight = 1;
		std::vector<Entity*> m_Entities;
		Entity m_EntityArray[m_GridDimX][m_GridDimY][m_Depth];
		
	public:
		Level(std::vector<Entity*>*);
		Level();
		void placeEntitiesOnLevel();
		void updateEntities(std::vector<Entity*>* entities);
		bool peekRight(int curx, int cury);
		bool peekLeft(int curx, int cury);
		bool peekUp(int curx, int cury);
		bool peekDown(int curx, int cury);
		//void DrawLevel();





};


} }