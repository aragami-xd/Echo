#include "Shader.h"
using namespace std;

Shader::Shader(const string& vertexPath, const string& fragmentPath) :
	program(0)
{
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

	// set default uniform values
	SetShaderUniformMat4f(string("model"), glm::mat4(1.0f));
	SetShaderUniformMat4f(string("view"), glm::mat4(1.0f));
	SetShaderUniformMat4f(string("proj"), glm::mat4(1.0f));

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