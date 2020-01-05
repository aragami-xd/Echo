#include "Shader.h"
using namespace std;

Shader::Shader(const string& vertexPath, const string& fragmentPath) :
	program(0)
{
	LOG_init("new shader");

	// compile 2 shaders then link them together
	program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexPath);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentPath);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	// unbind the shader for safety reason
	glUseProgram(0);
}

string Shader::ParseShader(const string& path)
{
	// parse the shader source code file into const char*
	ifstream file(path);
	if (!file)
	{
		LOG_warning("cannot open shader");
		return "";
	}
	stringstream ss;
	ss << file.rdbuf();

	file.close();
	return ss.str();
}

unsigned int Shader::CompileShader(unsigned int type, const string& path)
{
	// parse the shader
	unsigned int shader = glCreateShader(type);
	const char* shaderSource = ParseShader(path).c_str();

	LOG_message(shaderSource);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	// verify the shader
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char message[512];
		glGetShaderInfoLog(shader, 512, NULL, message);
		LOG_warning(message);
		glDeleteShader(shader);
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

int Shader::GetUniform(const string& name)
{
	// find the uniform in the cache
	if (uniform.count(name) > 0)
		return uniform[name];

	// if not found, look for it
	int location = glGetUniformLocation(program, name.c_str());
	if (location == -1)
		LOG_warning("uniform not found");

	// insert uniform into cache regardless of found or not
	uniform.insert({ name, location });
	return location;
}

void Shader::SetShaderUniform1i(const string& name, int v)
{
	glUniform1i(GetUniform(name), v);
}

void Shader::SetShaderUniform1f(const string& name, float v)
{
	glUniform1f(GetUniform(name), v);
}

void Shader::SetShaderUniform4f(const string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetUniform(name), v0, v1, v2, v3);
}

void Shader::SetShaderUniformMat4f(const string& name, const glm::mat4& mat)
{
	glUniformMatrix4fv(GetUniform(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetShaderUniformVec4f(const string& name, const glm::vec4& vec)
{
	glUniform4f(GetUniform(name), vec.r, vec.g, vec.b, vec.a);
}

Shader::~Shader()
{
	glDeleteProgram(program);
}