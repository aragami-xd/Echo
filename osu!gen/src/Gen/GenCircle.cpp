#include "GenCircle.h"

void OsuGen::GenCircle::Gen(EchoGen::PatternList* pattern, std::vector<int>& beat, int& index, std::ofstream& map)
{
	// random a distance
	dist = 900 * ((rand() % 10) / (float)100 + 0.1);

	// choose a random pattern
	patternIndex = rand() % pattern->Size();
	vertices = pattern->At(patternIndex)->GetVertices();
	refDist = pattern->At(patternIndex)->GetRefDist();

	// scaling the vertices
	float distScale = 100.0f/*dist / float(refDist)*/;
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i] = glm::scale(glm::mat4(1.0f), glm::vec3(distScale, distScale, 0.0f)) * vertices[i];
		std::cout << vertices[i].r << " " << vertices[i].g << std::endl;
	}
}