#include "window.h"

namespace nezus
{
	namespace graphics
	{
		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();
			
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
			glfwSetWindowSizeCallback(m_Window, windowResize);

			if (glewInit() != GLEW_OK)
			{
				std::cout << "could not initialize GLEW!" << std::endl;
				return false;
			}
			std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;
			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() 
		{
			glfwPollEvents();
			
			glfwSwapBuffers(m_Window);
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}
		
		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);

		}

	}
}