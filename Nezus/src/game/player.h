#pragma once
#include <time.h>
#include "..\utils\timer.h"
#include "entity.h"
#include "level.h"

namespace nezus { namespace graphics {
	enum PState
	{
		Idle,
		FacingRight,
		FacingLeft,
		FacingUp,
		FacingDown
	};

	class Player : public Entity
	{
	private:
		Window& m_Window;
		Shader& m_Shader;
		Shader& m_Shader2;
		Level* m_Level;
		Group* m_MapGroup;
		Sprite* m_PlayerSprite;
		Group* m_PlayerGroup;
		Label* m_PlayerLabel; 
		Timer m_Time;
		Timer m_WalkTimer;
		Sprite* m_PlayerHealthBarRed;
		Sprite* m_PlayerHealthBarGreen;
		Texture* m_PlayerTexture = new Texture("b.png");
		TileLayer m_PlayerTLayer = TileLayer(&m_Shader2);
		PState m_PlayerState = Idle;
		bool m_Walking = false;
		bool m_WalkingContinue = false;
		bool m_NextMoveEnable = false;
		int m_PlayerHP = 0;
		float m_InitialWalkTimer = 0;
		float tf = 0;
		float m_AnimationTime = 0;
		int m_MoveCounter = 0;
	public:
		Player(std::string name, int posx, int posy, Window* window, Shader* shader, Shader* shader2);//, Level** level );
		//buffs/spells ect
		Group* getGroup();
		void getMap(Group* map_group);
		void getLevel(Level* level);
		void movePlayer(float px, float py);
		void moveMap(Group* group, int dx, int dy);
		void Update();
		void render();



	};


}}
