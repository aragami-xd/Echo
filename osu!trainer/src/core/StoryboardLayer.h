#pragma once
#include <Echo.h>

class StoryboardLayer : public Layer
{
private:
	Texture* background;
	VertexBuffer* vb;
	VertexLayout* vl;
	VertexArray* va;

	ShaderList* shaders;

	void TapFlashing(KeyDownEvent& e);
public:
	StoryboardLayer();

	virtual void Update() override;
	virtual void OnEvent(Event& e) override;

	~StoryboardLayer();
};