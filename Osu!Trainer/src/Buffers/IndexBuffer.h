#pragma once
#include <GL/glew.h>

class IndexBuffer
{
private:
	unsigned int vertexID;
	unsigned int count;
public:
	IndexBuffer(unsigned int* data, unsigned int indexCount, GLenum flag = GL_DYNAMIC_DRAW);

	void Bind() const;
	void Unbind() const;
	inline unsigned int GetCount() const { 
		return count; 
	}

	~IndexBuffer();
};