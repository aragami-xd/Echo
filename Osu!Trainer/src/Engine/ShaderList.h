#pragma once
#include <Buffers/Shader.h>
#include <Engine/Attribute.h>

#include <unordered_map>
#include <string>

class ShaderList
{
private:
	std::unordered_map<std::string, Shader*> shader;
public:
	// add shader directly into the map
	inline void AddShader(const std::string& name, Shader* newShader)
	{
		shader.insert({ name, newShader });
	}

	// create a new shader by path and add into the map
	inline void AddShader(const std::string& name, const std::string& vertex, const std::string& fragment)
	{
		shader.insert({ name, new Shader(vertex, fragment) });
	}

	// return a shader pointer, return "nothing"(?) if not found
	inline Shader* GetShader(const std::string& name)
	{
		return shader.at(name);
	}

	// bind a shader in the list
	inline void BindShader(const std::string& name)
	{
		shader.at(name)->Bind();
	}

	// delete a shader 
	inline void RemoveShader(const std::string& name)
	{
		delete shader.at(name);
		shader.erase(name);
	}

	// delete all shader upon destruction
	~ShaderList()
	{
		//for (auto x : shader)
			//delete x.second;
	}
};