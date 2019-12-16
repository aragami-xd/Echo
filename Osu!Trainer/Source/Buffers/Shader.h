#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader
{
private:
	// shader sources, id and uniform cache
	std::string vertexSource;
	std::string fragmentSource;
	unsigned int id;
	std::unordered_map<std::string, int> cache;

	// convert uniform name to uniform location
	int GetUniformLocation(const std::string& name);

	// parse, compile and assemble the shader
	std::string ParseShader(const std::string& path);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void Bind() const;
	void Unbind() const;

	// set the uniforms
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniform1i(const std::string& name, int v);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

	~Shader();
};