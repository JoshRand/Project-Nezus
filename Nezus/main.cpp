#include "src/graphics/window.h"

int main()
{
	using namespace nezus;
	using namespace graphics;

	Window window("Nezus", 940, 540);
	glClearColor(.3f, .2f, .5f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	while (!window.closed())
	{
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		std::cout << "x: " << x << "y: " << y << std::endl;
		if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "LEFT CLICK!" << std::endl;
		}
		if (window.isKeyPressed(GLFW_KEY_A))
		{
			std::cout << "Pressed!" << std::endl;
		}
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();

	}


	return 0;
}