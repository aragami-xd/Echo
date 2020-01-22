#pragma once

#include <EchoHeader.h>
#include <glad/glad.h>

#include <Echo/buffers/Shader.h>

namespace Echo
{
	class ShaderList
	{
		using Shaders = std::unordered_map<std::string, Shader*>;
	private:
		Shaders shaderList;
	public:
		inline void Push(const std::string& name, Shader* shader)
		{
			shaderList.insert({ name, shader });
		}
		inline void Pop(const std::string& name)
		{
			delete shaderList[name];
			shaderList.erase(name);
		}

		inline Shader* At(const std::string& name)
		{
			return shaderList[name];
		}

		inline void Bind(const std::string& name)
		{
			shaderList[name]->Bind();
		}
		inline void Unbind(const std::string& name)
		{
			shaderList[name]->Unbind();
		}

		inline Shaders::iterator begin() { return shaderList.begin(); }
		inline Shaders::iterator end() { return shaderList.end(); }
	};
}