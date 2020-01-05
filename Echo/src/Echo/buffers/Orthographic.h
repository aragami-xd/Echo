#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"

#include <Core.h>

struct ECHO_DLL Orthographic
{
	static void SetViewMatrix(Shader* shader, glm::mat4 matrix);
	static void SetProjMatrix(Shader* shader, glm::mat4 matrix);
};