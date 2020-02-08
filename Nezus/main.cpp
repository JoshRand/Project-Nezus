
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/game/game.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/utils/timer.h"
#include <Windows.h>
#include <time.h>
#include "src/graphics/texture.h"

#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers/group.h"

#include <FreeImage.h>
#define BATCH_RENDERER 1
#define TEST_50K_SPRITES 0
#define ENABLE_GAME 0

#if 1
int main()
{
	using namespace nezus;
	using namespace graphics;
	using namespace math;
	
	Window window("Nezus!", 960, 540);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* s2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	
	TileLayer layer(&shader);
#if ENABLE_GAME
	Game game(shader,window);
#endif

	srand(time(NULL));
#if TEST_50K_SPRITES
	for (float y = -9.0f; y < 9.0f; y += .1)
	{
		for (float x = -16.0f; x < 16.0f; x += .1)
		{

			layer.add(new Sprite(x, y, 0.09f, 0.09f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
#else
	mat4 transform = mat4::rotation(45.0f, vec3(0, 0, 1));

	Group* group = new Group(mat4::translation(math::vec3(-15.0f,5.0f,0.0f)));
	
	group->add(new Sprite(0, 0, 6, 3, math::vec4(1, 1, 1, 1)));

	Group* button = new Group(mat4::translation(math::vec3(0.5f, 0.5f, 0.0f)));
	button->add(new Sprite(0.0f, 0.0f, 5.0f, 2.0, math::vec4(1, 0, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 3.0f, 1.0, math::vec4(0.2f, 0.3f, 0.8f, 1)));
	group->add(button);

	layer.add(group);
	
#endif
	//layer.add(new Sprite(0, 0, 2, 2, math::vec4(0.8f, 0.2f, 0.8f, 1.0f)));

	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, math::vec4(1, 0, 1, 1)));
	//shader.setUniformMat4("pr_matrix", ortho);
	glActiveTexture(GL_TEXTURE0);
	Texture texture("test.png");
	texture.bind();
	shader.enable();
	shader.setUniform1i("tex", 0);
	shader.setUniformMat4("pr_matrix", math::mat4::orthographic(-16.0f,16.0f,-9.0f,9.0f,-1.0f,1.0f));



	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		shader.enable();
		/*double x, y;
		window.getMousePosition(x, y);
		shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f /(float)window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / (float)window.getHeight() )));// 540.0f)));
		*/
		//shader.setUniform2f("light_pos", vec2(-8,-3));

		//shader2.enable();
		//layer.render();


		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex2f(0, 0);
		glTexCoord2f(0, 1);
		glVertex2f(0, 4);
		glTexCoord2f(1, 1);
		glVertex2f(4, 4);
		glTexCoord2f(1, 0);
		glVertex2f(4, 0);
		
		glEnd();


#if ENABLE_GAME
		game.update();
		game.draw();
#endif



		
		//layer2.render();
		//fps display
		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}
	
	return 0;
}
#endif
#if 0
int main()
{
	const char* filename = "test.png";
	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP* dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;

	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;

	std::cout << width << ", " << height << std::endl;


	for (int i = 0; i < width * height *4; i+=4)
	{
		std::cout << (int)bits[i] << " " << (int)bits[i+1] << " " << (int)bits[i+2]<< std::endl;
	}


	//return success
	return true;



	return 0;
}
#endif