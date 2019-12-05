#include "Renderer.h"
#include <iostream>

// clear all the errors
void GLClearError()
{
	// while there are still errors in the program
	while (glGetError() != GL_NO_ERROR);	// can also do: while (!glGetError())
}

// display all the errors onto the console
bool GLGetError(const char* func, const char* file, int line)
{
	if (GLenum error = glGetError())
	{
		std::cout << "[error]: " << error << " " << func << " " << file << "::" << line << std::endl;
		return false;
	}

	return true;
}