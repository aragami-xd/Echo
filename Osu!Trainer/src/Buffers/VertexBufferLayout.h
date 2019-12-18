#pragma once

#include <vector>
#include <GL/glew.h>

// essential elements of the vertex buffer object
struct VertexBufferElement
{
	unsigned int Type;
	unsigned int Count;
	unsigned char Normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:			return 4;
		case GL_UNSIGNED_INT:	return 4;
		case GL_UNSIGNED_BYTE:	return 1;
		default:				return 0;
		}
	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> elements;
	unsigned int stride{ 0 };

public:
	// pushing a new element list to the vbl. a data type is required
	template<typename T> void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<> void Push<float>(unsigned int count)
	{
		elements.push_back({ GL_FLOAT, count, GL_FALSE });
		stride += count * sizeof(GLfloat);
	}

	template<> void Push<unsigned int>(unsigned int count)
	{
		elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		stride += count * sizeof(GLuint);
	}

	template<> void Push<unsigned char>(unsigned int count)
	{
		elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		stride += count * sizeof(GLubyte);
	}

	// get functions
	inline std::vector<VertexBufferElement> GetElement() const& {
		return elements;
	}
	inline unsigned int GetStride() const {
		return stride;
	}
};