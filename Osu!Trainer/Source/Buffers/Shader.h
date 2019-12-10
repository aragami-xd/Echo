#pragma once

#include <string>
#include <unordered_map>

struct ShaderSource
{
	std::string Vertex;
	std::string Fragment;
};

class Shader
{
private:
	std::string file;
	unsigned int id;
	std::unordered_map<std::string, int> cache;

	int GetUniformLocation(const std::string& name);

	ShaderSource ParseShader(const std::string& path);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
public:
	Shader(const std::string& path);

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(std::string name, float v0, float v1, float v2, float v3);
	void SetUniform1i(std::string name, int v);

	~Shader();
};