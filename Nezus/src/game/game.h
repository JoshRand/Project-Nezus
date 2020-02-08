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

			
		public:
			Entity player1 = Entity("castuh", math::vec2(0.0f, 0.0f));
			Shader& m_Shader;
			TileLayer map = TileLayer(&m_Shader);
			TileLayer player = TileLayer(&m_Shader);
			Window& m_Window;
			Game(Shader& shader, Window& window)
				:m_Shader(shader),m_Window(window)
			{
				
				
				
				map.add(new Sprite(6.0f, 2.0f, 5.0f, 5.0f, math::vec4(0.4f, 0.5f, 1.0f, 1.0f)));
				
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
