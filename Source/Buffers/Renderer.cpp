#include "Renderer.h"
#include <iostream>

using namespace std;

/* error handling functions */
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
		cout << "[error]: " << error << " " << func << " " << file << "::" << line << endl;
		return false;
	}
	return true;
}

/* renderer functions */
// clear function
void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

// draw function
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	ib.Bind();
	va.Bind();
	shader.Bind();

	glDrawElements(GL_LINE_LOOP, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}