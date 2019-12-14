/* source files */
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Engine/Attribute.h"
#include "../Buffers/Renderer.h"
#include "../Buffers/Texture.h"
#include "Core.h"

using namespace std;

// main program
int main(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use OpenGL core profile
	glfwWindowHint(GLFW_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_VERSION_MINOR, 6);

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
		-0.5f, -0.5f, //0.0f, 0.0f,
		 0.5f, -0.5f, //1.0f, 0.0f,
		 0.5f,  0.5f, //1.0f, 1.0f,
		-0.5f,  0.5f, //0.0f, 1.0f
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	// vertex array object, vertex buffer
	VertexArray va;
	VertexBuffer vb(&position, sizeof(position));

	VertexBufferObject vbo;
	vbo.Push<float>(2);
	va.AddBuffer(vb, vbo);

	IndexBuffer ib(indices, 6);

	// new shader source code
	Shader shader("Osu!Trainer/Source/Shaders/Shader.vert", "Osu!Trainer/Source/Shaders/Shader.frag");
	shader.Bind();

	Object::SetMetadata(9.0f, 4.0f, 9.0f);
	Circle circle(0.0f, 0.0f, 0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window, true);

		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */

		// shader.SetUniform4f("uColor", red, 0.2f, 0.8f, 1.0f);
		// Renderer::Draw(va, ib, shader);

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