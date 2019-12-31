#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Settings.h>

#include "Shader.h"

class Orthographic
{
public:
	static void SetViewMatrix(Shader* shader, float x, float y);
};