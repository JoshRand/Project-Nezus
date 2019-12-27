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