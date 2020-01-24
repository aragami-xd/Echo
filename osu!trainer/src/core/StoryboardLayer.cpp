#include "StoryboardLayer.h"
#include <OsuSettings.h>

OsuTrainer::StoryboardLayer::StoryboardLayer() :
	Layer("Storyboard layer")
{
	// new background texture
	background = new Echo::Texture(OsuTrainer::settings["path"]["backgroundPath"]);
	va = new Echo::VertexArray;

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
	vb = new Echo::VertexBuffer(position, 32);

	vl = new Echo::VertexLayout();
	vl->Push<float>(2);
	vl->Push<float>(2);
	va->AddBuffer(*vl, *vb);

	// new shader
	shaders = new Echo::ShaderList();
	shaders->Push("texture", new Echo::Shader(OsuTrainer::settings["shader"]["textureVertex"], OsuTrainer::settings["shader"]["textureFragment"]));
}

void OsuTrainer::StoryboardLayer::TapFlashing(Echo::KeyDownEvent& e)
{
}

void OsuTrainer::StoryboardLayer::Update()
{
	Echo::Renderer::Render(va, 32);
}

void OsuTrainer::StoryboardLayer::OnEvent(Echo::Event& e)
{
	Echo::EventInvoker invoker(e);
	invoker.Invoke<Echo::KeyDownEvent>(EVENT_FUNC(OsuTrainer::StoryboardLayer::TapFlashing));
}

OsuTrainer::StoryboardLayer::~StoryboardLayer()
{
	delete background;
	delete vb;
	delete vl;
	delete va;

	for (auto shader : *shaders)
		delete shader.second;
	delete shaders;
}