#pragma once

#include <EchoHeader.h>
#include <Core.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ECHO_DLL Pattern
{
private:
	std::vector<glm::vec2> vertices;
public:
	Pattern(const std::string& path);
	
	inline std::vector<glm::vec2> GetVertices() { return vertices; }
};