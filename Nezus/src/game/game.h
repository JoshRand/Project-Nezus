#include <Windows.h>
#include "entity.h"
#include "player.h"
#include "..\math\math.h"
#include "..\graphics\layers\tilelayer.h"
#include "..\graphics\sprite.h"
#include "..\graphics\layers\group.h"
#include "..\graphics\layers\layer.h"
#include "..\graphics\window.h"
#include <time.h>
#include "..\graphics\label.h"
//#include "..\utils\timer.h"
//#include "..\graphics\layers\layer.h"
//#include "..\graphics\renderable2d.h"
//#include "..\graphics\renderer2d.h"
//#include "..\graphics\shader.h"
namespace nezus {
	namespace graphics {
	
		class Game {
		private:
			Shader& m_Shader;
			Shader& m_Shader2;
			Window& m_Window;
			//Timer m_Time;
			TileLayer m_Map = TileLayer(&m_Shader2);
			Texture* m_Texture;
			Player* m_Player1;
			float tf = 0;
		public:
			Game(Shader* shader,Shader* shader2, Window* window, Texture* texture)
				:m_Shader(*shader),m_Shader2(*shader2),m_Window(*window),m_Texture(texture)
			{
				m_Player1 = new Player("castuh", math::vec3(0.0f, 0.0f, 0.0f), &m_Window, &m_Shader, &m_Shader2);//, m_Time);
				
			
			}

			void moveGroup(Group* m_group, float dx, float dy);
			void update();
			void draw();
			//void addplayer();
		private:
		


		};

	}
}
