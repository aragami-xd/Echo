#pragma once

#include <Echo.h>
#include <components/BezierSliderRenderElement.h>

class GameplayLayer : public Layer
{
private:
	// shaders
	ShaderList* shaders;

	// parser
	Parser* parser;

	// scoring
	Scoring* scoring;

	// object component vector
	std::vector<ObjectComponent*> object;
	int objectIterate = 0;

	/* event functions */
	float mouseX, mouseY;
	bool keyDown = false;

	// functions
	void Tapping(KeyDownEvent& e);
	void Release(KeyUpEvent& e);
	void MouseMove(MouseMoveEvent& e);

	BezierSliderRenderElement* slider;
public:
	GameplayLayer();

	virtual void Update() override;
	virtual void OnEvent(Event& e) override;

	~GameplayLayer();
};