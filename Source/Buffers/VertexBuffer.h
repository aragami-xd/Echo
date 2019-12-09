#pragma once

class VertexBuffer
{
private:
	unsigned int vertexID;
public:
	VertexBuffer(const void* data, unsigned int size);

	void Update(const void* data, unsigned int size);
	void Bind() const;
	void Unbind() const;

	~VertexBuffer();
};
