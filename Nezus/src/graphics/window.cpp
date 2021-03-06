#include "window.h"

namespace nezus
{
	namespace graphics
	{
		void window_resize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		
		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}

		}
		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "GLFW DID NOT INITIALIZE" << std::endl;
				return false;

			}
			else
			{
				std::cout << "GLFW INITIALIZED" << std::endl;

			}
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "failed to create window" << std::endl;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetFramebufferSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			glfwSwapInterval(0);
			if (glewInit() != GLEW_OK)
			{
				std::cout << "could not initialize GLEW!" << std::endl;
				return false;
			}
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;
			return true;
		}
		bool Window::isKeyPressed(unsigned int keycode) const
		{
			//TODO: Log something
			if (keycode >= MAX_KEYS)
				return false;

			return m_Keys[keycode];
		}
		void Window::getMousePosition(double& x, double& y) const 
		{
			x = mx;
			y = my;
		}
		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			//TODO: Log something
			if (button >= MAX_BUTTONS)
				return false;

			return m_MouseButtons[button];
		}
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() 
		{
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGL error " << error << std::endl;


			glfwPollEvents();
			
			glfwSwapBuffers(m_Window);
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		GLFWwindow* Window::getGLFWwindow() const
		{

			return m_Window;
		}

		void window_resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Width = width;
			win->m_Height = height;

		}
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_PRESS;
		}
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}