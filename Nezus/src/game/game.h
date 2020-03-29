#include <Windows.h>
#include "entity.h"
#include "player.h"
#include "spellsdatabase.h"
#include "..\math\math.h"
#include "..\graphics\layers\tilelayer.h"
#include "..\graphics\sprite.h"
#include "..\graphics\layers\group.h"
#include "..\graphics\layers\layer.h"
#include "..\graphics\window.h"
#include <time.h>
#include "..\graphics\label.h"
#include "level.h"

namespace nezus {
	namespace graphics {
	
		class Game {
		private:
			Shader& m_Shader;
			Shader& m_Shader2;
			Window& m_Window;
			std::vector<Entity*> m_Entities;
			Group* m_MapGroup;
			Level* m_Level;
			Texture* m_MapTile = new Texture("w.png");
			Timer m_Time;
			TileLayer m_Map = TileLayer(&m_Shader);
			Texture* m_Texture;
			Player* m_Player1;
			SpellsDatabase* m_SpellsDatabase = new SpellsDatabase();
			float tf = 0;
			int m_MapWidth = 50;
			int m_MapHeight = m_MapWidth; //2
		public:
			Game(Shader* shader,Shader* shader2, Window* window, Texture* texture)
				:m_Shader(*shader),m_Shader2(*shader2),m_Window(*window),m_Texture(texture)
			{
				m_MapGroup = new Group(math::mat4::translation(math::vec3(0.0f, 0.0f, 0.0f)));
				for (int i = 0; i < m_MapHeight; i++)
				{
					for (int j = 0; j < m_MapWidth; j++)
					{
					
						m_MapGroup->add(new Sprite((float)j*2, (float)i*2 ,2.0f, 2.0f, m_MapTile));
						
					}
				}
				Spell newSpell1 = m_SpellsDatabase->getSpell(0);
				m_Map.add(m_MapGroup);
				m_Player1 = new Player("Mastuh", 8.0f, 4.0f, &m_Window, &m_Shader, &m_Shader2, m_SpellsDatabase);

				m_Entities.push_back(m_Player1);
				m_Level = new Level(&m_Entities);
				m_Player1->getLevel(m_Level);
				m_Player1->getMap(m_MapGroup);
				m_Level->updateEntities(&m_Entities);
			}

			void moveMap(TileLayer* m_TileLayer, int dx, int dy);
			void update();
			void draw();
			//void addplayer();
		private:
		


		};

	}
}
