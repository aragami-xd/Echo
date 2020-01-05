#include "CircleRenderElement.h"
#include <Settings.h>
using namespace std;

#define PI 3.14

/* note that the circle render element has nothing to do with circle object
	* this element is only use to depict anything rounded on the screen
	* components like slider can include circle render element
*/

CircleRenderElement::CircleRenderElement(float circleRadius, float circleThickness, glm::vec4 circleColor) :
	RenderElement(circleColor)
{
	// caculate the vertices coordinate
	float innerRadius = circleRadius - circleThickness;
	for (double i = 0; i < 2 * PI; i += 2 * PI / settings["circle"]["vertices"]) {
		vertices.push_back(cos(i) * circleRadius);
		vertices.push_back(sin(i) * circleRadius);
	}
	vertices.insert(vertices.end(), { circleRadius, 0.0f });

	// create buffers
	vl = new VertexLayout();		// vl
	vb = new VertexBuffer(vertices.data(), vertices.size() * sizeof(float));	// vb
	va = new VertexArray();			// va
	vl->Push<float>(2);
	va->AddBuffer(*vl, *vb);
}