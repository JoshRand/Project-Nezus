#include "player.h"
namespace nezus{ namespace graphics{

	Player::Player(std::string name, math::vec3 position, Window* window, Shader* shader, Shader* pshader)//, Timer &time)
		:m_Window(*window), m_Shader(*shader), m_Shader2(*pshader)//, m_Time(time)
	{
		
		m_Name = name;
		m_Position = position;
		m_PlayerGroup = new Group(math::mat4::translation(math::vec3(m_Position.x, m_Position.y, 0.0f)));
		m_PlayerSprite = new Sprite(m_Position.x, m_Position.y, 2.0f, 2.0f, m_PlayerTexture);
		m_PlayerLabel = new Label(m_Name, m_Position.x - 0.5f , m_Position.y + 2.2f, math::vec4(1, 1, 1, 1));
		m_PlayerGroup->add(m_PlayerSprite);
		m_PlayerGroup->add(m_PlayerLabel);
		m_PlayerTLayer.add(m_PlayerGroup);
	}

	void Player::Update()
	{
		double x, y;
		m_Window.getMousePosition(x, y);

		if (m_Time.elapsed() - tf > 0.01f)
		{

			int state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_RIGHT);
			if (state == GLFW_PRESS)
			{

				m_Position.x += getSpeed();

			}

			state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_LEFT);
			if (state == GLFW_PRESS)
			{
				m_Position.x -= getSpeed();
			}
			state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_UP);
			if (state == GLFW_PRESS)
			{
				m_Position.y += getSpeed();
			}
			state = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_DOWN);
			if (state == GLFW_PRESS)
			{
				m_Position.y -= getSpeed();
			}

			if (m_Position.x > 15.0f)
			{
				m_Position.x = 15.0f;
			}
			else if (m_Position.x < -16.0f)
			{
				m_Position.x = -16.0f;
			}
			if (m_Position.y > 8.0f)
			{
				m_Position.y = 8.0f;
			}
			else if (m_Position.y < -9.0f)
			{
				m_Position.y = -9.0f;
			}
			tf += 0.01f;
			m_Shader.setUniform2f("light_pos", math::vec2((m_Position.x + 1.0f), m_Position.y + 0.3f));
			Entity::moveGroup(m_PlayerGroup, m_Position.x, m_Position.y);

		}
	}
	void Player::render()
	{
		m_PlayerTLayer.render();
	}
	

}}