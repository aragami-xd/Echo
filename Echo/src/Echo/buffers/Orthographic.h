#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"

#include <Core.h>

namespace Echo
{
	class ECHO_DLL Orthographic
	{
	public:
		static void SetModelMatrix(Shader* shader, const glm::mat4& matrix);
		static void SetViewMatrix(Shader* shader, const glm::mat4& matrix);
		static void SetProjMatrix(Shader* shader, const glm::mat4& matrix);
	};
}