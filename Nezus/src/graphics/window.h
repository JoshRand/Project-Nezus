#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace nezus
{
	namespace graphics
	{
#define MAX_KEYS  1024
#define MAX_BUTTONS  32
		class Window
		{
		public:
			static Window* INSTANCE;
		private:
			friend struct GLFWwindow;

			int m_Width, m_Height;
			const char* m_Title;
			GLFWwindow* m_Window;
			bool m_Closed;
			bool m_MouseButtons[MAX_BUTTONS];
			bool m_Keys[MAX_KEYS];
			double mx, my;	
		public:
			Window(const char* name, int width, int height);
			~Window();
			void update();
			bool closed() const;
			void clear() const;
			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			GLFWwindow* getGLFWwindow() const;

			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int keycode) const;
			void getMousePosition(double& x, double& y) const;
		private:
			bool init();
			friend static void window_resize(GLFWwindow* window, int width, int height);
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
			
		};
	}
}