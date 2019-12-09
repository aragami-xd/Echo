#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

/* Error handling */
// a macro that automatically creates a breakpoint and stop the debugger if there is an error
// use it so we don't have to call GLClearError() and GLGetError() every time there is a function
#define GLCall(x)\
	GLClearError();\
	x;\
	if (!GLGetError(#x, __FILE__, __LINE__)) __debugbreak();\

// we clear all the error to make sure we don't have error from any other functions
void GLClearError();

// display all the errors onto the console
bool GLGetError(const char* func, const char* file, int line);

// renderer class
class Renderer
{
public:
	void Clear();
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};