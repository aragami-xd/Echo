#pragma once

#include <GL/glew.h>
#include <iostream>

// a macro that automatically creates a breakpoint and stop the debugger if there is an error
// use it so we don't have to call GLClearError() and GLGetError() every time there is a function
#define GLCall(x)\
	GLClearError();\
	x;\
	if (!GLGetError(#x, __FILE__, __LINE__)) __debugbreak();\

inline void GLClearError()
{
	// while there are still errors in the program
	while (glGetError() != GL_NO_ERROR);	// can also do: while (!glGetError())
}

// display all the errors onto the console
inline bool GLGetError(const char* func, const char* file, int line)
{
	if (GLenum error = glGetError())
	{
		std::cout << "[error]: " << error << " " << func << " " << file << "::" << line << std::endl;

		return false;
	}
	return true;
}