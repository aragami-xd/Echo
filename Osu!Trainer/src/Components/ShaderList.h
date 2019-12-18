#pragma once
#include <Buffers/Shader.h>
#include <Engine/Attribute.h>

/* different shaders */
struct ShaderList
{
	Shader* BasicShader{ nullptr };
	Shader* CircleShader{ nullptr };

	~ShaderList()
	{
		if (BasicShader != nullptr) { delete BasicShader; }
		if (CircleShader != nullptr) { delete CircleShader; }
	}
};