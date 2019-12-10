#pragma once

class IndexBuffer
{
private:
	unsigned int vertexID;
	unsigned int count;
public:
	IndexBuffer(unsigned int* data, unsigned int indexCount);

	void Bind() const;
	void Unbind() const;
	inline unsigned int GetCount() const { return count; }

	~IndexBuffer();
};