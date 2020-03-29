#include "player.h"


namespace nezus{ namespace graphics{

	Player::Player(std::string name, int posx, int posy, Window* window, Shader* shader, Shader* pshader, SpellsDatabase* spelldata)//, Level** level)
		:m_Window(*window), m_Shader(*shader), m_Shader2(*pshader), m_Spelldatabase(*spelldata)//,m_Level(*level)
	{
		
		m_Name = name;
		m_PlayerHp = m_PlayerHpMax;
		m_PositionX = posx;
		m_PositionY = posy;
		m_PlayerGroup = new Group(math::mat4::translation(math::vec3(1.0f,0.0f,0.0f)));//math::vec3((float)m_PositionX, (float)m_PositionY, 0.0f)));
		m_PlayerSprite = new Sprite(0.0f, 0.0f, 2.0f, 2.0f, m_PlayerTextureDown);
		m_PlayerHealthBarGreen = new Sprite(-0.5f, 3.0f, 1.0f, 0.4f, math::vec4(0.0f, 1.0f, 0.2f, 0.5f));
		m_PlayerHealthBarRed = new Sprite(-0.5f, 3.0f, 3.0f, 0.4f, math::vec4(1.0f, 0.0f, 0.2f, 0.5f));
		m_PlayerHealthBarGreen->setSize(3 * (m_PlayerHp / m_PlayerHpMax ), 0.4f);
		m_PlayerLabel = new Label(m_Name, - 0.5f ,  2.2f, math::vec4(1, 1, 1, 1));
		m_PlayerGroup->add(m_PlayerSprite);
		m_PlayerGroup->add(m_PlayerLabel);
		m_PlayerGroup->add(m_PlayerHealthBarRed);
		m_PlayerGroup->add(m_PlayerHealthBarGreen);
		m_PlayerTLayer.add(m_PlayerGroup);
		//m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(m_PositionX * 2 - 16.0f, 16.0f + m_PositionX * 2, m_PositionY * 2 - 9.0f, 9.0f + m_PositionY * 2, -1.0f, 1.0f));
		m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(m_PositionX * 2 - 16.0f, 16.0f + m_PositionX * 2, m_PositionY * 2 - 9.5f, 10.5f + m_PositionY * 2, -1.0f, 1.0f));
		m_Shader.setUniform2f("light_pos", math::vec2(m_PositionX * 2 + 2.0f, m_PositionY * 2 + 1.3f));
		m_APositionX = (float)m_PositionX;
		m_APositionY = (float)m_PositionY;
		newspell1 = m_Spelldatabase.getSpell(0);
	}

	void Player::getLevel(Level* level)
	{
		m_Level = level;
	}

	Group* Player::getGroup()
	{
		return m_PlayerGroup;
	}

	void Player::getMap(Group* map_group)
	{
		m_MapGroup = map_group;

	}

