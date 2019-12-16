/* source files */
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
	glEnable(GL_BLEND);

	// new color
	float red = 0.2f;
	float inc = 0.01f;

	float position[] = {
		-50.5f, -50.5f, 0.0f, 0.0f,
		 50.5f, -50.5f, 1.0f, 0.0f,
		 50.5f,  50.5f, 1.0f, 1.0f,
		-50.5f,  50.5f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0,1,2,
		2,3,0
	};

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// vertex array object, vertex buffer
	VertexArray va;
	VertexBuffer vb(&position, sizeof(position));

	VertexBufferLayout vbl;
	vbl.Push<float>(2);
	vbl.Push<float>(2);
	va.AddBuffer(vb, vbl);

	IndexBuffer ib(indices, 6);

	// projection matrix with 4x3 aspect ratio
	glm::mat4 proj = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0), glm::vec3(80, 0, 0));
	glm::mat4 model = glm::translate(glm::mat4(1.0), glm::vec3(0, 0, 0));

	glm::mat4 mvp = proj * view * model;

	// new shader source code
	Shader shader(::VertexPath, ::FragmentPath);
	shader.Bind();
	shader.SetUniform4f("uColor", red, 0.2f, 0.8f, 1.0f);
	shader.SetUniformMat4f("u_mvp", mvp);

	Texture texture("Osu!Trainer/Library/Textures/cursor.png");
	texture.Bind(0);
	shader.SetUniform1i("vTexture", 0);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window, true);

		glClear(GL_COLOR_BUFFER_BIT);

		/* Render here */
		shader.SetUniform4f("uColor", red, 0.2f, 0.8f, 1.0f);
		Renderer::Draw(va, ib, shader, GL_TRIANGLES);

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