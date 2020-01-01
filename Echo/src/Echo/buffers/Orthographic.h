#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"

class Orthographic
{
public:
	static void SetViewMatrix(Shader* shader, float x, float y);
	static void SetScaleMatrix(Shader* shader, float x, float y);
};