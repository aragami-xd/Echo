#pragma once

#include <vector>
#include <GL/glew.h>

struct VertexBufferElement
{
	unsigned int Type;
	unsigned int Count;
	unsigned char Normalized;

	static int GetSizeOfType(unsigned int type)
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
	template<typename T> void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<> void Push<float>(unsigned int count)
	{
		elements.push_back({ GL_FLOAT, count, false });
		stride += count * sizeof(GL_FLOAT);
	}

	template<> void Push<unsigned int>(unsigned int count)
	{
		elements.push_back({ GL_UNSIGNED_INT, count, false });
		stride += count * sizeof(GL_UNSIGNED_INT);
	}

	template<> void Push<unsigned char>(unsigned int count)
	{
		elements.push_back({ GL_UNSIGNED_BYTE, count, false });
		stride += count * sizeof(GL_UNSIGNED_BYTE);
	}

	inline std::vector<VertexBufferElement> GetElement() { return elements; }
	inline unsigned int GetStride() { return stride; }
};