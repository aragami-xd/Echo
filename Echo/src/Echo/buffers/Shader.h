#pragma once

#include <EchoHeader.h>
#include <Core.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

class ECHO_DLL Shader
{
private:
	// shader sources, id and uniform cache
	unsigned int program;
	std::unordered_map<std::string, int> uniform;

	// parse, compile and assemble the shader
	std::string ParseShader(const std::string& path);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

	// find the uniform
	int GetUniform(const std::string& name);
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void Bind();
	void Unbind();

	// set uniform
	void SetShaderUniform1i(const std::string& name, int v);
	void SetShaderUniform1f(const std::string& name, float v);
	void SetShaderUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetShaderUniformMat4f(const std::string& name, const glm::mat4& mat);
	void SetShaderUniformVec4f(const std::string& name, const glm::vec4& vec);

	~Shader();
};