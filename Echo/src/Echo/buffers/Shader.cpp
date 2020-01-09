#include "Shader.h"
using namespace std;

Shader::Shader(const string& vertexPath, const string& fragmentPath) :
	program(0)
{
	// create the shader
	program = CreateShader(ParseShader(vertexPath), ParseShader(fragmentPath));
}

string Shader::ParseShader(const string& path)
{
	// open the file
	ifstream source(path);
	if (!source)
	{
		LOG_warning("cannot open shader file");
		return "";
	}

	stringstream ss;
	ss << source.rdbuf();

	return ss.str();
}

unsigned int Shader::CompileShader(unsigned int type, const string& source)
{
	// get the shader type to compile it
	unsigned int shaderID = glCreateShader(type);
	const char* src = source.c_str();

	glShaderSource(shaderID, 1, &src, nullptr);
	glCompileShader(shaderID);

	int result;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

	// handling compilation error by printing out the message
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);

		char* message = new char[length];
		glGetShaderInfoLog(shaderID, length, &length, message);

		LOG_warning((type == GL_VERTEX_SHADER ? "vertex error" : "fragment error"));
		LOG_warning(message);

		glDeleteShader(shaderID);

		delete[] message;
		return 0;
	}

	return shaderID;
}

unsigned int Shader::CreateShader(const string& vertex, const string& fragment)
{
	LOG_message("[vertex shader]\n" + vertex + "\n[fragment shader]\n" + fragment);

	// create the program and call the compile function to compile and attach the 2 shaders
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
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