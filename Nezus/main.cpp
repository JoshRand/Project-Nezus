#include "src/graphics/window.h"
#include "src/math/math.h"

int main()
{
	using namespace nezus;
	using namespace graphics;
	using namespace math;

	Window window("Nezus", 940, 540);
	glClearColor(.3f, .2f, .5f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	
	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	vec4 c = a * b;
	
	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();

	position.elements[12] = 2.0f;

	vec4 column = position.columns[3];
	std::cout << column << std::endl;
	while (!window.closed())
	{
	
		window.clear();
		//std::cout << c << std::endl;
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