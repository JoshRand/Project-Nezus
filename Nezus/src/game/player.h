#pragma once
#include <time.h>
#include "..\utils\timer.h"
#include "entity.h"
#include "level.h"

namespace nezus { namespace graphics {
	class Player : public Entity
	{
	private:
		Window& m_Window;
		Shader& m_Shader;
		Shader& m_Shader2;
		Level* m_Level;
		Sprite* m_PlayerSprite;
		Group* m_PlayerGroup;
		Label* m_PlayerLabel; 
		Timer m_Time;
		Texture* m_PlayerTexture = new Texture("b.png");
		TileLayer m_PlayerTLayer = TileLayer(&m_Shader2);
		float tf = 0;
	public:
		Player(std::string name, int posx, int posy, Window* window, Shader* shader, Shader* shader2);//, Level** level );
		//buffs/spells ect
		Group* getGroup();
		void getLevel(Level* level);
		void Update();
		void render();



	};


}}
