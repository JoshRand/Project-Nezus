#include "game.h"

namespace nezus {
	namespace graphics {

		void Game::update()
		{
			m_Player1->Update();
			m_Level->placeEntitiesOnLevel();
			m_Level->updateEntities(&m_Entities);
			
		}

		void Game::draw()
		{
			
			//draw tilemap
			//draw character
			//draw walls
			//draw spells
			

			//player.add(new Sprite(player1.getX(), player1.getY(), 1.0f, 1.0f, math::vec4(0.4f, 0.5f, 1.0f, 1.0f)));
			
			m_Map.render();
			m_Player1->render();
			//m_Player1TLayer.render();
		}

		void Game::moveMap(TileLayer* m_TileLayer, int dx, int dy)
		{
			int j = 0;
			std::vector < graphics::Renderable2D* > groupmembers = m_TileLayer->getRenderables();
			for (int i = 0; i < groupmembers.size(); i++)
			{
				
					groupmembers[i]->setPosition(dx + groupmembers[i]->getPosition().x, dy + groupmembers[i]->getPosition().y);

				
			}
		}



	}
}