#pragma once

#include <EchoGenHeader.h>
#include <EchoGenCore.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace EchoGen
{
	class ECHO_GEN_DLL Pattern
	{
	private:
		std::vector<glm::vec4> vertices;
		float refDist;							// reference distance between the first 2 vertices
	public:
		Pattern(const std::string& path);

		inline std::vector<glm::vec4> GetVertices() { return vertices; }
		inline float GetRefDist() { return refDist; }
	};
}