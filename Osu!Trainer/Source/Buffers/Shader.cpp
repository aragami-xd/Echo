#include "Shader.h"
#include "Macro.h"
#include <GL/glew.h>

#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Shader::Shader(const string& vertexPath, const string& fragmentPath) :
	vertexSource(vertexPath), fragmentSource(fragmentPath), id(0)
{
	// create the shader
	id = CreateShader(ParseShader(vertexPath), ParseShader(fragmentPath));
}

string Shader::ParseShader(const string& path)
{
	// open the file
	ifstream source(path);
	if (!source)
	{
		cout << "cannot open shader file" << endl;
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

	GLCall(glShaderSource(shaderID, 1, &src, nullptr));
	GLCall(glCompileShader(shaderID));

	int result;
	GLCall(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result));

	// handling compilation error by printing out the message
	if (result == GL_FALSE)
	{
		int length;
		GLCall(glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length));

		char* message = new char[length];
		GLCall(glGetShaderInfoLog(shaderID, length, &length, message));

		cout << (type == GL_VERTEX_SHADER ? "vertex: " : "fragment: ") << message << endl;
		GLCall(glDeleteShader(shaderID));

		delete[] message;
		return 0;
	}

	return shaderID;
}

unsigned int Shader::CreateShader(const string& vertex, const string& fragment)
{
	cout << "[vertex shader]\n" << vertex << "\n\n[fragment shader]\n" << fragment << "\n" << endl;

	// create the program and call the compile function to compile and attach the 2 shaders
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment);

	GLCall(glAttachShader(program, vs));
	GLCall(glAttachShader(program, fs));
	GLCall(glLinkProgram(program));
	GLCall(glValidateProgram(program));

	GLCall(glDeleteShader(vs));
	GLCall(glDeleteShader(fs));

	return program;
}

int Shader::GetUniformLocation(const string& name)
{
	// if uniform is already in the cache
	if (cache.count(name) > 0)
		return cache[name];

	// get the location and print a warning if shader is not found
	int location = glGetUniformLocation(id, name.c_str());
	if (location == -1)
		cout << "uniform " << name << " not found" << endl;

	cache.insert({ name, location });
	return location;
}

void Shader::SetUniform4f(const string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniform1i(const string& name, int v)
{
	GLCall(glUniform1i(GetUniformLocation(name), v));
}

void Shader::Bind() const
{
	GLCall(glUseProgram(id));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(id));
}