	void Player::Update()
	{
		std::vector < graphics::Renderable2D* > groupmembers = m_PlayerGroup->getRenderables();
		double x, y;
		m_Window.getMousePosition(x, y);
		float deltax = 0.0f;
		float deltay = 0.0f;
		int keystateright = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_RIGHT);
		int keystateleft = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_LEFT);
		int keystateup = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_UP);
		int keystatedown = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_DOWN);
		int keystate1 = glfwGetKey(m_Window.getGLFWwindow(), GLFW_KEY_1);
		if (!m_Walking)
		{
			if (keystateright == GLFW_PRESS)
			{
				m_PlayerState = FacingRight;
				//m_PlayerTexture = new Texture("bright.png");
				m_PlayerSprite->setTexture(m_PlayerRightTexture);
				
				//change facing position
				
				if (m_WalkTimer.elapsed() > 0.3f)
				{
					if (!m_Level->peekRight(m_PositionX, m_PositionY))
					{
						m_PosPrevX = m_PositionX;
						m_PositionX += 1;
						m_APositionX = m_PositionX;
						m_Walking = true;
					}
				}
			}
			else if (keystateleft == GLFW_PRESS)
			{	
				m_PlayerState = FacingLeft;
				//change facing position
				m_PlayerSprite->setTexture(m_PlayerLeftTexture);
				if (m_WalkTimer.elapsed()  > 0.3f)
				{	
					if (!m_Level->peekLeft(m_PositionX, m_PositionY))
					{
						m_PosPrevX = m_PositionX;
						m_PositionX -= 1;
						m_APositionX = m_PositionX;
						m_Walking = true;
					
					}
					
				}

			}
			else if (keystateup == GLFW_PRESS)
			{
				m_PlayerState = FacingUp;
				//change facing position
				m_PlayerSprite->setTexture(m_PlayerUpTexture);
				if (m_WalkTimer.elapsed() > 0.3f)
				{
					if (!m_Level->peekUp(m_PositionX, m_PositionY))
					{
						m_PosPrevY = m_PositionY;
						m_PositionY += 1;
						m_APositionY = m_PositionY;
						m_Walking = true;

					}
				}
			}
			else if (keystatedown == GLFW_PRESS)
			{
				m_PlayerState = FacingDown;
				//change facing position
				m_PlayerSprite->setTexture(m_PlayerTextureDown);
				if (m_WalkTimer.elapsed() > 0.3f)
				{
					if (!m_Level->peekDown(m_PositionX, m_PositionY))
					{
						m_PosPrevY = m_PositionY;
						m_PositionY -= 1;
						m_APositionY = m_PositionY;
						m_Walking = true;
					}
				}
			}
			else
			{
				m_InitialWalkTimer = 0;
				m_WalkTimer.reset();
			}
		}
		if (m_Walking)
		{
			switch (m_PlayerState)
			{
				case FacingRight:
					movePlayer(m_PosPrevX + 0.002f, m_APositionY);
					m_PosPrevX += 0.002f;
					m_MoveCounter++;
					break;
				case FacingLeft:
					movePlayer(m_PosPrevX - 0.002f, m_APositionY);
					m_PosPrevX -= 0.002f;
					m_MoveCounter++;
					break;
				case FacingUp:
					movePlayer(m_APositionX, m_PosPrevY + 0.002f);
					m_PosPrevY += 0.002f;
					m_MoveCounter++;
					break;
				case FacingDown:
					movePlayer(m_APositionX, m_PosPrevY - 0.002f);
					m_PosPrevY -= 0.002f;
					m_MoveCounter++;
					break;
				default:
					break;
			}
		}
		
			
		if (m_MoveCounter == 500)
		{
			m_PlayerState = Idle;
			m_APositionX = m_PositionX;
			m_APositionY = m_PositionY;
			m_Walking = false;
			m_MoveCounter = 0;
			std::cout << "X = " << m_PositionX << " Y = " << m_PositionY << std::endl;
		}
		if (m_Time.elapsed() > 0.005)
		{

			m_PlayerHealthBarGreen->setSize(3 * ( (float)m_PlayerHp / (float)m_PlayerHpMax), 0.4f);
			m_Time.reset();
		}
		
		if (m_SpellTimer.elapsed() > 0.1f)
		{
			if (keystate1)
			{
				
				m_PlayerHp += newspell1.m_Properties["m_HpGiven"];
				std::cout << "HP given from soothe =" <<newspell1.m_Properties["m_HpGiven"] << std::endl;
				if (m_PlayerHp > m_PlayerHpMax)
				{
					m_PlayerHp = m_PlayerHpMax;
				}
			}
			m_SpellTimer.reset();
		}

		if (m_PoisonTimer.elapsed() > 1.0f)
		{
			if (m_PlayerHp != 0)
			{
				m_PlayerHp--;
			}
			
			m_PoisonTimer.reset();
		}
	}

	void Player::movePlayer(float px, float py)
	{
		if (py <= 4 && px >=  8)
		{
			Entity::moveGroup(m_PlayerGroup, 0, py * 2 - 8.0f);
			m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(px * 2 - 16.0f, 16.0f + px * 2, -0.0f, +18.0f, -1.0f, 1.0f));

			m_Shader.setUniform2f("light_pos", math::vec2(px * 2 + 2.0f, py * 2 + 1.3f));

		}
		else if (py >= 4 && px <= 8)
		{
			Entity::moveGroup(m_PlayerGroup, px * 2 - 16.0f, 0);
			m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(-0.0f, 32.0f, py * 2 - 8.0f, py * 2 + 10.0f, -1.0f, 1.0f));
			m_Shader.setUniform2f("light_pos", math::vec2(px * 2 + 2.0f, py * 2 + 1.3f));
		
		
		
		}
		else if (py <= 4 && px <= 8)
		{
			Entity::moveGroup(m_PlayerGroup, px * 2 - 16.0f, py * 2 - 8.0f);
			//m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(px * 2 - 16.0f, 16.0f + px * 2, - 9.0f, 9.0f , -1.0f, 1.0f));
			m_Shader.setUniform2f("light_pos", math::vec2(px * 2 + 2.0f, py * 2 + 1.3f));



		}
		else if (py >= 4 && px >= 8)
		{
			m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(px * 2 - 16.0f, 16.0f + px * 2, py * 2 - 8.0f, 10.0f + py * 2, -1.0f, 1.0f));

			//m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(px * 2 - 16.0f, 16.0f + px * 2, py * 2 - 9.0f, 9.0f + py * 2, -1.0f, 1.0f));
			m_Shader.setUniform2f("light_pos", math::vec2(px * 2 + 2.0f, py * 2 + 1.3f));

		}
		else
		{
			m_Shader.setUniformMat4("pr_matrix", math::mat4::orthographic(px * 2 - 16.0f, 16.0f + px * 2, py * 2 - 9.5f, 10.5f + py * 2, -1.0f, 1.0f));
			m_Shader.setUniform2f("light_pos", math::vec2(px * 2 + 2.0f, py * 2 + 1.3f));

		}
	}

	void Player::moveMap(Group* group, int dx, int dy)
	{
		int j = 0;
		std::vector < graphics::Renderable2D* > groupmembers = group->getRenderables();
		for (int i = 0; i < groupmembers.size(); i++)
		{

			groupmembers[i]->setPosition(  dx ,  dy);


		}
	}

	void Player::render()
	{
		m_PlayerTLayer.render();
	}
	

}}