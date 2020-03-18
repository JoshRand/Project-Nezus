#include "player.h"

namespace nezus{ namespace graphics{

	Player::Player(std::string name, int posx, int posy, Window* window, Shader* shader, Shader* pshader)//, Level** level)
		:m_Window(*window), m_Shader(*shader), m_Shader2(*pshader)//,m_Level(*level)
	{
		
		m_Name = name;
		m_PositionX = posx;
		m_PositionY = posy;
		m_PlayerGroup = new Group(math::mat4::translation(math::vec3((float)m_PositionX, (float)m_PositionY, 0.0f)));
		m_PlayerSprite = new Sprite((float)m_PositionX, (float)m_PositionY, 2.0f, 2.0f, m_PlayerTexture);
		m_PlayerLabel = new Label(m_Name, (float)m_PositionX - 0.5f , (float)m_PositionY + 2.2f, math::vec4(1, 1, 1, 1));
		m_PlayerGroup->add(m_PlayerSprite);
		m_PlayerGroup->add(m_PlayerLabel);
		m_PlayerTLayer.add(m_PlayerGroup);
		
	}

	void Player::getLevel(Level* level)
	{
		m_Level = level;
	}

	Group* Player::getGroup()
	{
		return m_PlayerGroup;
	}

	void Player::Update()
	{
		double x, y;
		m_Window.getMousePosition(x, y);
		
		if (m_Time.elapsed() - tf > 0.4f)
		{

			int state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_RIGHT);
			if (state == GLFW_PRESS)
			{


				// CANT READ MEMORY 
				if (!m_Level->peekRight(m_PositionX,m_PositionY))
				{
					m_PositionX+=1;//+= getSpeed();
					//m_PosChangeX = 1;
				}
			
			}
			
				
			//state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_LEFT);
			//if (state == GLFW_PRESS)
			//{
			//	if (!m_Level->peekLeft(m_PositionX, m_PositionY))
			//	{
			//		m_PositionX -= 1;
			//		m_PosChangeX = -1;
			//		Entity::moveGroup(m_PlayerGroup, m_PositionX + m_PosChangeX, m_PositionY);
			//	}
			//}
			//state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_UP);
			//if (state == GLFW_PRESS)
			//{
			//	m_Position.y += getSpeed();
			//}
			//state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_DOWN);
			//if (state == GLFW_PRESS)
			//{
			//	m_Position.y -= getSpeed();
			//}
			//
			//if (m_Position.x > 15.0f)
			//{
			//	m_Position.x = 15.0f;
			//}
			//else if (m_Position.x < -16.0f)
			//{
			//	m_Position.x = -16.0f;
			//}
			//if (m_Position.y > 8.0f)
			//{
			//	m_Position.y = 8.0f;
			//}
			//else if (m_Position.y < -9.0f)
			//{
			//	m_Position.y = -9.0f;
			//}
			tf += 0.4f;
			//m_Shader.setUniform2f("light_pos", math::vec2((m_Position.x + 1.0f), m_Position.y + 0.3f));
			Entity::moveGroup(m_PlayerGroup, m_PositionX*2, m_PositionY*2);

		}
	}
	void Player::render()
	{
		m_PlayerTLayer.render();
	}
	

}}