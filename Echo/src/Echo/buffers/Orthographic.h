#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"

#include <Core.h>

class ECHO_DLL Orthographic
{
public:
	static void SetViewMatrix(Shader* shader, float x, float y);
	static void SetScaleMatrix(Shader* shader, float x, float y);
};