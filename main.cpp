/* source files */
#include "Source/Components/Core.h"
#include "Source/Buffers/Renderer.h"
#include "Source/Engine/Attribute.h"

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
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
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
	va.AddBuffer(vb, vbl);

	IndexBuffer ib(indices, 6);

	// new shader source code
	Shader shader("Source/Shaders/Basic.shader");
	shader.Bind();

	// renderer class
	Renderer renderer;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renderer.Clear();

		shader.SetUniform4f("u_Color", red, 0.2f, 0.8f, 1.0f);
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