#pragma once

#include <EchoHeader.h>
#include <glad/glad.h>

#include <Echo/buffers/Shader.h>

class ShaderList
{
	using Shaders = std::unordered_map<std::string, Shader*>;
private:
	Shaders shaderList;
public:
	inline void Push(std::string& name, Shader* shader)
	{
		shaderList.insert({ name, shader });
	}
	inline void Pop(std::string& name)
	{
		delete shaderList[name];
		shaderList.erase(name);
	}

	inline Shader* operator[](std::string& name)
	{
		return shaderList[name];
	}

	inline void Bind(std::string& name)
	{
		shaderList[name]->Bind();
	}
	inline void Unbind(std::string& name)
	{
		shaderList[name]->Unbind();
	}

	inline Shaders::iterator begin() { return shaderList.begin(); }
	inline Shaders::iterator end() { return shaderList.end(); }
};