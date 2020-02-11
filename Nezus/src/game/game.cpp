#include "game.h"
namespace nezus {
	namespace graphics {

		void Game::update()
		{
			double x, y;
			
			m_Window.getMousePosition(x, y);
			m_Player1.Setx((x * 32.0f / (float)540 - 16.0f));
			m_Player1.Sety(9.0f - y * 18.0f / (float)960);

		}

		void Game::draw()
		{
			
			//draw tilemap
			//draw character
			//draw walls
			//draw spells
			
			//player.add(new Sprite(player1.Getx(), player1.Gety(), 1.0f, 1.0f, math::vec4(0.4f, 0.5f, 1.0f, 1.0f)));
			if (m_Player1.PositionChange())
			{
				
			}
			m_Map.render();
			m_PlayerLayer.render();
		}
	}
}