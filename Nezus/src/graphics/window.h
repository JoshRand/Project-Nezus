#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace nezus
{
	namespace graphics
	{
		class Window
		{
		private:
			int m_Width, m_Height;
			const char* m_Title;
			GLFWwindow* m_Window;
			bool m_Closed;
		public:
			Window(const char* name, int width, int height);
			~Window();
			void update();
			bool closed() const;
			void clear() const;
			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

		private:
			bool init();
		};
	}
}