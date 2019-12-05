#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/* source files */
#include "Source/Engine/Core.h"
#include "Source/Buffers/VertexBuffer.h"
#include "Source/Buffers/IndexBuffer.h"
#include "Source/Buffers/VertexArray.h"

/* Shader parsing */
// strucure contains 2 shader sources
struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

// read file function
static ShaderSource ParseShader(const std::string& path)
{
	std::fstream file(path);

	if (!file)
		std::cout << "oof" << std::endl;

	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	ShaderType type = ShaderType::NONE;

	std::string line;
	std::stringstream ss[2];

	// while this is not the final line
	while (getline(file, line))
	{
		std::cout << line << std::endl;
		// std::string::npos means not found till the end of the array (or string)
		if (line.find("#shader") != std::string::npos)
		{
			// choose type based on the keyword
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else
		{
			// else add the line in as source code
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}


// create an new individual shader
static unsigned int CompiledShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);

	// get the very first character in the string (the c_str() function)
	const char* src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	// error handling: if there is an error in the source code
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	// if the shader didn't compiled sucessfully
	if (result == GL_FALSE)
	{
		// get the error message
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		// save the error message into char array
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);

		// display the message
		std::cout << "oof: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);

		delete[] message;
		return 0;
	}

	return id;
}

// create the program shader
static unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader)
{
	unsigned int program = glCreateProgram();

	unsigned int vs = CompiledShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompiledShader(GL_FRAGMENT_SHADER, fragmentShader);

	// attach the shader to the program, link them togther then validate them
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	// now as the shader has completed and become a part of the program, we should detach it from the program
	// we should be using the detach function, but we'll just delete it for now
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

// main program
int main(void)
{
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // use OpenGL core profile
	glfwSwapInterval(1);	// set fps limit to vsync

	/* main window and its size */
	GLFWwindow* window;
	int width = 1280;
	int height = 720;
	double ratio = height/double(width);

	/* frame time - the delay in between each frame in ms */
	int frameTime = 20;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// you can only call glewInit after MakeContextCurrent(), so glew will have a window to work with
	if (glewInit() != GLEW_OK)
		return -1;

	float position[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
	};

	unsigned int indeces[] = {
		0,1,2,
		2,3,0
	};

	// vertex array object, vertex buffer
	VertexArray va;
	VertexBufferLayout vbl;
	VertexBuffer vb(position, sizeof(position));
	vbl.Push<float>(2);
	va.AddBuffer(vb, vbl);

	IndexBuffer ib(indeces, 6);

	// new shader source code
	ShaderSource shaderSource = ParseShader("Resources/Shaders/Basic.shader");
	std::string vertexShader = shaderSource.VertexSource;
	std::string fragmentShader = shaderSource.FragmentSource;

	//// create the shader based on that source code and use it
	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	// bound the location to the variable in the shader file
	int location = glGetUniformLocation(shader, "u_Color");

	// the core
	Core core(window);
	core.MapInit("Library/Beatmaps/map.txt");

	// new color
	float red = 0.2f;
	float inc = 0.01f;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// bind the vao
		va.Bind();

		// dump the data into the uniform
		glUniform4f(location, red, 0.2f, 0.8f, 1.0f);

		// draw the rectangle using drawElements
		glDrawElements(GL_LINE_LOOP, 6, GL_UNSIGNED_INT, nullptr);

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

		/* sleep for "frameTime" ms */
		Sleep(frameTime);
	}

	glDeleteProgram(shader);
	glDisableVertexAttribArray(0);

	glfwTerminate();
	return 0;
}