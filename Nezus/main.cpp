#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/math/math.h"
#include "src/utils/timer.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchrenderer2d.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
//_CRT_NONSTDC_NO_DEPRECATE
#include "src/graphics/layers/tilelayer.h"

#include "src/graphics/layers/group.h"
#include "src/graphics/texture.h"
#include "src/graphics/label.h"

#include "src/game/game.h"


#include <time.h>

#define BATCH_RENDERER 1

#define ENABLE_GAME 1

#if 1
int main()
{
	using namespace nezus;
	using namespace graphics;
	using namespace math;
	
	Window window("Nezus!", 960, 540);
	//glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f);

	Shader* s = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s;
	Shader* sg = new Shader("src/shaders/basic.vert", "src/shaders/basic2.frag");
	Shader& sgame = *sg;
	sgame.enable();
	sgame.setUniform2f("light_pos", vec2(7.0f, 1.5f));
	shader.enable();
	shader.setUniform2f("light_pos", vec2(1.0f, 1.5f));
	TileLayer layer(&shader);

	srand(time(NULL));

	
	Texture* textures[] =
	{
		new Texture("test.png"),
		new Texture("b.png"),
		new Texture("w.png")
	};
#if ENABLE_GAME
	Game game(&shader,&sgame, &window, textures[2]);
#endif
	
#if 0  
	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			if (rand() % 4 == 0)
			{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
			}
			else
			{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand() % 3]));
			}
		}
		
	}
#endif
	Group* g = new Group(math::mat4::translation(math::vec3(-15.8f, 7.0f, 0.0f)));

	Label* fps = new Label("", 0.4f,0.4f, math::vec4(1, 1, 1, 1));
	g->add(new Sprite(0, 0, 4.3f, 1.5f, math::vec4(0.2f, 0.2f, 0.2f, 0.8f)));
	g->add(fps);
	layer.add(g);
	Sprite* player = new Sprite(0, 0, 2, 2, math::vec4(1, 0, 1, 1));
	layer.add(player);
	GLint texIDs[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);

	sgame.enable();
	sgame.setUniform1iv("textures", texIDs, 10);

	shader.setUniformMat4("pr_matrix", math::mat4::orthographic(-16.0f,16.0f,-9.0f,9.0f,-1.0f,1.0f));
	sgame.setUniformMat4("pr_matrix", math::mat4::orthographic(-16.0f,16.0f,-9.0f,9.0f,-1.0f,1.0f));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	int initposx = 0;
	int initypos = 0;
	while (!window.closed())
	{ 

		window.clear();
		shader.enable();
		
		double x, y;
		window.getMousePosition(x, y);
#if !ENABLE_GAME
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / (float)window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / (float)window.getHeight())));// 540.0f)));
#endif	
		sgame.enable();
		layer.render();
		#if ENABLE_GAME
		game.update();
		game.draw();
		#endif

		window.update();

		//fps display
		
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{	
			std::cout << window.getWidth() << "= Width; " << window.getHeight() << " = Height." << std::endl;
			player->setPosition(initposx++, initypos);
			if (initposx > 15)
			{
				initypos++;
				initposx = 0;
			}
				
			//fps->position.x++;
			timer += 1.0f;
			fps->text = std::to_string(frames) + "fps";
			printf("%d fps\n", frames);
			
			frames = 0;
		}
	}
	for (int i = 0; i < 3; i++)
	{
	delete textures[i];
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