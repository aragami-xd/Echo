#include "CircleComponent.h"
#include <Echo/buffers/Renderer.h>
#include <Echo/buffers/Orthographic.h>
using namespace std;

void CircleComponent::Render(ShaderList* shaders)
{
	// bind the shader
	//shaders->Bind("basic");
	//shaders->At("basic")->SetShaderUniform4f("uColor", 1.0f, 1.0f, 1.0f, 1.0f);

	//// render the circle
	//Orthographic::SetScaleMatrix(shaders->At("basic"), 100, 100);
	//Orthographic::SetViewMatrix(shaders->At("basic"), object->GetX(), object->GetY());

	Renderer::Render(
		element["circle"]->GetVertexArray(),
		settings["circle"]["vertices"],
		GL_LINE_LOOP
	);
}
