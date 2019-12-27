#include "Shader.h"
using namespace std;

Shader::Shader(string& vertexPath, string& fragmentPath) :
	program(0)
{
	// compile 2 shaders then link them together
	program = glCreateProgram();
	glAttachShader(program, CompileShader(true, vertexPath));
	glAttachShader(program, CompileShader(false, fragmentPath));
	glLinkProgram(program);

	// verify the shader program
	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		char message[512];
		glGetProgramInfoLog(program, 512, nullptr, message);
		LOG_warning(message);
	}

	// unbind the shader for safety reason
	glUseProgram(0);
}

const char* Shader::ParseShader(string& path)
{
	// parse the shader source code file into const char*
	ifstream file;
	try
	{
		file.open(path);
	}
	catch(ifstream::failure e)
	{
		LOG_message(e.what());
		return nullptr;
	}
	stringstream ss;
	ss << file.rdbuf();

	file.close();
	
	return ss.str().c_str();
}

unsigned int Shader::CompileShader(bool isVertex, string& path)
{
	// create and compile the shader
	GLenum type = (isVertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);

	unsigned int shader = glCreateShader(type);
	const char* shaderSource = ParseShader(path);
	glShaderSource(shader, 1, &shaderSource, nullptr);

	// verify the shader
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char message[512];
		glGetShaderInfoLog(shader, 512, nullptr, message);
		LOG_warning(message);
		return 0;
	}
	return shader;
}

void Shader::Bind()
{
	glUseProgram(program);
}

void Shader::Unbind()
{
	glUseProgram(0);
}

void Shader::SetShaderUniform1i(string& name, int v)
{
	glUniform1i(glGetUniformLocation(program, name.c_str()), v);
}

void Shader::SetShaderUniform1f(string& name, float v)
{
	glUniform1f(glGetUniformLocation(program, name.c_str()), v);
} 

void Shader::SetShaderUniform4f(string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(glGetUniformLocation(program, name.c_str()), v0, v1, v2, v3);
}

void Shader::SetShaderUniformMat4f(string& name, const glm::mat4& mat)
{
	glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetShaderUniformVec4f(std::string& name, const glm::vec4& vec)
{
	glUniform4f(glGetUniformLocation(program, name.c_str()), vec.r, vec.g, vec.b, vec.a);
}

Shader::~Shader()
{
	glDeleteProgram(program);
}
