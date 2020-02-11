#include <Windows.h>
#include "entity.h"
#include "player.h"
#include "..\graphics\layers\tilelayer.h"
#include "..\graphics\sprite.h"
#include "..\graphics\layers\group.h"
#include "..\graphics\window.h"
//#include "..\graphics\layers\layer.h"
//#include "..\graphics\renderable2d.h"
//#include "..\graphics\renderer2d.h"
//#include "..\graphics\shader.h"
namespace nezus {
	namespace graphics {
	
		class Game {

			
		private:
			Entity m_Player1 = Entity("castuh", math::vec2(0.0f, 0.0f));
			Shader& m_Shader;
			TileLayer m_Map = TileLayer(&m_Shader);
			TileLayer m_PlayerLayer = TileLayer(&m_Shader);
			Window& m_Window;
			Texture* m_Texture;
		public:
			Game(Shader* shader, Window* window, Texture* texture)
				:m_Shader(*shader),m_Window(*window),m_Texture(texture)
			{
				
				m_Map.add(new Sprite(6.0f, 2.0f, 5.0f, 5.0f, math::vec4(0.4f, 0.5f, 1.0f, 1.0f)));
				m_PlayerLayer.add(new Sprite(m_Player1.Getx(), m_Player1.Gety(), 1.0f, 1.0f, m_Texture));
				//TileLayer players(&m_Shader);
				//TileLayer walls(&m_Shader);
				//TileLayer spells(&m_Shader);

				//Entity P1();
				//Entity Play2(name, math::vec2(2.0f, 2.0f));
			}
			
			void update();
			void draw();
			//void addplayer();
		private:
		


		};

	}
}
