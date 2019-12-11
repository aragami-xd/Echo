#pragma once

#include <string>
#include <unordered_map>

class Shader
{
private:
	std::string vertexSource;
	std::string fragmentSource;
	unsigned int id;
	std::unordered_map<std::string, int> cache;

	int GetUniformLocation(const std::string& name);

	std::string ParseShader(const std::string& path);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& name, int v);

	~Shader();
};