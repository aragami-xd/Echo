/* source files */
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Engine/Attribute.h"
#include "../Buffers/Renderer.h"
#include "../Buffers/Shader.h"
#include "../Buffers/Texture.h"
#include "../Buffers/IndexBuffer.h"

using namespace std;

// main program
int main(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use OpenGL core profile

	/* main window and its size */
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(::WindowWidth, ::WindowHeight, "OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	glfwSwapInterval(1);	// set fps limit to vsync

	// new color
	float red = 0.2f;
	float inc = 0.01f;

	float position[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	// vertex array object, vertex buffer
	VertexArray va;
	VertexBuffer vb(&position, sizeof(position));
	VertexBufferLayout vbl;

	vbl.Push<float>(2);
	vbl.Push<float>(2);
	va.AddBuffer(vb, vbl);
	va.Bind();
	vb.Bind();

	IndexBuffer ib(indices, 6);
	ib.Bind();

	// new shader source code
	Shader shader("Osu!Trainer/Source/Shaders/Vertex.shader", "Osu!Trainer/Source/Shaders/Fragment.shader");
	shader.Bind();

	// renderer class
	Renderer renderer;

	// texture class
	//Texture texture("Osu!Trainer/Library/Textures/thumb.png");
	//texture.Bind();
	//shader.SetUniform1i("vTexture", 0);	// the value and the texture buffer slot must be the same

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window, true);

		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */

		shader.SetUniform4f("uColor", red, 0.2f, 0.8f, 1.0f);
		renderer.Draw(va, ib, shader);

		// cycle through the color
		if (red > 1.0f)
			inc = -0.05f;
		else if (red < 0.0f)
			inc = 0.05f;
		red += inc;

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}