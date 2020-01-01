#pragma once

#include <EchoHeader.h>
#include <Core.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

class ECHO_DLL Shader
{
private:
	unsigned int program;

	// read in the shader source code
	std::string ParseShader(const std::string& path);

	// compile the shader
	unsigned int  CompileShader(unsigned int type, const std::string& path);

public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);

	void Bind();
	void Unbind();

	// set uniform
	void SetShaderUniform1i(std::string& name, int v);
	void SetShaderUniform1f(std::string& name, float v);
	void SetShaderUniform4f(std::string& name, float v0, float v1, float v2, float v3);
	void SetShaderUniformMat4f(std::string& name, const glm::mat4& mat);
	void SetShaderUniformVec4f(std::string& name, const glm::vec4& vec);

	~Shader();
};