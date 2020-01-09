#include "StoryboardLayer.h"
using namespace std;

StoryboardLayer::StoryboardLayer() :
	Layer("Storyboard layer")
{
	// new background texture
	background = new Texture(settings["path"]["backgroundPath"]);
	va = new VertexArray;

	float position[32] = {
		 1.0f,  1.0f,  1.0f,  1.0f,		// position and texture coordinates
		 1.0f, -1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,  1.0f
		//0.0f, 0.0f, 0.0f, 0.0f,
		//0.0f, 900.0f, 0.0f, 900.0f,
		//1600.0f, 900.0f, 1600.0f, 900.0f,
		//1600.0f, 0.0f, 1600.0f, 0.0f
	};
	vb = new VertexBuffer(position, 32);

	vl = new VertexLayout();
	vl->Push<float>(2);
	vl->Push<float>(2);
	va->AddBuffer(*vl, *vb);

	// new shader
	shaders = new ShaderList();
	shaders->Push("texture", new Shader(settings["shader"]["textureVertex"], settings["shader"]["textureFragment"]));
}

void StoryboardLayer::TapFlashing(KeyDownEvent& e)
{
}

void StoryboardLayer::Update()
{
	Renderer::Render(va, 32);
}

void StoryboardLayer::OnEvent(Event& e)
{
	EventInvoker invoker(e);
	invoker.Invoke<KeyDownEvent>(EVENT_FUNC(StoryboardLayer::TapFlashing));
}

StoryboardLayer::~StoryboardLayer()
{
	delete background;
	delete vb;
	delete vl;
	delete va;

	for (auto shader : *shaders)
		delete shader.second;
	delete shaders;
}
